#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"
# include "stdio.h"
# ifndef ARG_MAX
#  define ARG_MAX 262144
# endif
/* common1.c */
void	sa(t_stack *a, t_stack *b);
void	sb(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
/* common2.c */
void	ra(t_stack *a, t_stack *b);
void	rb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
/* common3.c */
void	rra(t_stack *a, t_stack *b);
void	rrb(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
/* common4.c */
void	da(t_stack *a, t_stack *b);
void	db(t_stack *a, t_stack *b);
void	dd(t_stack *a, t_stack *b);
int	max(int a, int b);
t_stack	parse(int ac, char **av, void *mem_a);
#endif
