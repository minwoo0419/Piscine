#include <unistd.h>
#include <stdlib.h>

char	**split(char *str)
{
	char	**s;
	int		i;
	int		j;
	int		k;

	s = (char **)malloc(sizeof(char *) * 10000);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] > 32)
		{
			k = 0;
			s[j] = (char *)malloc(sizeof(char) * 10000);
			while (str[i] > 32)
			{
				s[j][k] = str[i];
				k++;
				i++;
			}
			s[j][k] = 0;
			j++;
		}
		while (str[i] <= 32 && str[i])
			i++;
	}
	s[j] = 0;
	return (s);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		k;
	char	**s;

	if (argc >= 2)
	{
		i = 0;
		s = split(argv[1]);
		while (s[i])
			i++;
		k = i - 1;
		while (k >= 0)
		{
			j = 0;
			while (s[k][j])
			{
				write(1, &s[k][j], 1);
				j++;
			}
			if (k != 0)
				write(1, " ", 1);
			k--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
