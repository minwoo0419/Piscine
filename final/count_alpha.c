#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	c;
	int		cnt;
	int		a[26];

	if (argc == 2)
	{
		i = -1;
		while (++i < 26)
			a[i] = 0;
		i = -1;
		while (argv[1][++i])
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = argv[1][i] - 'A' + 'a';
		i = -1;
		cnt = 0;
		while (argv[1][++i])
		{
			c = argv[1][i];
			if (c >= 'a' && c <= 'z' && !a[c - 'a'])
			{
				j = i - 1;
				while (argv[1][++j])
				{
					if (argv[1][j] == c)
						a[c - 'a']++;
				}
				if (cnt)
					printf(", ");
				printf("%c%d", c, a[c - 'a']);
				cnt++;
			}
		}
	}
	printf("\n");
	return (0);
}
