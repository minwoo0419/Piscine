
int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	sum;

	if (nb < 0)
		return (0);
	i = 0;
	sum = 1;
	while (i < power)
	{
		sum = sum * nb;
		i++;
	}
	return (sum);
}
