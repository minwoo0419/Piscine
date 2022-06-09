void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_list	*sort_list(t_list *begin_list, int (*cmp)(int, int))
{
	t_list	*list;
	t_list *tmp;

	list = begin_list;
	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (cmp(list->data, tmp->data) == 0)
				swap(&list->data, &tmp->data);
			tmp = tmp->list;
		}
		list = list->next;
	}
	return (begin_list);
}
