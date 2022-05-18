/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:57:33 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/18 11:33:46 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(int a)
{
	char	c;

	if (a >= 10)
	{
		c = '0' + a / 10;
		write(1, &c, 1);
		c = '0' + a % 10;
		write(1, &c, 1);
	}
	else
	{
		c = '0' + a;
		write(1, "0", 1);
		write(1, &c, 1);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			put_char(a);
			write(1, " ", 1);
			put_char(b);
			if (a != 98)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
