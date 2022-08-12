#include "common.h"


int		ra(t_stack *a, t_stack *b, t_list **i)
{
	(void)b;
	printf("ra\n");
	stack_rotate(*a);
}

int		rb(t_stack *a, t_stack *b, t_list **i)
{
	(void)a;
	printf("rb\n");
	stack_rotate(*b);
}

int		rr(t_stack *a, t_stack *b, t_list **i)
{
	ra(a, b);
	rb(a, b);
}

