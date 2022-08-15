#include "solver.h"

int	bubble_sort(t_stack *a, t_stack *b, t_stack *s, t_list **l, t_stack_instructions si, int desc)
{
	int	i;
	int	x;
	int	y;

	if (s->size < 2)
		return (0);
	i = 0;
	x = 0;
	while (x <= s->size - 1)
	{
		y = 0;
		while (y <= s->size - 2)
		{
			if (desc)
			{
				if (s->data[s->size - 2] > s->data[s->size - 1])
					i += si.s(a, b, l);
			}
			else 
			{
				if (s->data[s->size - 2] < s->data[s->size - 1])
					i += si.s(a, b, l);
			}

			i += si.r(a, b, l);
			y += 1;
		}

			i += si.r(a, b, l);
		x += 1;

	}
	return (i);
}

int	bubble_sort_a(t_stack *a, t_stack *b, t_list **l)
{
	return bubble_sort(a, b, a, l, (t_stack_instructions) {
		.r=ra,
		.s=sa,
		.rr=rra,
		.p=pa
	}, 0);
}

int	bubble_sort_b(t_stack *a, t_stack *b, t_list **l)
{
	return bubble_sort(a, b, b, l, (t_stack_instructions) {
		.r=rb,
		.s=sb,
		.rr=rrb,
		.p=pb
	}, 1);
}
