/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:03:00 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/22 21:11:07 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*num;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*num = (int *)malloc(sizeof(int) * (max - min));
	if (!dst)
	{
		*range = NULL;
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
