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

int	order_a(t_stack *a, t_stack *ac, t_list **l)
{
	int	i;
	int	ret;
	int	index;
	ret = 0;
	i = 0;
	while (i < ac->size)
	{
		index = find_index_of(a, ac->data[i]);
		printf("sb_at [index=%i (%i)] with [indexc=%i (%i)]\n", i, 
			a->data[i],
			index,
			a->data[index]
		);
		ret += sa_at(a, l, i, index, a->data[i], a->data[index]);
		dd(a, ac, 0);
		i += 1;
	}
	return (ret);
}

int	order_b(t_stack *b, t_stack *bc, t_list **l)
{
	int	i;
	int	indexc;
	int	index;
	int	ret;

	ret = 0;
	i = 0;
	while (i < bc->size)
	{
		index = find_index_of(b, b->data[i]);
		indexc = find_index_of(b, bc->data[i]);
		printf("sb_at [index=%i (%i)] with [indexc=%i (%i)]\n", index, 
			b->data[index],
			indexc,
			b->data[indexc]
		);
		ret += sb_at(b, l, index, indexc, b->data[indexc], b->data[index]);
		i += 1;
	}
	return (ret);
}
