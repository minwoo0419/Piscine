/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:37:33 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/22 16:41:00 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	sum;

	if (nb < 0)
		return (0);
	i = 0;
	sum = 1;
	while (i < power)
	{
		sum = sum * nb;
		i++;
	}
	return (sum);
}
