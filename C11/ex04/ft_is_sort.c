/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:31:32 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/04 12:05:15 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	j = 0;
	tmp = 0;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]))
		{
			j = f(tab[i - 1], tab[i]);
			if (tmp == 0)
				tmp = j;
		}
		if (j != 0 && tmp != 0 && j != tmp)
			return (0);
		i++;
	}
	return (1);
}
