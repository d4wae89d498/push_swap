#ifndef SOLVER_H
# define SOLVER_H
# include "common.h"
# include "stdio.h"
# include "stdlib.h"

/* abstrations */
int	find_index(t_stack s, int n);
int	find_index_rev(t_stack s, int n);
int	do_x(t_stack *a, t_stack *b, t_list **l, int n,
		int(*instr)(t_stack *a, t_stack *b, t_list **l));
int	pb_at(t_stack *a, t_stack *b, t_list **l, int n);
int	pb_at_rev(t_stack *a, t_stack *b, t_list **l, int n);
int	pa_at(t_stack *a, t_stack *b, t_list **l, int n);
int	pa_at_rev(t_stack *a, t_stack *b, t_list **l, int n);


int	sa_at(t_stack *s, t_list **l, int x, int y, int vx, int vy);
int	sb_at(t_stack *s, t_list **l, int x, int y, int vx, int vy);

int	order_a(t_stack *a, t_stack *ac, t_list **l);
int	order_b(t_stack *b, t_stack *bc, t_list **l);


int	find_index_rev(t_stack s, int n);
/* strategies */

int		push_rotate(t_stack *a, t_stack *b, t_list **l);
int		split_swap(t_stack *a, t_stack *b, t_list **l);

#endif
