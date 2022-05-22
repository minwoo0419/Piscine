/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:39:01 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/22 19:50:27 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	first_print(unsigned long addr, int cnt)
{
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = cnt;
	if (!addr)
	{
		while (i < 16)
		{
			write(1, "0", 1);
			i++;
		}
		write(1, ":", 1);
		return ;
	}
	first_print(addr / 16, cnt + 1);
	write(1, &hex[addr % 16], 1);
}

void	second_print(unsigned char *addr, int cnt, char *str)
{
	char	*hex;
	int		i;

	i = 0;
	hex = "0123456789abcdef";
	while (i < cnt)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, &hex[addr[i] / 16], 1);
		write(1, &hex[addr[i] % 16], 1);
		if (addr[i] < 32 || addr[i] > 126)
			str[i] = '.';
		else
			str[i] = addr[i];
		i++;
	}
	write(1, " ", 1);
	while (i < 16)
	{
		write(1, " ", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				i;
	int				cnt;
	char			str[17];
	unsigned char	*put;

	i = 0;
	while (size)
	{
		if (size / 16)
			cnt = 16;
		else
			cnt = size;
		put = (unsigned char *)addr + i;
		first_print((unsigned long)put, 0);
		second_print(put, cnt, str);
		write(1, str, cnt);
		size = size - cnt;
		i = i + 16;
		write(1, "\n", 1);
	}
	return (addr);
}
