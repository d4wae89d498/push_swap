#include "solver.h"

int		push_rotate(t_stack *a, t_stack *b, t_list **l)
{
	int	i;

	i = 0;
	while (a->size)
		i += pb_at(a, b, l, find_index(*b, a->data[a->size - 1]));
	while (b->size)
		i += pa(a, b, l);
	return (i);
}
