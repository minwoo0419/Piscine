/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:32:39 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/04 12:15:46 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_swap2(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_strlen(tab) - 1;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_swap2(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
