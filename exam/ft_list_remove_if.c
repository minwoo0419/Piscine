#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list;
	t_list	*tmp;

	while (*begin_list && cmp(*begin_list->data, data_ref) == 0)
	{
		list = *begin_list;
		*begin_list = *begin_list->next;
		free(list);
	}
	list = *begin_list;
	while (list && list->next)
	{
		if (cmp(list->next->data, data_ref) == 0)
		{
			tmp = list->next;
			list->next = tmp->next;
			free(tmp)
		}
		list = list->next;
	}
}
