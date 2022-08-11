#include "solver.h"
#include "common.h"

int	find_index(t_stack s, int n)
{
	int	i;

	i = 0;
	while (i < s.size)
	{
		if (s.data[i] >= n)
			break ;
		i += 1;
	}
	return i;
}

void	do_x(t_stack *a, t_stack *b, int n, void(*instr)(t_stack *a, t_stack *b))
{
	while (n)
	{
		instr(a, b);
		n -= 1;
	}
}

void	pa_at(t_stack *a, t_stack *b, int n)
{
	if (!a->size)
	{
		pa(a, b);
		return ;
	}
	do_x(a, b, n, rra);
	pa(a, b);
	do_x(a, b, n + 1, ra);
}

void	pa_at_rev(t_stack *a, t_stack *b, int n)
{
	if (!a->size)
	{
		pa(a, b);
		return ;
	}
	n = a->size - n;
	do_x(a, b, n + 1, ra);
	pa(a, b);
	do_x(a, b, n, rra);
}

void	pb_at(t_stack *a, t_stack *b, int n)
{
	if (!b->size)
	{
		pb(a, b);
		return ;
	}
	do_x(a, b, n, rrb);
	pb(a, b);
	do_x(a, b, n + 1, rb);
}



void	pb_at_rev(t_stack *a, t_stack *b, int n)
{
	if (!b->size)
	{
		pb(a, b);
		return ;
	}
	n = b->size - n;
	do_x(a, b, n + 1, rb);
	pb(a, b);
	do_x(a, b, n, rrb);
}

int	main(int ac, char **av)
{
	static int	mem_a[ARG_MAX];
	t_stack		a;
	static int	mem_b[ARG_MAX];
	t_stack		b;


	a = parse(ac, av, mem_a);
	b = stack_init(mem_b);
	while (a.size)
	{
	//	printf("---------\n");
	//	dd(&a, &b);
		pb_at(&a, &b, find_index(b, a.data[a.size - 1]));
	}
//	pa_at_rev_test(&a, &b, 0);
	while (b.size)
	{
		pa(&a, &b);
	}

//	dd(&a, &b);
}
