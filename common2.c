#include "common.h"

void	ra(t_stack *a, t_stack *b)
{
	printf("ra\n");
	stack_rotate(*a);
}

void	rb(t_stack *a, t_stack *b)
{
	printf("rb\n");
	stack_rotate(*b);
}

void	rr(t_stack *a, t_stack *b)
{
	rra(a, b);
	rrb(a, b);
}

