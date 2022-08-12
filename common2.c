#include "common.h"

void	ra(t_stack *a, t_stack *b)
{
	(void)b;
	printf("ra\n");
	stack_rotate(*a);
}

void	rb(t_stack *a, t_stack *b)
{
	(void)a;
	printf("rb\n");
	stack_rotate(*b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, b);
	rb(a, b);
}

