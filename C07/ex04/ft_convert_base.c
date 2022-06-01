/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:47:54 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/01 16:48:18 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	dis_able(char *base);

int	ft_strlen2(char *base);

int	base_strlen(int num, int size)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -1 * (num / size);
		i = i + 2;
	}
	while (num > 0)
	{
		num = num / size;
		i++;
	}
	return (i);
}

void	itoa_base(int num, char *str, char *base, int size)
{
	int	i;

	i = base_strlen(num, size);
	str[i--] = 0;
	if (num == 0)
		str[i] = base[num % size];
	if (num < 0)
	{
		str[0] = '-';
		str[i] = base[-(num % size)];
		num = -(num / size);
		i--;
	}
	if (num > 0)
	{
		while (num)
		{
			str[i] = base[num % size];
			num = num / size;
			i--;
		}
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		size;
	char	*str;

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
