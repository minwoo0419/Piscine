int	ft_atoi(const char *str)
{
	int	i;
	int	sum;
	int	min;

	i = 0;
	while (str[i] <= 32 && str[i])
		i++;
	min = 1;
	if (str[i] == '-')
	{
		min = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + (str[i] - '0') * min;
		i++;
	}
	return (sum);
}
