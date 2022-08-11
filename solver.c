#include "solver.h"

static int ft_atoi(char *s)
{
	int	o;
	int	sign;

	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s += 1;
	}
	else if (*s == '+')
		s += 1;
	o = 0;
	while (*s >= '0' && *s <= '9')
	{
		o *= 10;
		o += *s - '0';
		s += 1;
	}
	if (*s)
	{
		printf("error\n");
		exit(0);
	}
	return (o * sign);
}

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

void	compile(int ac, char **av)
{
	int		i;
	static int	mem_a[ARG_MAX];
	t_stack		a;
	static int	mem_b[ARG_MAX];
	t_stack		b;

	if (ac < 2)
		return ;
	a = stack_init(mem_a);
	b = stack_init(mem_b);
	ac -= 1;
	av += 1;
	i = 0;
	while (i < ac)
	{
		stack_push(&a, ft_atoi(av[i]));
		i += 1;
	}
	while (a.size)
	{
		pb_at(&a, &b, find_index(b, a.data[a.size - 1]));
	}
//	pa_at_rev_test(&a, &b, 0);
	while (b.size)
	{
		pa(&a, &b);
	}

//	dd(&a, &b);
}
