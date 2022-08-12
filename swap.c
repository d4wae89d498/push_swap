#include "common.h"

int		sa(t_stack *a, t_stack *b, t_list **i)
{
	list
	(void)b;
	list_push(i, "sa");
	stack_swap(*a);
}


int		sb(t_stack *a, t_stack *b, t_list **i)
{
	(void)a;
	list_push(i, "sb");
	stack_swap(*b);
}

int		ss(t_stack *a, t_stack *b, t_list **i)
{
//	printf("ss\n");
	sa(a, b);
	sb(a, b);
}


