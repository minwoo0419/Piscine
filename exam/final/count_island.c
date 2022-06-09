/*Assignment name  : count_island
Expected files   : *.c, *.h
Allowed functions: open, close, read, write, malloc, free
--------------------------------------------------------------------------------

동일한 길이의 행을 포함하는 파일을 받아들이는 프로그램을 작성하십시오.
이러한 문자열에는 '.' 또는 'X'. 이 모든 라인
함께 '.' 문자에서 직사각형을 형성합니다. "섬" 'X'를 포함합니다.
최대 줄 크기는 후행 줄 바꿈을 포함하여 1024자입니다.
열(열이 파일에서
동일한 수의 문자로 해당 줄을 시작합니다.
두 캐릭터가 인접해 있으면 서로 닿아 있다고 합니다.
동일한 행 또는 인접한 행 및 동일한 열에 있습니다.
"X"의 "Island"는 서로 접하는 "X"의 집합을 의미합니다.
프로그램은 파일을 살펴보고 모든 "X"를 바꾼 후 표시해야 합니다.
파일의 시작 부분부터 시작하여 파일에서 섬의 ​​위치에 해당하는 숫자입니다.
하나의 결과만 있을 수 있습니다.
파일이 비어 있거나 오류(예: 일관성 없는 입력)가 있거나 매개변수가
통과되지 않은 경우 프로그램은 새 행을 표시해야 합니다.
파일에는 10개 이하의 섬이 포함되어 있습니다.
주제별 디렉토리에서 예제를 찾을 수 있습니다.

$>cat johndoe
.................XXXXXXXX..........................................
....................XXXXXXXXX.......XXXXXXXX.......................
.................XXXXXXXX..............XXX...XXXXX.................
.....................XXXXXX.....X...XXXXXXXXXXX....................
................................X..................................
......XXXXXXXXXXXXX.............X..................................
..................X.............XXXXXXXXX..........................
..................X.........XXXXXXXXXXXX...........................
..................X................................................
XX.............................................................XXXX
XX..................XXXXXXXXXXXXX.................................X
...................................................................
.................................................................X.
.....................XXXXX.......................................XX
$>
$>./count_island johndoe
.................00000000..........................................
....................000000000.......11111111.......................
.................00000000..............111...11111.................
.....................000000.....2...11111111111....................
................................2..................................
......3333333333333.............2..................................
..................3.............222222222..........................
..................3.........222222222222...........................
..................3................................................
44.............................................................5555
44..................6666666666666.................................5
...................................................................
.................................................................7.
.....................88888.......................................77
$>

$>cat who-s-there
...................................................................
...X........X.....XXXXX......XXXXXXX...XXXXXXXXXX..XXXXXXXXXX......
...XX......XX....XX...XX....XX.....XX.....XXXX.....XXXXXXXXXX......
...XXXX..XXXX...XX.....XX...XX.....XX......XX......XX..............
...XX.XXXX.XX...XX.....XX...XX.....XX......XX......XX..............
...XX...X..XX...XX.....XX...XXXXXXXX.......XX......XXXXX...........
...XX......XX...XXXXXXXXX...XXXX...........XX......XXXXX...........
...XX......XX..XX.......XX..XX.XX..........XX......XX..............
...XX......XX..XX.......XX..XX...X.........XX......XX..............
...XX......XX..XX.......XX..XX....X......XXXXXX....XXXXXXXXXX......
...XX......XX.XX.........XX.XX.....XX..XXXXXXXXXX..XXXXXXXXXX..X...
...................................................................
$>
$>./count_island who-s-there
...................................................................
...0........0.....11111......2222222...3333333333..4444444444......
...00......00....11...11....22.....22.....3333.....4444444444......
...0000..0000...11.....11...22.....22......33......44..............
...00.0000.00...11.....11...22.....22......33......44..............
...00...0..00...11.....11...22222222.......33......44444...........
...00......00...111111111...2222...........33......44444...........
...00......00..11.......11..22.22..........33......44..............
...00......00..11.......11..22...5.........33......44..............
...00......00..11.......11..22....6......333333....4444444444......
...00......00.11.........11.22.....77..3333333333..4444444444..8...
...................................................................
$>

$>cat -e void
$>./count_island void | cat -e
$
$>
*/



#include <unistd.h>
#include <fcntl.h>

#define LIM 102400

void	flood_fill(char *map, int width, int pos, int size, char replace)
{
	if (pos < 0 || pos >= size || !map[pos] || map[pos] != 'X')
		return ;
	map[pos] = replace;
	flood_fill(map, width, pos + 1, size, replace);
	flood_fill(map, width, pos - 1, size, replace);
	flood_fill(map, width, pos - width, size, replace);      
	flood_fill(map, width, pos + width, size, replace);       


	flood_fill(map, width, pos + width + 1, size, replace);    
	flood_fill(map, width, pos + width - 1, size, replace);  
	flood_fill(map, width, pos - width + 1, size, replace);
	flood_fill(map, width, pos - width - 1, size, replace);
}

int		count_island(char *file)
{
	char	map[LIM] = {0};
	int		j;
	int		i;
	int		size;
	int		width;
	int		height;
	char	replacer;

	if (((j = open(file, O_RDONLY)) != -1) \
		&& ((size = read(j, map, LIM)) != -1))
	{

		width = 0;
		while (map[width++] != '\n');

		height = 0;
		i = -1;
		while (++i < size)
		{
			if (map[i] != '.' && map[i] != 'X' \
				&& map[i] != '\n' && map[i] != '\0')
				return (0);
			if (map[i] == '\n')
				height++;
		}

		if (height * width == size)
		{

			replacer = '0';
			i = -1;
			while (++i < height)
			{
				j = -1;
				while (++j < width)
				{
					if (map[(i * width) + j] == 'X')
						flood_fill(map, width, (i * width) + j, size, replacer++);
				}
			}


			if (replacer <= ('9' + 1))
				write(1, map, size - 1);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		count_island(*(av + 1));
	write(1, "\n", 1);
	return (0);
}



#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

void	ft_putmap(char **map)
{
	int y;

	y = -1;
	while (map[++y])
		ft_putstr(map[y]);
}

int		ft_size(char *file, char c)
{
	int		fd;
	char	buffer;
	int		size;
	int		r;

	size = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	else
	{
		while ((r = read(fd, &buffer, 1)))
		{
			if (r == -1)
				break;
			if (buffer == c)
				break;
			size++;
		}
		if (close(fd) == -1)
			return (0);
	}
	return (size);
}

char	**file_to_arr(char *file)
{
	char	**map;
	int		fd;
	int		size;
	int		width;
	int		height;
	int		y;
	int		x;

	map = (void *)0;
	if ((size = ft_size(file, '\0')) &&	(width = ft_size(file, '\n') + 1) \
		&& (map = (char **)malloc(sizeof(char **) * ((size/ width) + 1))))
{
		height = size / width;
		y = -1;
		while (++y < height)
		{
			if (!(map[y] = (char *)malloc(sizeof(char) * (width + 1))))
				return ((void *)0);
			map[y][width] = '\0';
		}
		if (((fd = open(file, O_RDONLY))) == -1)
			return ((void *)0);
		y = -1;
		while (++y < height)
		{
			x = -1;
			while (((read(fd, &map[y][++x], 1)) != -1))
			{
				if (map[y][x] == '\n')
				{
					map[y][x + 1] = '\0';
					break;
				}
			}
		}
		if (close(fd) == -1)
			return ((void *)0);
		map[y] = (void *)0;
	}
	return (map);
}

void	floodfill(char **map, int x, int y, char c)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x] || map[y][x] != 'X')
		return ;
	map[y][x] = c;
	floodfill(map, x + 1, y, c);
	floodfill(map, x - 1, y, c);
	floodfill(map, x, y + 1, c);
	floodfill(map, x, y - 1, c);
}

void	count_island(char *file)
{
	char	**map;
	int		y;
	int		x;
	char	replace;

	if ((map = file_to_arr(file)))
	{
		replace = '0';
		y = -1;
		while (map[++y])
		{
			x = -1;
			while (map[y][++x])
			{
				if (map[y][x] == 'X')
					floodfill(map, x, y, replace++);
			}
		}
		if (replace <= ('9' + 1))
			ft_putmap(map);
	}
	else
		ft_putstr("\n");
}

int		main(int ac, char **av)
{
	if (ac == 2)
		count_island(*(av + 1));
	return (0);
}

