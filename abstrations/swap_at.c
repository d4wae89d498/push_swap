#include "solver.h"

int	sa_at(t_stack *s, t_list **l, int x, int y, int vx, int vy)
{
	int	i;

	(void) y;
	(void) x;
	(void) vy;
	(void) vx;
	i = 0;
	if (!s->size || s->size == 1)
		return (0);
	while (s->data[s->size - 1] != vx)
	{
		i += ra(s, 0, l);
	}
	int z = 0;
	while (z < 2)
	{
		i += sa(s, 0, l);
		i += rra(s, 0, l);
		z += 1;
	}


/*	while (s->data[s->size - 1] != vy)
	{
		i += sa(s, 0, l);
		i += ra(s, 0, l);
	}
	while (s->data[y] == vy)
	{
		i += rra(s, 0, l);
		i += sa(s, 0, l);
	}
	int	z = 0;
	while (y < abs(x - y))
	{
		i += rra(s, 0, l);
		z += 1;
	}*/
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
