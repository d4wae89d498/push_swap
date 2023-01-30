#include "solver.h"

void set_index(t_stack *s, int *median)
{
	static int mem_data_sc[ARG_MAX];
	t_stack sc;
	static int passed[ARG_MAX];
	int i;
	int j;

	sc = stack_init(mem_data_sc);
	stack_clone(&sc, s);
	stack_order_asc(&sc);
	i = -1;
	while (++i < s->size)
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
	}
	if (median)
		*median = s->data[s->size / 2];
}
