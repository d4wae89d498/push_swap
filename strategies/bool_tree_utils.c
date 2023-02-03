#include "solver.h"
#include "limits.h"

static int	is_branch(int(*try)(t_stack *s, t_list **l, int depth), 
		t_stack *s,
		t_list **l,
		int depth,
		int *ic)
{
	int	success;

	success = try(s, l, depth);
	if (success && success < *ic)
	{
		*ic = success;
		return (1);
	}
	return (0);
}

char bool_tree_c(t_stack *s, t_list **l, t_possible_instructions pi,
			int depth)
{
	char	c;
	int		ic;
	int		success;

	ic = INT_MAX;
	success = 0;
	c = 0;
	if (pi.s && is_branch(try_s, s, l, depth, &ic))
		c = 's';
	if (pi.r && is_branch(try_r, s, l, depth, &ic))
		c = 'r';
	if (pi.rr && is_branch(try_rr, s, l, depth, &ic))
		c = 'i';
	if (!ic)
		c = 'r';
	return c;
}
