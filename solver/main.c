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


void	pb_at(t_stack *a, t_stack *b, int n)
{
	if (!b->size)
	{
		pb(a, b);
		return ;
	}
	if (n == b->size)
	{
		pb(a, b);
		return ;
	}
	do_x(a, b, n, rrb);
	pb(a, b);
	do_x(a, b, n + 1, rb);
}

int	main(int ac, char **av)
{
	static int	mem_a[ARG_MAX];
	t_stack		a;
	static int	mem_b[ARG_MAX];
	t_stack		b;

	int			i;

	a = parse(ac, av, mem_a);
	b = stack_init(mem_b);

/*
	dd(&a, &b);

	ra(&a, &b);

	dd(&a, &b);
*/
	i = 0;
	while (a.size)
	{
 		i = find_index(b, a.data[a.size - 1]);
//		printf("pb_at i=%i\n", i);
		pb_at(&a, &b,i);
//		dd(&a, &b);
	}
	while (b.size)
	{
		pa(&a, &b);
	}
//	dd(&a, &b);
}
