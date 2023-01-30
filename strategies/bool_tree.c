#include "solver.h"

int	bool_tree(t_stack *a, t_stack *b, t_list **l)
{
	int	i;

	(void) b;
	i = 0;
	i += bool_tree_r(a, l,
			(t_possible_instructions){.s = 1, .r = 1, .rr = 1}, 0);
	return (i);
}
