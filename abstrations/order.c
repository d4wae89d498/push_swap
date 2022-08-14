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

t_instruction	order_a(t_stack *a, t_stack *ac)
{
	static int		i;
	t_instruction	ret;

	int	index;
	

	if (i < ac->size)
	{
		index = find_index_of(a, ac->data[i]);
		printf("sa_at [i=%i] with [index=%i]\n", i, index);
		ret = swap_at(a, i, index, a->data[i], a->data[index]);
		printf("ret=%p\n", ret);
		dd(a, ac, 0);
		if (ret)
			return ret;
		i += 1;
	}
	return (0);
}

t_instruction	order_b(t_stack *b, t_stack *bc)
{
	static int	i;
	int	index;
	t_instruction	ret;

	if (i < bc->size)
	{
		index = find_index_of(b, bc->data[i]);
		printf("sb_at [i=%i] with [index=%i]\n", i, index);
		ret = swap_at(b, i, index, b->data[i], b->data[index]);
		printf("ret=%p\n", ret);
		if (ret)
			return ret;
		i += 1;
	}
	return (0);
}
