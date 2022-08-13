#include "common.h"

int	rra(t_stack *a, t_stack *b, t_list **l)
{
	(void)b;
	list_push(l, "rra");
	stack_reverse_rotate(*a);
	return (1);
}

int	rrb(t_stack *a, t_stack *b, t_list **l)
{
	(void)a;
	list_push(l, "rrb");
	stack_reverse_rotate(*b);
	return (1);
}

int	rrr(t_stack *a, t_stack *b, t_list **l)
{
	list_push(l, "rrr");
	rra(a, b, 0);
	rrb(a, b, 0);
	return (1);
}
