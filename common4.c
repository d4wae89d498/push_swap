#include "common.h"
#include "stdlib.h"

int	max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void	da(t_stack *a, t_stack *b)
{	
	(void) b;
	stack_dump(*a);
}

void	db(t_stack *a, t_stack *b)
{
	(void)a;
	stack_dump(*b);
}

#include <stdio.h>
void	dd(t_stack *a, t_stack *b)
{
	int	i;

	i = max(a->size, b->size);
	while (i)
	{
		i -= 1;
		printf("[%i]", i);
		if (i < a->size)
			printf("\t%i", a->data[i]);
		else
			printf("\t");
		if (i < b->size)
			printf("\t%i", b->data[i]);
		else
			printf("\t");
		printf("\n");
	}
	printf("   \t-\t-\n");
	printf("   \ta\tb\n-----------------------------------\n");
}

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

t_stack	parse(int ac, char **av, void *mem_a)
{
	t_stack		o;
	int			i;

	if (ac < 2)
	{
		exit (0);
	}
	o = stack_init(mem_a);
	ac -= 1;
	av += 1;
	i = 0;
	while (i < ac)
	{
		stack_push(&o, ft_atoi(av[i]));
		i += 1;
	}
	return (o);
}
