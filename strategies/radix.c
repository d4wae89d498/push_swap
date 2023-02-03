#include "solver.h"
#include "limits.h"

static int	get_max(t_stack *s)
{
	int	max;
	int	i;

	max = INT_MIN;
	i = 0;
	while (i < s->size)
	{
		if (s->data[i] > max)
			max = s->data[i];
		i += 1;
	}
	return (max);
}

static int	radix_util(t_stack *a, t_stack *b, t_list **l, int bits)
{
	int	j;
	int	k;
	int	i;
	int	size;

	size = a->size;
	i = 0;
	j = 0;
	while (j < bits)
	{
		k = 0;
		while (k < size)
		{
			if ((((a->data[a->size - 1]) >> j) & 1))
				i += ra(a, b, l);
			else
				i += pb(a, b, l);
			k += 1;
		}
		while (b->size)
			i += pa(a, b, l);
		j += 1;
	}
	return (i);
}

int	radix(t_stack *a, t_stack *b, t_list **l)
{
	int	bits;
	int	n;

	set_index(a, 0);
	bits = 0;
	n = get_max(a);
	while (n >> bits)
		bits += 1;
	return (radix_util(a, b, l, bits));
}
