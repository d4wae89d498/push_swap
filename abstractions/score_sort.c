#include "solver.h"

/*
int	count_score_left(t_stack *s, int desc, t_stack_instructions si)
{
	t_stack		sc;
	static int	mem_sc[ARG_MAX];
	int			score;

	sc = stack_init(mem_sc);
	stack_clone(&sc, s);
	score = 0;
	if (desc)
	{
		while (sc.data[0] < sc.data[sc.size - 1] && score < sc.size)
		{
			si.rr(s, s, l);
			si.s(s, s, l);
			score += 1;
		}
	}
	else
	{
		while (s.data[0] > s.data[sc.size - 1] && score < sc.size)
		{
			si.rr(s, s, l);
			si.s(s, s, l);
			score += 1;
		}
	}
	return (score);
}

int	count_score_right(t_stack *s, int desc)
{
	t_stack		sc;
	static int	mem_sc[ARG_MAX];
	int			score;

	sc = stack_init(mem_sc);
	stack_clone(&sc, s);
	score = 0;
	if (desc)
	{
		while (sc.data[sc.size - 1] < sc.data[sc.size - 2] && score < sc.size)
		{
			si.s(s, s, l);
			si.r(s, s, l);
			score += 1;
		}
	}
	else
	{
		while (s.data[sc.size - 1] > s.data[sc.size - 2] && score < sc.size)
		{
			si.s(s, s, l);
			si.r(s, s, l);
			score += 1;
		}
	}
	return (score);
}

int	find_best_direction()
{

}

int	score_sort(t_stack *s, int desc, t_stack_instructions si)
{
	int	l;
	int	r;
	int	i;

	i = 0;
	l = count_score_left(s, desc, si);
	r = count_score_right(s, desc, si);
	return (i);
}*/
