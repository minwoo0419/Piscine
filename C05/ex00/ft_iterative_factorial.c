
int	ft_iterative_factorial(int nb)
{
	int	i;
	int	sum;

	if (nb < 0)
		return (0);
	i = 1;
	sum = 1;
	while (i <= nb)
	{
		sum = sum * i;
		i++;
	}
	return (sum);
}
