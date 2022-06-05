#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_location
{
	int	x;
	int	y;
	int	square;
}	t_location;

void	print_square(char **map, int size)
{
	int	i;
	int	x_size;

	i = 0;
	x_size = 0;
	while (map[0][x_size])
		x_size++;
	while (i < size)
	{
		write(1, map[i], x_size);
		write(1, "\n", 1);
		i++;
	}
}

void	change_map(t_location max, char fill_map, char **map)
{
	int	start_x;
	int	start_y;
	int	temp;

	start_x = max.x - max.square + 1;
	start_y = max.y - max.square + 1;
	temp = start_x;
	while (start_y <= max.y)
	{
		start_x = temp;
		while (start_x <= max.x)
		{
			map[start_y][start_x] = fill_map;
			start_x++;
		}
		start_y++;
	}
}

int	find_min(int **dp, int i, int j)
{
	int	a;
	int	b;
	int	c;
	int	n;

	a = dp[i][j - 1];
	b = dp[i - 1][j];
	c = dp[i - 1][j - 1];
	n = a;
	if (n > b)
		n = b;
	if (n > c)
		n = c;
	return (n);
}

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	**find_first_line(t_location map_size, char **map, char empty)
{
	int	i;
	int	**dp;
	int	limit;

	i = -1;
	limit = find_max(map_size.y, map_size.x);
	dp = (int **)malloc(sizeof(int *) * map_size.y);
	while (++i < map_size.y)
		dp[i] = (int *)malloc(sizeof(int) * map_size.x);
	i = -1;
	while (++i < limit)
	{
		if (i < map_size.y && map[i][0] == empty)
			dp[i][0] = 1;
		else if (i < map_size.y && map[i][0] != empty)
			dp[i][0] = 0;
		if (i < map_size.x && map[0][i] == empty)
			dp[0][i] = 1;
		else if (i < map_size.x && map[0][i] != empty)
			dp[0][i] = 0;
	}
	return (dp);
}

t_location	use_dp(t_location map_size, int **dp, char **map, char disable)
{
	int			i;
	int			j;
	t_location	max;

	i = 0;
	max.square = 0;
	while (++i < map_size.y)
	{
		j = 0;
		while (++j < map_size.x)
		{
			if (map[i][j] == disable)
				dp[i][j] = 0;
			else
				dp[i][j] = 1 + find_min(dp, i, j);
			if (max.square < dp[i][j])
			{
				max.square = dp[i][j];
				max.x = j;
				max.y = i;
			}
		}
	}
	return (max);
}

void	find_max_square(char **map, int y_size, char *sign)
{
	int	**dp;
	t_location	max;
	t_location	map_size;

	map_size.x = 0;
	map_size.y = y_size;
	max.square = 0;
	while (map[0][map_size.x])
		map_size.x++;
	dp = find_first_line(map_size, map, sign[0]);
	max =  use_dp(map_size, dp, map, sign[1]);
	change_map(max, sign[2], map);
}

char	**ft_malloc(int y, int x)   /*2차원 char형 배열 동적할당*/
{
	char	**set;
	int		i;

	set = (char **)malloc(sizeof(char *) * (y + 1));
	if (!set)
		return (0);
	i = -1;
	while (++i < y)
	{
		set[i] = (char *)malloc(sizeof(char *) * (x + 1));
		if (!set[i])
			return (0);
	}
	return (set);
}

void	add(int *size, char **s)       /*동적 할당 최신화*/
{
	int		i;
	char	*temp;
	int		new;

	i = 0;
	new = *size + 1;
	temp = (char *)malloc(sizeof(char) * new);
	if (!temp)
		return ;
	while (i < *size)
	{
		temp[i] = (*s)[i];
		i++;
	}
	*size = *size + 1;
	temp[i] = 0;
	free(*s);
	*s = temp;
}

int	same_check(char c, char *sign, int n)    /*첫 행의 문자와 같은 문자 오는지*/
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (sign[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*set_first(int size, char *sign, int *sum)    /*첫 행 정보 뽑기*/
{
	int		i;
	char	*word;

	word = (char *)malloc(sizeof(char) * 4);
	if (!word)
		return (0);
	i = -1;
	while (++i < 4)      /*빈, 장애물, 찬 문자 저장*/
	{
		word[i] = sign[size - 4 + i];
		if (same_check(word[i], word, i))
			return (0);
		sign[size - 4 + i] = 0;
	}
	i = 0;
	*sum = 0;
	while (sign[i])        /*세로 길이 저장*/
	{
		*sum = *sum * 10 + (sign[i] - '0');
		i++;
	}
	free(sign);
	sign = 0;
	return (word);
}

char	*input_first(int fd, int *sum)      /*첫 행 정보에서 문자, 숫자 저장*/
{
	char	*sign;
	char	*word;
	char	c;
	int		size;

	sign = (char *)malloc(sizeof(char));
	if (!sign)
		return (0);
	size = 1;
	c = 0;
	while (c != '\n')
	{
		read(fd, &c, 1);
		if (c != '\n')
		{
			sign[size - 1] = c;
			add(&size, &sign);
		}
	}
	if (size < 5)
		return (0);
	word = set_first(size, sign, sum);
	return (word);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*read_one(int fd, char *sign)
{
	char	*set;
	char	c;
	int		size;

	set = (char *)malloc(sizeof(char));
	if (!set)
		return (0);
	c = 0;
	size = 1;
	while (c != '\n')
	{
		read(fd, &c, 1);
		if (c != '\n')
		{
			if (!same_check(c, sign, 2))
				return (0);
			set[size - 1] = c;
			add(&size, &set);
		}
	}
	return (set);
}

char	**make_map(int fd, int sum, char *sign)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char*) * (sum + 1));
	if (!map)
		return (0);
	i = 0;
	while (i < sum)
	{
		map[i] = read_one(fd, sign);
		if (!map[i])
			return (0);
		i++;
	}
	map[i] = 0;
	i = 1;
	while (i < sum)
	{
		if (ft_strlen(map[i - 1]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (map);
}

void	memory_free(char *sign, char **map)
{
	int	i;

	i = 0;
	free(sign);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	input_data(int fd)
{
	int			sum;
	char		*sign;
	char		**map;

	sign = input_first(fd, &sum);
	if (!sign)
		return (0);
	map = make_map(fd, sum, sign);
	if (!map)
		return (0);
	find_max_square(map, sum, sign);
	print_square(map, sum);
	memory_free(sign, map);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	fd;
	int	i;

	fd = 0;
	if (argc < 2)
	{
		if (!input_data(fd))
			write(1, "map error\n", 10);
	}
	else if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (!input_data(fd))
				write(1, "map error\n", 10);
			close(fd);
			i++;
			if (i != argc)
				write(1, "\n", 1);
		}
	}
	return (0);
}
