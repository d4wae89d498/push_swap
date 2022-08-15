#include "solver.h"

static int	find_index_of(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (s->data[i] == n)
			return (i);
		i += 1;
	}
	return (i);
}

int	order_a(t_stack *a, t_stack *b, t_stack *ac, t_list **l)
{
	int	i;
	int	ret;
	int	index;
	ret = 0;
	i = 0;
	while (i < ac->size)
	{
		index = find_index_of(a, ac->data[i]);
		ret += sa_at(a, b, l, i, index, a->data[i], a->data[index]);
	//	dd(a, b, 0);
		i += 1;
	}
	return (ret);
}

int	order_b(t_stack *a, t_stack *b, t_stack *bc, t_list **l)
{
	int	i;
	int	ret;
	int	index;
	ret = 0;
	i = 0;
	while (i < bc->size)
	{
		index = find_index_of(b, bc->data[i]);
		ret += sb_at(a, b, l, i, index, b->data[i], b->data[index]);
		//dd(a, b, 0);
		i += 1;
	}
	return (ret);
}
