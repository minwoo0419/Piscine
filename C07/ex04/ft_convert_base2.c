/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:49:25 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/01 18:13:00 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	is_number(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen2(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	dis_able(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[++i])
	{
		j = i + 1;
		while (base[++j])
			if (base[i] == base[j])
				return (1);
	}
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		if (is_space(base[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	min;
	int	sum;
	int	size;

	i = 0;
	min = 1;
	sum = 0;
	size = ft_strlen2(base);
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = min * -1;
		i++;
	}
	while (is_number(str[i], base) != -1)
	{
		sum = sum * size + is_number(str[i], base) * min;
		i++;
	}
	return (sum);
}
