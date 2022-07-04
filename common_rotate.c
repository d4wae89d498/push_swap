#include "common.h"

void	ra(t_stack *a, t_stack *b)
{
	(void) b;
	ft_stack_rotate_right(a);
}

void	rb(t_stack *a, t_stack *b)
{
	(void) a;
	ft_stack_rotate_right(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, b);
	rb(a, b);
}

