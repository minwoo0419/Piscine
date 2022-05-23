/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:47:25 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/23 15:01:13 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printnbr(int nb)
{
	char	c;

	if (nb == 0)
		return ;
	c = '0' + nb % 10;
	ft_printnbr(nb / 10);
	write(1, &c, 1);
}	

void	ft_putnbr(int nb)
{
	char	a;

	if (nb < 0)
	{
		write(1, "-", 1);
		a = '0' - nb % 10;
		ft_printnbr(-(nb / 10));
	}
	else
	{
		a = '0' + nb % 10;
		ft_printnbr(nb / 10);
	}
	write(1, &a, 1);
}
