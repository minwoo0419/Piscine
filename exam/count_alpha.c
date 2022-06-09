#include <stdio.h>

int	check(char *s, char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	cnt;
	int	sum;

	if (argc == 2)
	{
		i = -1;
		while (argv[1][++i])
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = argv[1][i] - 'A' + 'a';
		i = -1;
		sum = 0;
		while (argv[1][++i])
		{
			if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') && !check(argv[1], argv[1][i], i))
			{
				cnt = 0;
				j = i - 1;
				while (argv[1][++j])
					if (argv[1][j] == argv[1][i])
						cnt++;
				if (sum)
					printf(", ");
				if (cnt)
					printf("%c%d", argv[1][i], cnt);
				sum++;
			}
		}
	}
	printf("\n");
	return (0);
}
