#include "list.h"

t_list		*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list		*cur1;
	t_list		*cur2;
	int			tmp;

	tmp = 0;
	cur1 = lst;
	while (cur1)
	{
		cur2 = cur1->next;
		while (cur2)
		{
			if (cmp(cur1->data, cur2->data) != 1)
			{
				tmp = cur1->data;
				cur1->data = cur2->data;
				cur2->data = tmp;
			}
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
	return (lst);
}