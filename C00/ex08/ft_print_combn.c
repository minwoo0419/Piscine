/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:34:05 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/18 12:36:01 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	comb(int n, int cnt, int t, char *num)
{
	int	i;

	i = t + 1;
	if (n == cnt)
	{
		write(1, num, n);
		write(1, ", ", 2);
		return ;
	}
	while (i <= 10 - n + cnt)
	{
		num[cnt] = i + '0';
		comb(n, cnt+1, i, num);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		cnt;
	char	a;
	char	num[10];

	i = 0;
	cnt = 0;
	while (i < 10 - n)
	{
		num[0] = i + '0';
		comb(n, cnt+1, i, num);
		i++;
	}
	while (i < 10)
	{
		a = i + '0';
		write(1, &a, 1);
		i++;
	}
}
