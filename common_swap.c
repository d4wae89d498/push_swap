#include "common.h"

void	sa(t_stack *a, t_stack *b)
{
	(void) b;
	ft_stack_swap(a, 0, 1);
}

void	sb(t_stack *a, t_stack *b)
{
	(void) a;
	ft_stack_swap(b, 0, 1);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, a);
	sb(a, b);
}
