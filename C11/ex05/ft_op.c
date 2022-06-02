/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:30:46 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/01 15:30:49 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_op.h"
#include <unistd.h>

void	add(int a, int b)
{
	ft_putnbr(a + b);
}

void	sub(int a, int b)
{
	ft_putnbr(a - b);
}

void	mul(int a, int b)
{
	ft_putnbr(a * b);
}

void	div(int a, int b)
{
	if (b == 0)
		write(1, "Stop : division by zero\n", 24);
	else
		ft_putnbr(a / b);
}

void	mod(int a, int b)
{
	if (b == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
		ft_putnbr(a % b);
}
