int	ascending(int a, int b)
{
	return (a <= b);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	{

t_list	*sort_list(t_list *begin_list, int (*cmp)(int, int))
{

	t_list	*list;
	t_list	*tmp;

	list = begin_list;
	while (begin_list->next)
	{
		tmp = begin_list->next;
		while (tmp)
		{
			if (!cmp(begin_list->data, tmp->data))
				swap(begin_list->data, tmp->data);
			tmp = tmp->next;
		}
		begin_list = begin_list->next;
	}
	return (list);
}
