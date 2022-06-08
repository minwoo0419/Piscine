/*oAssignment name  : str_maxlenoc 
Expected files   : str_maxlenoc.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------


하나 이상의 행을 취하고 다음을 표시하는 프로그램을 작성하십시오.
다음 줄 바꿈, 각 줄에 나타나는 가장 긴 줄
매개변수. 둘 이상의 행이 일치하면 일치하는 행이 표시됩니다.
첫 번째 매개변수에서 첫 번째로 나타납니다. 빈 문자열에 주의하십시오.
기술적으로 모든 줄에 나타납니다.
매개변수가 없으면 프로그램은 새 행('\n')을 표시합니다.

Examples:

$>./str_maxlenoc ab bac abacabccabcb
a
$>./str_maxlenoc bonjour salut bonjour bonjour
u
$>./str_maxlenoc xoxAoxo xoxAox  oxAox oxo  A ooxAoxx oxooxo Axo | cat -e
$
$>./str_maxlenoc bosdsdfnjodur atehhellosd afkuonjosurafg headfgllosf fghellosag afdfbosnjourafg
os
$>./str_maxlenoc | cat -e
$

*/
#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

int		find_indx_min_str(int ac, char *av[])
{

	int minLen;
	int minIdx;
	int	lenght;
	int i;
	
	minLen = (~0u >> 1); 
	minIdx = 1;
	i = 1;
	while (i < ac)
	{
		lenght = ft_strlen(av[i]);
		if (minLen > lenght)
		{
			minLen = lenght;
			minIdx = i;
		}
		i++;
	}
	return (minIdx);
}

int		find_fragment(char *fragment, char *str, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (fragment[i] != str[i])
		{
			if (!str[1])
				return (0);
			str++;
			i = -1;
		}
	}
	return (1);
}

int		largest_match_size(char *fragment, int ac, char *av[])
{

	int	len;
	int	i;

	len = ft_strlen(fragment);
	i = -1;
	while (++i < ac)
	{
		if (!find_fragment(fragment, av[i], len))
		{
			if (len <= 1)
				return (-1);
			len--;
			i = -1;
		}
	}
	return (len);
}

void	ft_swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_str_maxlenoc(int ac, char *av[])
{
	char	*fragment;
	int		index;
	int		max_len;
	int		max_index;
	int		tmp;

	if (ac == 1)
		write(1, av[0], ft_strlen(av[0]));
	else
	{
		tmp = find_indx_min_str(ac, av);
		if (tmp != 1)
			ft_swap(&av[0], &av[tmp]);
		fragment = av[0];
		index = 0;
		max_index = 0;
		max_len = -1;
		ac--;
		av++;
		while (*(fragment + index))
		{
			tmp = largest_match_size(fragment + index, ac, av);
			if (max_len < tmp)
			{
				max_len = tmp;
				max_index = index;
			}
			index++;
		}
		if (max_index > -1)
			write(1, fragment + max_index, max_len);
	}
	write(1, "\n", 1);
	return (0);
}

int		main(int ac, char *av[])
{
	if (ac >= 2)
		ft_str_maxlenoc(ac - 1, av + 1);
	else
		write(1, "\n", 1);
	return (0);
}
