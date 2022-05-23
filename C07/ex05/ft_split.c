/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:05:08 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/23 16:29:01 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i] || c == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!is_check(str[i++], charset))
		j++;
	while (str[i])
	{
		if (!is_check(str[i], charset) && is_check(str[i-1], charset))
			j++;
		i++;
	}
	return (j);
}

char	*ft_strncpy(char *src, int size)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char	**ft_split(char *str, char *charset)
{
	char	**s;
	int		i;
	int		j;
	int		k;

	s = (char **)malloc(sizeof(char *) * (ft_strlen(str, charset) + 1));
	if (!s)
		return (0);
	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (!is_check(str[i + j], charset))
		{
			j++;
		}
		if (j)
		{
			s[k] = ft_strncpy(str + i, j);
			k++;
		}
		i = i + j;
		i++;
	}
	s[k] = 0;
	return (s);
}
