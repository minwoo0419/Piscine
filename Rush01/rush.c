#include <unistd.h>
#include <stdlib.h>

char	g_col[5][3];
char	g_row[5][3];
char	g_num[17];
int		g_cnt;

void	put_num(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[1][j])
	{
		if (argv[1][j] >= '0' && argv[1][j] <= '4')
		{
			g_num[i] = argv[1][j];
			i++;
			j++;
		}
		else
			j++;
	}
}

void	set_colrow(void)  //col, row 받아오기//
{
	int	i;

	i = 0;
	while (i < 4)
	{
		g_col[i][0] = g_num[i];
		g_col[i][1] = g_num[i + 4];
		g_row[i][0] = g_num[i + 8];
		g_row[i][1] = g_num[i + 12];
		i++;
	}
}

char	**set_board(int n)       //board '0'으로 초기화//
{
	int		i;
	int		j;
	char	**board;

	board = (char **)malloc(sizeof(char*) * (n + 1));
	i = 0;
	while (i < n)
	{
		j = 0;
		board[i] = (char *)malloc(sizeof(char) * (n + 1));
		while (j < n)
		{
			board[i][j] = '0';
			j++;
		}
		board[i][j] = 0;
		i++;
	}
	board[i] = 0;
	return (board);
}

void	check_col_up(char **g_cer_board)      //colup으로 확실히 들어가는 수 넣기//
{
	int		i;
	int		j;
	int		k;
	char	n;

	i = 0;
	while (i < 4)
	{
		if (g_col[i][0] == '4')
		{
			n = '1';
			j = -1;
			while (++j < 4)
				g_cer_board[j][i] = n++;
		}
		else if ((g_col[i][0] - '0') + (g_col[i][1] - '0') == 5)
			g_cer_board[g_col[i][0] - '0' - 1][i] = '4';
		else if (g_col[i][0] == '1')
			g_cer_board[0][i] = '4';
		i++;
	}
}

void	check_col_down(char **g_cer_board)      //coldown으로 확실히 들어가는 수 넣기//
{
	int		i;
	int		j;
	int		k;
	char	n;

	i = 0;
	while (i < 4)
	{
		if (g_col[i][1] == '4')
		{
			n = '1';
			j = 4;
			while (--j >= 0)
				g_cer_board[j][i] = n++;
		}
		else if (g_col[i][1] == '1')
			g_cer_board[3][i] = '4';
		i++;
	}
}

void	check_row_up(char **g_cer_board)         //rowup으로 확실히 들어가는 수 넣기//
{
	int		i;
	int		j;
	int		k;
	char	n;

	i = 0;
	while (i < 4)
	{
		if (g_row[i][0] == '4')
		{
			n = '1';
			j = -1;
			while (++j < 4)
				g_cer_board[i][j] = n++;
		}
		else if ((g_row[i][0] - '0') + (g_row[i][1] - '0') == 5)
			g_cer_board[i][g_row[i][0] - '0' - 1] = '4';
		else if (g_row[i][0] == '1')
			g_cer_board[i][0] = '4';
		i++;
	}
}

void	check_row_down(char **g_cer_board)         //rowdown으로 확실히 들어가는 수 넣기//
{
	int		i;
	int		j;
	int		k;
	char	n;

	i = 0;
	while (i < 4)
	{
		if (g_row[i][1] == '4')
		{
			n = '1';
			j = 4;
			while (--j >= 0)
				g_cer_board[i][j] = n++;
		}
		else if (g_row[i][1] == '1')
			g_cer_board[i][3] = '4';
		i++;
	}
}

int	posi(int i, int j, char num, char **g_cer_board)        //i행, j열에 겹치는 수 없는지 확인//
{
	int	a;
	int	b;

	a = 0;
	while (a < 4)
	{
		if (g_cer_board[i][a] == num && a != j && g_cer_board[i][a] != 0)
			return (0);
		a++;
	}
	b = 0;
	while (b < 4)
	{
		if (g_cer_board[b][j] == num && b != i && g_cer_board[b][j] != 0)
			return (0);
		b++;
	}
	return (1);
}

void	print_board(char **g_cer_board)       //board 출력//
{
	int	i;
	int	j;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &g_cer_board[i][j], 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	g_cnt++;
}

int	row_up_ch(int i, char **g_cer_board)        //rowup의 수에 맞게 들어갔는지//
{
	int		cnt;
	char	sum;
	int		j;

	sum = '0';
	j = -1;
	cnt = 0;
	while (++j < 4)
	{
		if (g_cer_board[i][j] > sum)
		{
			sum = g_cer_board[i][j];
			cnt++;
		}
	}
	if (cnt + '0' != g_row[i][0])
		return (0);
	return (1);
}

int	row_down_ch(int i, char **g_cer_board)        //rowdown의 수에 맞게 들어갔는지//
{
	int		cnt;
	char	sum;
	int		j;

	j = 4;
	cnt = 0;
	sum = '0';
	while (--j >= 0)
	{
		if (g_cer_board[i][j] > sum)
		{
			sum = g_cer_board[i][j];
			cnt++;
		}
	}
	if (cnt + '0' != g_row[i][1])
		return (0);
	return (1);
}

int	col_up_ch(char **g_cer_board)           //colup의 수에 맞게 들어갔는지//
{
	int		i;
	int		j;
	int		cnt;
	char	sum;
	
	j = -1;
	while (++j < 4)
	{
		i = -1;
		cnt = 0;
		sum = '0';
		while (++i < 4)
			if (g_cer_board[i][j] > sum)
			{
				sum = g_cer_board[i][j];
				cnt++;
			}
		if (cnt + '0' != g_col[j][0])
			return (0);
	}
	return (1);
}

int	col_down_ch(char **g_cer_board)            //coldown의 수에 맞게 들어갔는지//
{
	int		i;
	int		j;
	int		cnt;
	char	sum;
	
	j = 0;
	while (j < 4)
	{
		i = 4;
		cnt = 0;
		sum = '0';
		while (--i >= 0)
			if (g_cer_board[i][j] > sum)
			{
				sum = g_cer_board[i][j];
				cnt++;
			}
		if (cnt + '0' != g_col[j][1])
			return (0);
		j++;
	}
	return (1);
}

void	fill(int a, int b, char **g_cer_board)          //백트래킹으로 채워넣기//
{
	char	k;

	if (b == 4)
	{
		if (!row_up_ch(a, g_cer_board) || !row_down_ch(a, g_cer_board))
			return ;
		a++;
		b = 0;
	}
	if (a == 4)
	{
		if (col_up_ch(g_cer_board) && col_down_ch(g_cer_board))//
			print_board(g_cer_board);
		return ;
	}
	k = '1';
	if (g_cer_board[a][b] == '0')
	{
		while (k <= '4')
		{
			if (posi(a, b, k, g_cer_board))
			{
				g_cer_board[a][b] = k;
				fill(a, b+1, g_cer_board);
				g_cer_board[a][b] = '0';
			}
			k++;
		}
	}
	else
		fill(a, b + 1, g_cer_board);
}

int	error(int argc, char *argv[])            //에러확인//
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (argc != 2)
		return (1);
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '4')
		{
			if (argv[1][i + 1] >= '0' && argv[1][i + 1] <= '4')
				return (1);
			cnt++;
			i++;
		}
		else if (argv[1][i] == ' ' || argv[1][i] == '\n' || argv[1][i] == '\t')
			i++;
		else
			return (1);
	}
	if (cnt != 16)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**g_cer_board;

	if (error(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	g_cnt = 0;
	put_num(argv);
	set_colrow();
	g_cer_board = set_board(4);
	check_col_up(g_cer_board);
	check_col_down(g_cer_board);
	check_row_up(g_cer_board);
	check_row_down(g_cer_board);
	fill(0, 0, g_cer_board);
	if (g_cnt != 1)
		write(1, "Error\n", 6);
	return (0);
}
