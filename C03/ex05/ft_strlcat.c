/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:38:11 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/26 13:22:20 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] && (i < size))
		i++;
	j = 0;
	if (size > i)
	{
		while (src[j] && (i + j) < (size - 1))
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	while (src[j])
		j++;
	return (i + j);
}
