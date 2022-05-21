/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:54:52 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/21 19:14:48 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len;

	if (!str || !to_find)
		return (str);
	len = 0;
	while (to_find[len])
		len++;
	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
			while (str[i + j] == to_find[j])
				j++;
		if (j == len)
			return (&str[i]);
		i++;
	}
	return (0);
}
