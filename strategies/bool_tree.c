#include "solver.h"
#include "limits.h"

int		bool_tree_r(t_stack *s, t_list **l, t_possible_instructions pi, int depth);


int		try_s(t_stack *s, t_list **l, int depth)
{
	int		*mem_sc;
	t_stack	sc;
	int		i;

	(void) l;
	mem_sc = malloc(ARG_MAX * sizeof(int));
	sc = stack_init(mem_sc);
	stack_clone(&sc, s);
	i = 0;
	i += sa(&sc, 0, 0);
	i += bool_tree_r(&sc, 0, (t_possible_instructions){.s=0, .r=1, .rr=1}, depth + 1);
	free(mem_sc);
	return (is_sorted_asc(&sc) ? i : 0);
}

int		try_r(t_stack *s, t_list **l, int depth)
{
	int		*mem_sc;
	t_stack	sc;
	int		i;

	(void) l;
	mem_sc = malloc(ARG_MAX * sizeof(int));
	sc = stack_init(mem_sc);
	stack_clone(&sc, s);
	i = (ra(&sc, 0, 0));
	i += bool_tree_r(&sc, 0, (t_possible_instructions){.s=1, .r=1, .rr=0}, depth + 1);
	free(mem_sc);
	return (is_sorted_asc(&sc) ? i : 0);
}

int		try_rr(t_stack *s, t_list **l, int depth)
{
	int		*mem_sc;
	t_stack	sc;
	int		i;


	(void) l;
	mem_sc = malloc(ARG_MAX * sizeof(int));
	sc = stack_init(mem_sc);
	stack_clone(&sc, s);
	i = (rra(&sc, 0, 0));
	i += bool_tree_r(&sc, 0, (t_possible_instructions){.s=1, .r=0, .rr=1}, depth + 1);
	free(mem_sc);
	return (is_sorted_asc(&sc) ? i : 0);
}


char bool_tree_c(t_stack *s, t_list **l, t_possible_instructions pi,
			int depth);

int		bool_tree_r(t_stack *s, t_list **l, t_possible_instructions pi, int depth)
{
	int	c;

	if (depth > 10)
		return 0;
	if (is_sorted_asc(s))
		return 0;
	c = bool_tree_c(s, l, pi, depth);
	if (c == 's')
		return (sa(s, 0, l) + bool_tree_r(s, l, (t_possible_instructions) {.s=0, .r=1, .rr=1}, depth + 1));
	
	if (c == 'r')
		return (ra(s, 0, l) + bool_tree_r(s, l, (t_possible_instructions) {.s=1, .r=1, .rr=0}, depth + 1));
	
	if (c == 'i')
		return (rra(s, 0, l) + bool_tree_r(s, l, (t_possible_instructions) {.s=1, .r=0, .rr=1}, depth + 1));
	

	return (0);
}

int	bool_tree(t_stack *a, t_stack *b, t_list **l)
{
	int	i;

	(void) b;
	i = 0;
	i += bool_tree_r(a, l, (t_possible_instructions) {.s=1, .r=1, .rr=1} , 0);
	return (i);
}

