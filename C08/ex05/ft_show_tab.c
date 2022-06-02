/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <miwncho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:17:39 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/31 14:48:30 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	print_num(int size)
{
	char	c;

	if (size == 0)
		return ;
	c = '0' + size % 10;
	print_num(size / 10);
	write(1, &c, 1);
}

void	ft_putnbr(int size)
{
	char	c;

	c = '0' + size % 10;
	print_num(size / 10);
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		write(1, par[i].str, par[i].size);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, par[i].size);
		write(1, "\n", 1);
		i++;
	}
}
