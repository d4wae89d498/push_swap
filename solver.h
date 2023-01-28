#ifndef SOLVER_H
# define SOLVER_H
# include "common.h"
# include "stdio.h"
# include "stdlib.h"



typedef struct
{
	t_instruction	rr;
	t_instruction	r;
	t_instruction	p;
	t_instruction	s;
}	t_stack_instructions;

/* abstrations */
int	find_index(t_stack s, int n);
int	find_index_rev(t_stack s, int n);
int	do_x(t_stack *a, t_stack *b, t_list **l, int n,
		int(*instr)(t_stack *a, t_stack *b, t_list **l));
int	pb_at(t_stack *a, t_stack *b, t_list **l, int n);
int	pb_at_rev(t_stack *a, t_stack *b, t_list **l, int n);
int	pa_at(t_stack *a, t_stack *b, t_list **l, int n);
int	pa_at_rev(t_stack *a, t_stack *b, t_list **l, int n);


int	sa_at(t_stack *a, t_stack *b, t_list **l, int x, int y, int vx, int vy);
int	sb_at(t_stack *a, t_stack *b, t_list **l, int x, int y, int vx, int vy);

int	order_a(t_stack *a, t_stack *b, t_stack *ac, t_list **l);
int	order_b(t_stack *a, t_stack *b, t_stack *bc, t_list **l);


int	find_index_rev(t_stack s, int n);


int	bubble_sort_a(t_stack *a, t_stack *b, t_list **l);

int	bubble_sort_b(t_stack *a, t_stack *b, t_list **l);

int	insertion_sort(t_stack *s, t_list **l, t_stack_instructions si, int desc);
int	swap_at(
		t_stack *a, 
		t_stack *b, 
		t_list **l, 
		int x, 
		int y, 
		int vx, 
		int vy, 
		t_stack *s, 
		t_stack_instructions si
);

int	is_sorted_asc(t_stack *s);
int	is_sorted_desc(t_stack *s);

int	is_sorted(t_stack *s, int desc);
int 	cmp(t_stack *s, int ix, int iy, int desc);
int		sort_tree(t_stack *a, t_stack *b, t_stack *s, t_list **l, t_stack_instructions si);
int		sort_five(t_stack *a, t_stack *b, t_stack *s, t_list **l, t_stack_instructions si);
/* strategies */

int		push_rotate(t_stack *a, t_stack *b, t_list **l);
int		split_swap(t_stack *a, t_stack *b, t_list **l);
int		radix(t_stack *a, t_stack *b, t_list **l);
int		bool_tree(t_stack *a, t_stack *b, t_list **l);
int		quick_sort(t_stack *a, t_stack *b, t_list **l);


int	sort_p(t_stack *a, t_stack *b, t_stack *s, t_list **l, t_stack_instructions si);
#endif
