#include "common.h"

int		pa(t_stack *a, t_stack *b, t_list **i)
{
	list_push(i, "pa");
	if (!b->size)
		return (1);
	stack_push(a, b->data[b->size - 1]);
	stack_pull(b);
	return (1);
}

int		pb(t_stack *a, t_stack *b, t_list **i)
{
	list_push(i, "pb");
	if (!a->size)
		return (1);
	stack_push(b, a->data[a->size - 1]);
	stack_pull(a);
	return (1);
}