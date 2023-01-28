#include "solver.h"

int 	cmp(t_stack *s, int ix, int iy, int desc)
{
	if (desc)
		return (s->data[ix] > s->data[iy]);
	return (s->data[ix] < s->data[iy]);
}
