#include "solver.h"

int	find_index(t_stack s, int n)
{
	int	i;

	i = 0;
	while (i < s.size)
	{
		if (s.data[i] >= n)
			break ;
		i += 1;
	}
	return i;
}

int	do_x(t_stack *a, t_stack *b, t_list **l, int n, int(*instr)(t_stack *a, t_stack *b, t_list **l))
{
	int	i;

	i = 0;
	while (n)
	{
		i += instr(a, b, l);
		n -= 1;
	}
	return (i);
}


int	pb_at(t_stack *a, t_stack *b, t_list **l, int n)
{
	int	i;

	i = 0;

	if (!b->size)
		return (pb(a, b, l));
	if (n == b->size)
		return (pb(a, b, l));
	i += do_x(a, b, l, n, rrb);
	i += pb(a, b, l);
	i += do_x(a, b, l, n + 1, rb);
	return (i);
}
