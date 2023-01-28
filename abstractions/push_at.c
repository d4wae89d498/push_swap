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
#if LOG == 1
printf("index=%i for n=%i\n", i, n);
#endif
	return i;
}

int	find_index_rev(t_stack s, int n)
{
	int	i;

	i = 0;
	while (i < s.size)
	{
		if (s.data[i] < n)
			break ;
		i += 1;
	}
#if LOG == 1
printf("index=%i for n=%i\n", i, n);
#endif
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

int	pb_at_rev(t_stack *a, t_stack *b, t_list **l, int n)
{
	int	i;

	i = 0;
	if (n == b->size)
		return (pb(a, b, l));
	if (n == 0)
	{
		i += pb(a, b, l);
		i += rb(a, b, l);
		return (i);
	}
	i += do_x(a, b, l, b->size - n, rb);
	i += pb(a, b, l);
	i += do_x(a, b, l, b->size - n - 1, rrb);
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

int	pa_at_rev(t_stack *a, t_stack *b, t_list **l, int n)
{
	int	i;

	i = 0;
	if (n == b->size)
		return (pa(a, b, l));
	if (n == 0)
	{
		i += pa(a, b, l);
		i += ra(a, b, l);
		return (i);
	}
	i += do_x(a, b, l, a->size - n, ra);
	i += pa(a, b, l);
	i += do_x(a, b, l, a->size - n - 1, rra);
	return (i);
}

int	pa_at(t_stack *a, t_stack *b, t_list **l, int n)
{
	int	i;

	i = 0;
	if (!b->size)
		return (pa(a, b, l));
	if (n == b->size)
		return (pa(a, b, l));
	i += do_x(a, b, l, n, rra);
	i += pa(a, b, l);
	i += do_x(a, b, l, n + 1, ra);
	return (i);
}
