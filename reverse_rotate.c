#include "common.h"


int		rra(t_stack *a, t_stack *b, t_list **i)
{
	(void)b;
	printf("rra\n");
	stack_reverse_rotate(*a);
}

int		rrb(t_stack *a, t_stack *b, t_list **i)
{
	(void)a;
	printf("rrb\n");
	stack_reverse_rotate(*b);
}

int		rrr(t_stack *a, t_stack *b, t_list **i)
{
	rra(a, b);
	rrb(a, b);
}
