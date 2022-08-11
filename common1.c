#include "common.h"

void	sa(t_stack *a, t_stack *b)
{
	stack_swap(*a);
}

void	sb(t_stack *a, t_stack *b)
{
	stack_swap(*b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, b);
	sb(a, b);
}

void	pa(t_stack *a, t_stack *b)
{
	if (!b->size)
		return ;
	stack_push(a, b->data[b->size - 1]);
	stack_pull(b);
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a->size)
		return ;
	stack_push(b, a->data[a->size - 1]);
	stack_pull(a);
}
