#include <unistd.h>

int	g_tot;

int	ft_abs(char a, char b)
{
	if (a < b)
		return (b - a);
	return (a - b);
}

void	print(char *pl)
{
	while (*pl)
	{
		write(1, &(*pl), 1);
		pl++;
	}
	write(1, "\n", 1);
}

void	rec(char *pl, int cnt)
{
	int	i;
	int	j;

	if (cnt == 10)
	{
		print(pl);
		g_tot++;
		return ;
	}
	j = 0;
	while (j < 10)
	{
		i = 0;
		pl[cnt] = '0' + j;
		while (i < cnt)
		{
			if (pl[i] == pl[cnt] || (cnt - i) == ft_abs(pl[i], pl[cnt]))
				i = cnt + 1;
			i++;
		}
		if (i == cnt)
			rec(pl, cnt + 1);
		j++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	pl[11];

	g_tot = 0;
	rec(pl, 0);
	return (g_tot);
}
