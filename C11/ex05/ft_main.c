/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:42:36 by minwcho           #+#    #+#             */
/*   Updated: 2022/06/01 15:42:38 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include <unistd.h>

int	dis_able(int argc, char *argv[])
{
	if (argc != 4)
		return (1);
	if (argv[2][1] != 0)
	{
		write(1, "0\n", 2);
		return (1);
	}
	if (argv[2][0] != '+' && argv[2][0] != '-')
	{
		if (argv[2][0] != '*' && argv[2][0] != '/' && argv[2][0] != '%')
		{
			write(1, "0\n", 2);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	void	(*f[5])(int, int);

	if (dis_able(argc, argv))
		return (0);
	f[0] = add;
	f[1] = sub;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
	if (argv[2][0] == '+')
		f[0](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argv[2][0] == '-')
		f[1](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argv[2][0] == '*')
		f[2](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argv[2][0] == '/')
		f[3](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argv[2][0] == '%')
		f[4](ft_atoi(argv[1]), ft_atoi(argv[3]));
	return (0);
}
