#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strcmp(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	chk;
	int	*cnt;

	if (argc > 1)
	{
		i = -1;
		cnt = (int *)malloc(sizeof(int) * (argc - 1));
		while (++i < argc - 1)
			cnt[i] = 0;
		i = -1;
		while (argv[1][++i])
		{
			cnt[0] = i + 1;
			j = 1;
			while (++j < argc)
			{
				if (ft_strcmp(argv[j], argv[1][i]) != 0)
					cnt[j - 1] = ft_strcmp(argv[j], argv[1][i]);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}

