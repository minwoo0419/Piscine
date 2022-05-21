/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:27:45 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/21 14:42:12 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	is_anglea(int x, int y, int i, int j)
{
	if ((i == 1 && j == 1) || (i == y && j == x))
		return (1);
	return (0);
}

int	is_anglec(int x, int y, int i, int j)
{
	if ((i == y && j == 1) || (i == 1 && j == x))
		return (1);
	return (0);
}

int	is_space(int x, int y, int i, int j)
{
	if (i != 1 && i != y)
	{
		if (j != 1 && j != x)
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
			if (is_anglea(x, y, i, j))
				ft_putchar('A');
			else if (is_anglec(x, y, i, j))
				ft_putchar('C');
			else if (is_space(x, y, i, j))
				ft_putchar(' ');
			else
				ft_putchar('B');
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
