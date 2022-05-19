/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:14:41 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/18 21:11:24 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	a;

	if (nb == 0)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		a = '0' - nb % 10;
		nb = nb / 10;
		ft_putnbr(-nb);
		write(1, &a, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		a = nb % 10 + '0';
		write(1, &a, 1);
	}
}
