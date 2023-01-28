#include "solver.h"

int	swap_at(
		t_stack *a, 
		t_stack *b, 
		t_list **l, 
		int x, 
		int y, 
		int vx, 
		int vy, 
		t_stack *s, 
		t_stack_instructions si
)
{

	int		i;
	int		k;
	int		z;

	k = 0;
	i = 0;
	if (!s->size || s->size == 1)
		return (0);
	if (vx == vy)
		return (0);
	if (s->size == 2 || x + y == 2 * s->size - 3)
		return (si.s(a, b, l));
	while (s->data[s->size - 1] != vx)
	{
		 i += si.r(a, b, l);
			k += 1;
	}

	while (s->data[s->size - 2] != vy)
	{
		i += si.s(a, b, l);
		i += si.r(a, b, l);
	}
	da(s, 0, 0);
	z = abs(x - y) - 1;
	while (z)
	{
		i += si.r(a, b, l);
		i += si.s(a, b, l);

		z -= 1;
	}
	while (k > 1)
	{
		i += si.rr(a, b, l);
		k -= 1;
	}

	return (i);
}

int	sa_at(t_stack *a, t_stack *b, t_list **l, int x, int y, int vx, int vy)
{
	return swap_at(a, b, l, x, y, vx, vy, a, (t_stack_instructions) {
		.r=ra,
		.s=sa,
		.rr=rra,
		.p=pa
	});
}

int	sb_at(t_stack *a, t_stack *b, t_list **l, int x, int y, int vx, int vy)
{
	return swap_at(a, b, l, x, y, vx, vy, b, (t_stack_instructions) {
		.r=rb,
		.s=sb,
		.rr=rrb,
		.p=pb
	});
}
