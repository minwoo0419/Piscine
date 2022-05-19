/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minwcho <minwcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:32:24 by minwcho           #+#    #+#             */
/*   Updated: 2022/05/19 17:36:39 by minwcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./ex00/ft_ft.c"
#include "./ex01/ft_ultimate_ft.c"
#include "./ex02/ft_swap.c"
#include "./ex03/ft_div_mod.c"
#include "./ex04/ft_ultimate_div_mod.c"
#include "./ex05/ft_putstr.c"
#include "./ex06/ft_strlen.c"
#include "./ex07/ft_rev_int_tab.c"
#include "./ex08/ft_sort_int_tab.c"

int	main(void)
{
	int		nbr;
	int		*nbr1;
	int		**nbr2;
	int		***nbr3;
	int		****nbr4;
	int		*****nbr5;
	int		******nbr6;
	int		*******nbr7;
	int		********nbr8;
	int		*********nbr9;
	int		a;
	int		b;
	int		div;
	int		mod;
	char	*str;
	int		tab[10];
	int		size;
	int		i;

	nbr1 = &nbr;
	nbr2 = &nbr1;
	nbr3 = &nbr2;
	nbr4 = &nbr3;
	nbr5 = &nbr4;
	nbr6 = &nbr5;
	nbr7 = &nbr6;
	nbr8 = &nbr7;
	nbr9 = &nbr8;

	a = 24;
	b = 42;
	str = "abcdefgh";
	tab[0] = 2;
	tab[1] = 5;
	tab[2] = 7;
	tab[3] = 1;
	tab[4] = 9;
	tab[5] = 4;
	tab[6] = 8;
	tab[7] = 3;
	tab[8] = 0;
	tab[9] = 6;	
	size = 10;
	i = 0;
	ft_ft(&nbr);
	printf("ex00:\n%d\n", nbr);
	nbr = 0;
	ft_ultimate_ft(nbr9);
	printf("ex01:\n%d\n", nbr);
	ft_swap(&a, &b);
	printf("ex02:\n%d %d\n", a, b);
	ft_div_mod(a, b, &div, &mod);
	printf("ex03:\n%d %d\n", div, mod);
	ft_ultimate_div_mod(&a, &b);
	printf("ex04:\n%d %d\n", a, b);
	printf("ex05:\n");
	ft_putstr(str);
	printf("\nex06:\n%d\n", ft_strlen(str));
	ft_rev_int_tab(tab, size);
	printf("ex07:\n");
	while (i < size)
		printf("%d ", tab[i++]);
	printf("\n");
	ft_sort_int_tab(tab, size);
	printf("ex08:\n");
	i = 0;
	while (i < size)
		printf("%d ", tab[i++]);
	return (0);
}
