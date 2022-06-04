/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:47:54 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/02 15:52:28 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	dis_able(char *base);

int	ft_strlen2(char *base);

int	base_strlen(long long num, int size)
{
	int	i;

	i = 1;
	if (num < 0)
	{
		num = -1 * num;
		i++;
	}
	while (num / size > 0)
	{
		num = num / size;
		i++;
	}
	return (i);
}

void	itoa_base(long long num, char *str, char *base, int size)
{
	int	i;
	int	sum;

	sum = 1;
	i = 0;
	if (num < 0)
	{
		str[i++] = '-';
		num = -num;
	}
	while (num / sum >= (long long)size)
		sum = sum * size;
	while (sum)
	{
		str[i] = base[num / sum];
		num = num % sum;
		sum = sum / size;
		i++;
	}
	str[i] = 0;
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long		num;
	int				size;
	char			*str;

	if (dis_able(base_from) || dis_able(base_to))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	size = ft_strlen2(base_to);
	str = (char *)malloc(sizeof(char) * (base_strlen(num, size) + 1));
	if (!str)
		return (0);
	itoa_base(num, str, base_to, size);
	return (str);
}
