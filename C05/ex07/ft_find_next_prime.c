int	ft_find_next_prime(int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = nb;
	j = 2;
	if (i <= j)
		return (j);
	while (j * j <= i)
	{
		if (i % j == 0)
		{
			i++;
			j = 2;
		}
		else
			j++;
	}
	return (i);
}
