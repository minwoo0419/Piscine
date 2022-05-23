/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:26:10 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/23 14:02:11 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	dis_able(char *base);

int	ft_strlen(char *base);

int	base_strlen(int num, int size)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		num = -num;
		i++;
	}
	while (num > 0)
	{
		num = num / size;
		i++;
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		size;
	int		i;
	char	*str;

	if (dis_able(base_from) || dis_able(base_to))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	size = ft_strlen(base_to);
	i = base_strlen(num, size);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	str[i--] = 0;
	while (num > 0)
	{
		str[i] = base_to[num % size];
		i--;
		num = num / size;
	}
	return (str);
}
