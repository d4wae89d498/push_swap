#include "common.h"

int		pa(t_stack *a, t_stack *b, t_list **i)
{
	list_add(i, "pa");
	if (!b->size)
		return ;
	stack_push(a, b->data[b->size - 1]);
	stack_pull(b);
	return (1);
}

int		pb(t_stack *a, t_stack *b, t_list **i)
{
	list_add(i, "pb");
	if (!a->size)
		return ;
	stack_push(b, a->data[a->size - 1]);
	stack_pull(a);
	return (1);
}
