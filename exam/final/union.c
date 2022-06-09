#include <unistd.h>

int	check(char *s, char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (c == s[i])
			return (0);
		i++;
	}
	return (1);
}

int	check2(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	i;
	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (check(argv[1], argv[1][i], i))
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (check2(argv[1], argv[2][i]) && check(argv[2], argv[2][i], i))
				write(1, &argv[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
