#include <stdio.h>
#include <stdlib.h>

int	is_prime(int n)
{
	int	i;

	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		n;
	int		i;
	if (argc == 2)
	{
		n = atoi(argv[1]);
		i = 2;
		if (n == 1)
			printf("%d", n);
		while (n != 1)
		{
			if (is_prime(i) && (n % i == 0))
			{
				printf("%d", i);
				if (n / i != 1)
					printf("*");
				n = n / i;
			}
			else
				i++;
		}
	}
	printf("\n");
	return (0);
}
