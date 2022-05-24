/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:24:05 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/23 16:26:43 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	is_slash(int x, int y, int i, int j)
{
	if (i == 1 && j == 1)
		return (1);
	if (y != 1 && x != 1)
		if (i == y && j == x)
			return (1);
	return (0);
}

int	is_back_slash(int x, int y, int i, int j)
{
	if (i == 1 && j == x)
		return (1);
	else if (i == y && j == 1)
		return (1);
	return (0);
}

int	is_side(int x, int y, int i, int j)
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
			if (is_slash(x, y, i, j))
				ft_putchar('/');
			else if (is_back_slash(x, y, i, j))
				ft_putchar('\\');
			else if (is_side(x, y, i, j))
				ft_putchar('*');
			else
				ft_putchar(' ');
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
