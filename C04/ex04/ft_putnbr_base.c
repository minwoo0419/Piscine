/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:10:53 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/23 15:04:33 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	dis_able(char *base)
{
	int	i;

	i = 1;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
	{
		if (base[i] == base[i - 1])
			return (1);
		i++;
	}
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

void	change(int nbr, char *base, int size)
{
	int	num;

	if (nbr == 0)
		return ;
	num = nbr % size;
	change(nbr / size, base, size);
	write(1, &base[num], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;
	int	num;

	if (dis_able(base))
		return ;
	size = ft_strlen(base);
	printf("%d\n", size);
	if (nbr < 0)
	{
		write(1, "-", 1);
		num = -(nbr % size);
		change(-(nbr / size), base, size);
		write(1, &base[num], 1);
	}
	else
	{
		num = nbr % size;
		change(nbr / size, base, size);
		write(1, &base[num], 1);
	}
}
