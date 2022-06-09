#include <stdlib.h>
#include <stdio.h>

int	nbrlen(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
		i++;
	while (nbr)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	char		*str;
	int			i;
	int			sum;
	long long	n;

	n = nbr;
	str = (char *)malloc(sizeof(char) * 10000);
	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	sum = 1;
	while (n / sum > 9)
		sum = sum * 10;
	while (sum)
	{
		str[i++] = n / sum + '0';
		n = n % sum;
		sum = sum / 10;
	}
	str[i] = 0;
	return (str);
}

int main()
{
	printf("%s\n", ft_itoa(17892));
	printf("%s\n", ft_itoa(-11231));
	return (0);
}

