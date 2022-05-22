/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:48:40 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/22 11:26:09 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	sum;

	if (nb < 0)
		return (0);
	i = 1;
	sum = 1;
	while (i <= nb)
	{
		sum = sum * i;
		i++;
	}
	return (sum);
}
