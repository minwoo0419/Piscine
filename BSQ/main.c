#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct s_location
{
	int x;
	int y;
	int square;
}	t_location;

void	print_square(t_location point, char **map, int size, char fill_map)
{
	int	i;
	int	j;
	int start_x;
	int start_y;

	i = 0;
	start_x = point.x - point.square + 1;
	start_y = point.y - point.square + 1;
	while (i < size)
	{
		j = 0;
		while (map[i][j])
		{
			if (i >= start_y && i <= point.y && j >= start_x && j <= point.x)
				write(1, &fill_map, 1);
			else
				write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
int find_min(int a, int b, int c)
{
	int n;

	n = a;
	if (n > b)
		n = b;
	if (n > c)
		n = c;
	return (n);
}

struct s_location	find_max_square(char **map, char empty, int y_size, char disable)
{
	int	**dp;
	int	i; // 가로의 길이
	int	j; // 세로의 길이
	t_location	max;
	t_location	map_size;

	i = 0;
	j = 0;
	map_size.x = 0;
	map_size.y = y_size;
	max.square = 0;
	dp = (int **)malloc(sizeof(int *) * (y_size));
	while (map[0][map_size.x])
		map_size.x++;
	while (i < y_size)
		dp[i++] = (int *)malloc(sizeof(int) * map_size.x);
	while (j < map_size.x)
	{
		if (map[0][j] == empty)
			dp[0][j] = 1;
		else
			dp[0][j] = 0;
		j++;
	}
	j = -1;
	while (++j < map_size.y)
	{
		if (map[j][0] == empty)
			dp[j][0] = 1;
		else
			dp[j][0] = 0;
	}
	i = 0;
	while (++i < map_size.y)
	{
		j = 0;
		while (++j < map_size.x)
		{
			if (map[i][j] == disable)
				dp[i][j] = 0;
			else
				dp[i][j] = 1 + find_min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
			if (dp[i][j] > max.square)
			{
				max.square = dp[i][j];
				max.x = j;
				max.y = i;
			}
		}
	}
	return (max);
}

int	set_map(char ***map, char *s, int sum)
{
	int		len;
	int		i;
	int		j;
	int		k;
	char	**set;

	len = 1;
	set = (char **)malloc(sizeof(char*) * (sum + 1));
	while (s[len] != '\n')
		len++;
	i = 0;
	k = 1;
	while (i < sum && s[k])
	{
		set[i] = (char *)malloc(sizeof(char) * (len));
		j = 0;
		while (j < len - 1)
		{
			if (s[k] == '\n')
				return (0);
			set[i][j++] = s[k++];
		}
		set[i][j] = 0;
		if (s[k] != '\n')
			return (0);
		k++;
		i++;
	}
	set[i] = 0;
	*map = set;
	return (1);
}

void add(int* size, char** s)
{
	int		i;
	int		newsize;
	char	*temp;
	
	i = 0;
	newsize = *size + 1;
	temp = (char *)malloc(sizeof(char) * newsize);
	if (!temp)
		return ;
	while (i < *size)
	{
		temp[i] = (*s)[i];
		i++;
	}
	temp[i] = 0;
	free(*s);
	*s = temp;
	*size = *size + 1;;
}

void	print_error(int *fd)
{
	if (*fd == 0)
	{
		write(1, "map error\n", 10);
		exit(1);
	}
	else if (*fd == 1)
	{
		write(1, "map error\n", 10);
		close(*fd);
	}
}

int	same_check(char c, char *sign, int n)
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

int	main(int argc, char *argv[])
{
	int		fd = 0;
	int		i;
	int		j;
	char	c;
	int		sum;
	char	*sign;
	char	*put;
	char	**map;
	int		size;

	sum = 0;
	c = '0';
	i = 0;
	if (argc < 2) //fd == 0일때
	{
		sign = (char*)malloc(sizeof(char) * 4);
		if (!sign)
			print_error(&fd);
		while (c >= '0' && c <= '9')
		{
			read(fd, &c, 1);
			if (c >= '0' && c <= '9')
				sum = sum * 10 + (c - '0');
			else
				sign[i++] = c;
		}
		if (!sum)
			print_error(&fd);
		while (sign[i] != '\n' && i < 3)
		{
			read(fd, &sign[i], 1);
			if (same_check(sign[i], sign, i))
				print_error(&fd);
			i++;
		}
		sign[i] = 0;
		if (i != 3)
			print_error(&fd);
		size = 1;
		put = (char *)malloc(sizeof(char) * size);
		i = 0;
		j = 0;
		while (i < sum + 1)
		{
			read(fd, &put[j], 1);
			if (put[j] == '\n')
				i++;
			else if (!same_check(put[j], sign, 3))
				print_error(&fd);
			add(&size, &put);
			j++;
		}
		if (!set_map(&map, put, sum))
			print_error(&fd);
		t_location max = find_max_square(map, sign[0], sum, sign[1]);
		printf("\n\n");
		print_square(max, map, sum, sign[2]);
	}
	/*
	else
	{
		i = 0;
		while (i < argc)
		{
			if (fd = open(argv[i], O_RDONLY <= 0))
				write(1, "map error\n", 10);
			else
			{
				while (//첫 행 끝날 때 까지)
				{
					if (//첫 행 조건 부합하지 않으면)
					{
						print_error(&fd);
						break;
					}
					//숫자, 각 문자들 저장
				}
				while (//지도 끝날 때 까지)
				{
					if (//행의 길이 다르거나, 행이 없거나, 첫 행에서 없는 문자 나올 경우)
					{
						print_error(&fd);
						break;
					}
					//배열에 지도 저장
				}
				//가장 큰 정사각형 출력
				close(fd);
			}
			i++;
		}
	}
	*/
	exit (1);
}



