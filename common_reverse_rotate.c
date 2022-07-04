#include "common.h"

void	rra(t_stack *a, t_stack *b)
{
	(void) b;
	ft_stack_rotate_left(a);
}

void	rrb(t_stack *a, t_stack *b)
{
	(void) a;
	ft_stack_rotate_left(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, b);
	rrb(a, b);
}
