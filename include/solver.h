#ifndef SOLVER_H
# define SOLVER_H
# include "common.h"
# include "stdio.h"
# include "stdlib.h"

/* abstrations */
int	find_index(t_stack s, int n);
int	do_x(t_stack *a, t_stack *b, t_list **l, int n,
		int(*instr)(t_stack *a, t_stack *b, t_list **l));
int	pb_at(t_stack *a, t_stack *b, t_list **l, int n);
/* strategies */
int		push_rotate(t_stack *a, t_stack *b, t_list **l);

#endif
