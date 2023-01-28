#include "solver.h"

int	is_sorted_asc(t_stack *s)
{
	return (is_sorted(s, 0));
}

int	is_sorted_desc(t_stack *s)
{
	return (is_sorted(s, 1));
}

int	is_sorted(t_stack *s, int desc)
{
	int	i;

	i = 0;
	while (i < s->size - 1)
	{
		if (!desc && s->data[i] < s->data[i + 1])
			return (0);
		if (desc && s->data[i] > s->data[i + 1])
			return (0);
		i += 1;
	}
	return (1);
}

int	bubble_sort(t_stack *a, t_stack *b, t_stack *s, t_list **l, t_stack_instructions si)
{
	int	i;
	int	x;
	int	y;

	int	desc = s == b;

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
			if (is_sorted(s, desc))
				return (i);
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
	});
}

int	bubble_sort_b(t_stack *a, t_stack *b, t_list **l)
{
	return bubble_sort(a, b, b, l, (t_stack_instructions) {
		.r=rb,
		.s=sb,
		.rr=rrb,
		.p=pb
	});
}
