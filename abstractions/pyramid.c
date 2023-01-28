#include "solver.h"

static t_stack build_stage(t_stack s, int desc)
{
	int 		y;
	t_stack 	o;
	
	o.size = s.size - 1;
	o.data = malloc(o.size * sizeof(int));

	y = 0;
	while (y < o.size)
	{
		if (cmp(&s, y, y + 1, desc))
			o.data[y] = s.data[y] + s.data[y + 1];
		else
			o.data[y] = 0;
		y += 1;
	}

	return o;
}

static int	count_non_null(t_stack s)
{
	int	i;
	int	o;

	o = 0;
	i = 0;
	while (i < s.size)
	{
		if (s.data[i])
			o += 1;
		i += 1;
	}
	return o;
}

static int	index_non_null(t_stack s)
{
	int	i;
	int	o;

	o = 0;
	i = 0;
	while (i < s.size)
	{
		if (s.data[i])
			break ;
		i += 1;
	}
	return i;
}

static int sort_p_once(t_stack *a, t_stack *b, t_stack *s, t_list **l, t_stack_instructions si, int desc)
{
	int		y;
	t_stack	new_s;
	t_stack stages[s->size];
	int 	stage;	

	(void) a;
	(void) b;
	(void) l;
	(void) si;


	new_s.size = s->size;
	new_s.data = malloc( new_s.size * sizeof(int) );

	y = 0;
	while (y < new_s.size)
	{
		new_s.data[y] = s->data[y - 1];
		y += 1;
	}
//	new_s.data[0] = s->data[s->size - 1];
// stage = 1
	stage = 0;
	stages[stage] = build_stage(new_s, desc);
	while (stage < s->size)
	{
		da(&stages[stage], 0, 0);

	//	(void) count_non_null;
		if (count_non_null(stages[stage]) == 1)
	//	if (stage == s->size - 1)
			break ;
		stage += 1;
		stages[stage] = build_stage(stages[stage - 1], desc);
	}
	
	if (!stage)
	{
		printf("NO STAGE!\n");
		return si.rr(a, b, l);
	}


	if (stages[stage - 1].data[stages[stage-1].size - 1])
	{
		// top
		printf("top\n");
		return si.s(a, b, l);
	//	printf("top\n");

	}
//	printf("%i %i\n", index_non_null(stages[stage]), stages[stage - 1].data[ index_non_null(stages[stage]) ]);
	if (!stages[stage - 1].data[ index_non_null(stages[stage])  ])
		return si.r(a, b, l);
	return si.rr(a, b, l);
/*
	if (stages[stage - 1][0])
	{
		// left
	}
	if (stages[stage - 1][stages[stage - 1].size - 1])
	{
		// right
	}
   
	return i;*/
}


int	sort_p(t_stack *a, t_stack *b, t_stack *s, t_list **l, t_stack_instructions si)
{
	int	i;
	int desc;

	static int z = 0;

	i = 0;
	desc = s == b;
	while (!is_sorted(s, desc))
	{
		i += sort_p_once(a, b, s, l, si, desc);
	
		da(s, 0, 0);
//		printf("\n\n\n");

		if (++z >= 10)
			break ;
	}
	return i;
}
