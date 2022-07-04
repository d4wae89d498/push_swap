#ifndef COMMON_H
# define COMMON_H
# ifndef ARG_MAX
#  define ARG_MAX 262144 
# endif
# include "stack.h"

t_stack	parse(int ac, char **av);
typedef struct 
{
	const char	*label;
	void	(*instruction)(t_stack *a, t_stack *b);
} instruction;
instruction	g_instructions[255];
void	sa(t_stack *a, t_stack *b);
void	sb(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a, t_stack *b);
void	rb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, t_stack *b);
void	rrb(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
#endif
