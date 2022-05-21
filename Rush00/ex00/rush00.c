/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:24:05 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/21 13:15:42 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	is_angle(int x, int y, int i, int j)
{
	if (i == 1 || i == y)
		if (j == 1 || j == x)
			return (1);
	return (0);
}

int	is_width(int x, int y, int i, int j)
{
	if (i == 1 || i == y)
		if (j != 1 && j != x)
			return (1);
	return (0);
}

int	is_depth(int x, int y, int i, int j)
{
	if (i != 1 && i != y)
		if (j == 1 || j == x)
			return (1);
	return (0);
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			if (is_angle(x, y, i, j))
				ft_putchar('o');
			else if (is_width(x, y, i, j))
				ft_putchar('-');
			else if (is_depth(x, y, i, j))
				ft_putchar('|');
			else
				ft_putchar(' ');
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
