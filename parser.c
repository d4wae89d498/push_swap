#include "common.h"

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
	i = ac;
	while (i)
	{
		i -= 1;
		stack_push(&o, ft_atoi(av[i]));
	}
	return (o);
}
