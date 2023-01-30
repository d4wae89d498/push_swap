#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "list.h"
#include "stack.h"
#include "stdio.h"
#ifndef ARG_MAX
#define ARG_MAX 262144
#endif

typedef int (*t_instruction)(t_stack *a, t_stack *b, t_list **l);

/* common1.c */
int sa(t_stack *a, t_stack *b, t_list **i);
int sb(t_stack *a, t_stack *b, t_list **i);
int ss(t_stack *a, t_stack *b, t_list **i);
int pa(t_stack *a, t_stack *b, t_list **i);
int pb(t_stack *a, t_stack *b, t_list **i);
/* common2.c */
int ra(t_stack *a, t_stack *b, t_list **i);
int rb(t_stack *a, t_stack *b, t_list **i);
int rr(t_stack *a, t_stack *b, t_list **i);
/* common3.c */
int rra(t_stack *a, t_stack *b, t_list **i);
int rrb(t_stack *a, t_stack *b, t_list **i);
int rrr(t_stack *a, t_stack *b, t_list **i);
/* common4.c */
int da(t_stack *a, t_stack *b, t_list **i);
int db(t_stack *a, t_stack *b, t_list **i);
int dd(t_stack *a, t_stack *b, t_list **i);
int max(int a, int b);
t_stack parse(int ac, char **av, void *mem_a);
#endif
