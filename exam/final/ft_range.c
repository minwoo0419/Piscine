#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*n;
	int	i;

	i = start;
	n = (int *)malloc(sizeof(int) * 10000);
	while (i != end)
	{
		n[i - start] = i;
		(end > start) ? i++ : i--;
	}
	n[i - start] = end;
	return (n);
}
