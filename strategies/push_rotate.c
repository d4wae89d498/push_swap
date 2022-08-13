#include "solver.h"

int		push_rotate(t_stack *a, t_stack *b, t_list **l)
{
	int	i;
	int	index;

	dd(a, b, 0);
	i = 0;
	while (a->size)
	{
		index = find_index(*b, a->data[a->size - 1]);
		
		if (index < b->size / 2)
			i += pb_at(a, b, l, index);
		else
			i += pb_at_rev(a, b, l, index);
		dd(a, b, 0);
	}
	while (b->size)
		i += pa(a, b, l);
	dd(a, b, 0);
	return (i);
}
