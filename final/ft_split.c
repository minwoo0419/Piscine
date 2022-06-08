#include <stdlib.h>

char	**ft_split(char *str)
{
	int		i;
	char	**s;
	int		j;
	int		k;

	s = (char **)malloc(sizeof(char *) * 10000);
	i = 0;
	while (str[i] <= 32 && str[i])
		i++;
	k = 0;
	while (str[i])
	{
		if (str[i] > 32)
		{
			s[k] = (char *)malloc(sizeof(char) * 10000);
			j = 0;
			while (str[i] > 32)
			{
				s[k][j] = str[i];
				j++;
				i++;
			}
			s[k][j] = 0;
			k++;
		}
		i++;
	}
	s[k] = 0;
	return (s);
}
