#include "common.h"

void	rra(t_stack *a, t_stack *b)
{
	(void)b;
	printf("rra\n");
	stack_reverse_rotate(*a);
}
void	rrb(t_stack *a, t_stack *b)
{
	(void)a;
	printf("rrb\n");
	stack_reverse_rotate(*b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, b);
	rrb(a, b);
}