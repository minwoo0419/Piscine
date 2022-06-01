/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:47:24 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/01 16:59:54 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*num;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	num = (int *)malloc(sizeof(int) * (max - min));
	if (!num)
	{
		*range = 0;
		return (-1);
	}
	i = min;
	while (i < max)
	{
		num[i - min] = i;
		i++;
	}
	*range = num;
	return (max - min);
}
