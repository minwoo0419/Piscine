#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp()))
{
	t_list	*tmp;
	t_list	*list;

	while (*begin_list && !cmp((*begin_list)->data, data_ref))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	list = *begin_list;
	while (list && list->next)
	{
		if (!cmp(list->data, data_ref))
		{
			tmp = list->next;
			list->next = tmp->next;
			free(tmp);
		}
		list = list->next;
	}
}
