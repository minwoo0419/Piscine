/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:31:35 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/04 11:28:00 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*num;

	num = (int *)malloc(sizeof(int) * length);
	if (!num)
		return (0);
	i = 0;
	while (i < length)
	{
		num[i] = f(tab[i]);
		i++;
	}
	return (num);
}
