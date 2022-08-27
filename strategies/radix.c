#include "solver.h"
#include "limits.h"

static int get_max(t_stack *s)
{
	int max;
	int i;

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

static void set_index(t_stack *s)
{
	static int mem_data_sc[ARG_MAX];
	t_stack sc;

	static int passed[ARG_MAX];
	int i;
	int j;

	sc = stack_init(mem_data_sc);
	stack_clone(&sc, s);
	stack_order_asc(&sc);

	i = 0;
	while (i < s->size)
	{
		j = 0;
		while (j < s->size)
		{
			if (!passed[j] && s->data[j] == sc.data[i])
			{
				passed[j] = 1;
				s->data[j] = s->size - i;
			}
			j += 1;
		}
		i += 1;
	}
}

int radix(t_stack *a, t_stack *b, t_list **l)
{
	int i;
	int size;
	int bits;
	int n;
	int j;
	int k;

	i = 0;
	while (i < a->size)
	{
		i += 1;
	}
	set_index(a);


	size = a->size;
	bits = 0;
	n = get_max(a);
	while (n >> bits)
		bits += 1;
	j = 0;
	while (j < bits)
	{
		k = 0;
		while (k < size)
		{
			if ((((a->data[a->size - 1]) >> j)&1))
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
