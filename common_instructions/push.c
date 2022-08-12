#include "common.h"

int		pa(t_stack *a, t_stack *b, t_list **i)
{
	printf("pa\n");
	if (!b->size)
		return ;
	stack_push(a, b->data[b->size - 1]);
	stack_pull(b);
}

int		pb(t_stack *a, t_stack *b, t_list **i)
{
	printf("pb\n");
	if (!a->size)
		return ;
	stack_push(b, a->data[a->size - 1]);
	stack_pull(a);
}
