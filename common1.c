#include "common.h"

void	sa(t_stack *a, t_stack *b)
{
	printf("sa\n");
	stack_swap(*a);
}

void	sb(t_stack *a, t_stack *b)
{
	printf("sb\n");
	stack_swap(*b);
}

void	ss(t_stack *a, t_stack *b)
{
//	printf("ss\n");
	sa(a, b);
	sb(a, b);
}

void	pa(t_stack *a, t_stack *b)
{
	printf("pa\n");
	if (!b->size)
		return ;
	stack_push(a, b->data[b->size - 1]);
	stack_pull(b);
}

void	pb(t_stack *a, t_stack *b)
{
	printf("pb\n");
	if (!a->size)
		return ;
	stack_push(b, a->data[a->size - 1]);
	stack_pull(a);
}
