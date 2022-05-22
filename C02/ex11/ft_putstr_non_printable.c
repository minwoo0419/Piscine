/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:28:05 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/21 14:17:55 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_able(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

void	is_hex(char c)
{
	if (c >= 10)
		c = c - 10 + 'a';
	else
		c = c + '0';
	write(1, &c, 1);
}

void	dis_print(char c)
{
	write(1, "\\", 1);
	is_hex(c / 16);
	is_hex(c % 16);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (!is_able(*str))
			dis_print(*str);
		else
			write(1, &(*str), 1);
		str++;
	}
}
