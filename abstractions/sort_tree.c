#include "solver.h"

int		sort_tree(t_stack *a, t_stack *b, t_stack *s, t_list **l, t_stack_instructions si)
{
		int i = 0;
		int desc = s == b;

		if (cmp(s, 0, 1, desc) && cmp(s, 1, 2, desc))
		{
			i += si.r(a, b, l);	
			i += si.s(a, b, l);	
		}
		else if (cmp(s, 0, 1, desc) && !cmp(s, 0, 2, desc))
		{
			i += si.rr(a, b, l);	
			i += si.s(a, b, l);	
		}

		else if (cmp(s, 0, 1, desc) && !cmp(s, 1, 2, desc))
		{
			i += si.rr(a, b, l);	
		}

		else if (!cmp(s, 0, 1, desc) && cmp(s, 0, 2, desc))
		{
			i += si.r(a, b, l);	
		}
		else if (!cmp(s, 0, 1, desc) && cmp(s, 1, 2, desc))
		{
			i += si.s(a, b, l);	
		}
		return i;
}
