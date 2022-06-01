/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:47:11 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/01 16:47:22 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*num;
	int	i;

	if (min >= max)
		return (0);
	num = (int *)malloc(sizeof(int) * (max - min));
	if (!num)
		return (0);
	i = min;
	while (i < max)
	{
		num[i - min] = i;
		i++;
	}
	return (num);
}
