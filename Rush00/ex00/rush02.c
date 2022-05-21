/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:36:19 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/21 13:53:24 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	is_a(int x, int y, int i, int j)
{
	if (i == 1)
		if (j == 1 || j == x)
			return (1);
	return (0);
}

int	is_c(int x, int y, int i, int j)
{
	if (i == y)
		if (j == 1 || j == x)
			return (1);
	return (0);
}

int	is_b(int x, int y, int i, int j)
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
			if (is_a(x, y, i, j))
				ft_putchar('A');
			else if (is_b(x, y, i, j))
				ft_putchar('B');
			else if (is_c(x, y, i, j))
				ft_putchar('C');
			else
				ft_putchar(' ');
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
