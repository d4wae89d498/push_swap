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
/*
static void	solve(t_stack *a, t_stack *b)
{
	int	i;

	i = a->size - 1;
	while (i)
	{
		if (b->size && b->data[b->size - 1] <= a->data[i])
			pb(a, b);
		else 

		i -= 1;
	}
}
*/

void	do_top(t_stack *a, t_stack *b, int position, void(*instr)(t_stack*, t_stack *))
{
	int i;

	i = 0;
	while (i < position)
	{
		printf("rrb\n");
		rrb(a, b);
		i += 1;
	}
	instr(a, b);
	i = 0;
	while (i < position)
	{
		printf("rb\n");
		rrb(a, b);
		i += 1;
	}
}

void	do_bottom(t_stack *a, t_stack *b, int position, void(*instr)(t_stack*, t_stack *))
{
	int i;

	i = 0;
	while (i < position)
	{
		printf("rb\n");
		rrb(a, b);
		i += 1;
	}
	instr(a, b);
	i = 0;
	while (i < position)
	{
		printf("rrb\n");
		rrb(a, b);
		i += 1;
	}

}

void	insert(t_stack *a, t_stack *b)
{
	int	value;
	int	i;

	value = a->data[a->size - 1];


	i = 0;
	while (i < b->size)
	{
		if (value >= b->data[i])
			break ;
		i += 1;
	}

	if (i >= b->size / 2)
	{
		printf("Shall insert at index=%i, near from from top.\n", i);
		do_top(a, b, i, pb);
	}
	else 
	{
		printf("Shall insert at index=%i, near from from bottom.\n", i);
	}
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
	stack_push(&b, 15);
	stack_push(&b, 13);
	stack_push(&b, 7);
	stack_push(&b, 0);

//	pb(&a, &b);

	dd(&a, &b);
	insert(&a, &b);
	dd(&a, &b);
	//	solve(&a, &b);
//	dd(&a, &b);
}
