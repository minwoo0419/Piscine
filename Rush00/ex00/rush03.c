/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:53:21 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/21 15:59:56 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	is_rush_a(int x, int y, int i, int j)
{
	if (j == 1 && i == y)
		return (1);
	else if (j == 1 && i == 1)
		return (1);
	return (0);
}

int	is_rush_c(int x, int y, int i, int j)
{
	if (j == x && i == 1)
		return (1);
	else if (j == x && i == y)
		return (1);
	return (0);
}

int	is_rush_b(int x, int y, int i, int j)
{
	if (i == 1 || i == y)
	{
		if (j != 1 && j != x)
			return (1);
	}
	else
	{
		if (j == 1 || j == x)
			return (1);
	}
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
			if (is_rush_a(x, y, i, j))
				ft_putchar('A');
			else if (is_rush_c(x, y, i, j))
				ft_putchar('C');
			else if (is_rush_b(x, y, i, j))
				ft_putchar('B');
			else
				ft_putchar(' ');
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
