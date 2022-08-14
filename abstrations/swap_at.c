#include "solver.h"

int	sa_at(t_stack *s, t_list **l, int x, int y, int vx, int vy)
{
	int		i;
	int		k;
	int		z;

	(void) y;
	(void) x;
	(void) z;
	(void) vy;
	(void) vx;
	
	k = 0;
	i = 0;
	if (!s->size || s->size == 1)
		return (0);
	if (vx == vy)
		return (0);
	if (s->size == 2 || x + y == 2 * s->size - 3)
		return (sa(s, 0, l));
	while (s->data[s->size - 1] != vx)
	{
		 i += ra(s, 0, l);
			k += 1;
	}

	while (s->data[s->size - 2] != vy)
	{
		i += sa(s, 0, l);
		i += ra(s, 0, l);
	}
	da(s, 0, 0);
	z = abs(x - y) - 1;
	while (z)
	{
		i += ra(s, 0, l);
		i += sa(s, 0, l);

		z -= 1;
	}
	while (k > 1)
	{
		i += rra(s, 0, l);
		k -= 1;
	}

	return (i);
}

int	sb_at(t_stack *s, t_list **l, int x, int y, int vx, int vy)
{
	(void) s;
	(void) l;
	(void) x;
	(void) y;
	(void) vx;
	(void) vy;
	return (0);
}
