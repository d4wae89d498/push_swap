#include "solver.h"
#include "limits.h"


typedef struct
{
	int	s:	1;
	int	r:	1;
	int	rr:	1;
}	t_possible_instructions;

int		bool_tree_r(t_stack *s, t_list **l, t_possible_instructions pi, int depth);

int		count_ordered(t_stack *s)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (i < s->size - 1)
	{
		if (s->data[s->size - 1 - i] < s->data[s->size - 2 - i])
			y += 1;
		i += 1;
	}
	y += 1;
	printf("score: %i\n", y);
	return (y);
}

int		try_s(t_stack *s, t_list **l, int depth)
{
	int		*mem_sc;
	t_stack	sc;
	int		i;

	printf("s [depth %i]\n", depth);
	(void) l;
	mem_sc = malloc(ARG_MAX * sizeof(int));
	sc = stack_init(mem_sc);
	stack_clone(&sc, s);
	i = 0;
	i += sa(&sc, 0, 0);
	i += bool_tree_r(&sc, 0, (t_possible_instructions){.s=0, .r=1, .rr=1}, depth + 1);
//	i = (count_ordered(&sc));
	free(mem_sc);
	return (i);
}

int		try_r(t_stack *s, t_list **l, int depth)
{
	int		*mem_sc;
	t_stack	sc;
	int		i;

	printf("r [depth %i]\n", depth);
	(void) l;
	mem_sc = malloc(ARG_MAX * sizeof(int));
	sc = stack_init(mem_sc);
	stack_clone(&sc, s);
	i = (ra(&sc, 0, 0) + bool_tree_r(&sc, 0, (t_possible_instructions){.s=1, .r=1, .rr=0}, depth + 1));
//	i = (count_ordered(&sc));
	free(mem_sc);
	return (i);
}

int		try_rr(t_stack *s, t_list **l, int depth)
{
	int		*mem_sc;
	t_stack	sc;
	int		i;


	printf("rr [depth %i]\n", depth);
	(void) l;
	mem_sc = malloc(ARG_MAX * sizeof(int));
	sc = stack_init(mem_sc);
	stack_clone(&sc, s);
	i = (rra(&sc, 0, 0) + bool_tree_r(&sc, 0, (t_possible_instructions){.s=1, .r=0, .rr=1}, depth + 1));
//	i = (count_ordered(&sc));
	free(mem_sc);
	return (i);
}

int		bool_tree_r(t_stack *s, t_list **l, t_possible_instructions pi, int depth)
{
	int	max_ordered;
	int	max_ordered_tmp;
	char	c;
	int			i;
	static int	pp;

	if (++pp > 10)
	{
	//	printf("MAX DEPTH!!\n");
		return (SHRT_MAX / 2);
	}

	max_ordered = SHRT_MAX / 4;
		max_ordered_tmp = 0;
	c = 0;

	printf("sorted=%i:\n", is_sorted_asc(s));
	da(s, 0, 0);

	if (is_sorted_asc(s))
		return (- (SHRT_MAX / 2));
	i = 0;
	if (s->data[s->size - 1] > s->data[s->size - 2])
	{
		i += sa(s, 0, l);
		pi.s = 0;
		pi.r = 1;
		pi.rr = 1;
	}

//========
// T R Y
// =======
	if (l)
		printf("%c (%x) %i %i %i [%i]\n", c, c, pi.s, pi.r, pi.rr, max_ordered);
	
	if (pi.s)
	{
		max_ordered_tmp = try_s(s, l, depth + 1);
		if (l)
			printf("try_s [%i]\n", max_ordered_tmp);
		if (max_ordered_tmp < max_ordered)
		{
			if (l)
				printf("OK\n");
			c = 's';
			max_ordered = max_ordered_tmp;
		}
	}
	if (pi.r)
	{
		max_ordered_tmp = try_r(s, l, depth + 1);
		if (l)
			printf("try_r ... %i ... \n", max_ordered_tmp);
		if (max_ordered_tmp < max_ordered)
		{
			if (l)
				printf("OK\n");
			c = 'r';
			max_ordered = max_ordered_tmp;
		}
	}
	if (pi.rr)
	{
		max_ordered_tmp = try_rr(s, l, depth + 1);
		if (l)
			printf("try_rr ... %i ... \n", max_ordered_tmp);
		if (max_ordered_tmp < max_ordered)
		{
			if (l)
				printf("OK\n");
			c = 'i';
			max_ordered = max_ordered_tmp;
		}
	}
//========
// T H I N K
// =======
//
	if (l)
		printf("%c (%x) %i %i %i\n", c, c, pi.s, pi.r, pi.rr);
	if (c == 's')
	{
		if (l)
			printf("--sa %i %i\n", max_ordered, max_ordered_tmp);
		return (i + sa(s, 0, l) + bool_tree_r(s, l, (t_possible_instructions) {.s=0, .r=1, .rr=1}, depth));
	}
	if (c == 'r')
	{
		if (l)
			printf("--ra %i %i\n", max_ordered, max_ordered_tmp);
		return (i + ra(s, 0, l) + bool_tree_r(s, l, (t_possible_instructions) {.s=1, .r=1, .rr=0}, depth));
	}
	if (c == 'i')
	{
		if (l)
			printf("--rra %i %i\n", max_ordered, max_ordered_tmp);
		return (i + rra(s, 0, l) + bool_tree_r(s, l, (t_possible_instructions) {.s=1, .r=0, .rr=1}, depth));
	}

	return (SHRT_MAX / 2);
}

int	bool_tree(t_stack *a, t_stack *b, t_list **l)
{
	int	i;

	(void) b;
	i = 0;
	i += bool_tree_r(a, l, (t_possible_instructions) {.s=0, .r=1, .rr=1} , 0);
	dd (a, b, l);
	exit(0);
	return (i);
}

