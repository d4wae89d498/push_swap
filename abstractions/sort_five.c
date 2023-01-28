#include "solver.h"


int		sort_five(t_stack *a, t_stack *b, t_stack *s, t_list **l, t_stack_instructions si)
{
	int	desc = s == b;
//	int	y;
	int	i;

	i = 0;
	if (s->size >= 2)
	{
		if (!cmp(s, 1, 0, desc))
		{
			i += si.s(a, b, l);
		}
	}
	if (s->size == 3)
	{
		if (!cmp(s, 2, 0, desc))
			i += si.r(a, b, l);
		else
			i += si.rr(a, b, l);
		if (!cmp(s, 2, 0, desc))
			i += si.r(a, b, l);
		if (!cmp(s, 2, 1, desc))
			i += si.s(a, b, l);
	}

	return (i);
}
