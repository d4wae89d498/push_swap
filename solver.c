#include "solver.h"
#include "unistd.h"

static void	putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i += 1;
	write(1, str, i);
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	static int	mem_a[ARG_MAX];
	t_stack		a;
	static int	mem_b[ARG_MAX];
	t_stack		b;

	t_list		*instructions;

	int			ic;

	a = parse(ac, av, mem_a);
	b = stack_init(mem_b);
	instructions = 0;

	ic = push_rotate(&a, &b, &instructions);
	list_iter(&instructions, (void*) putstr);
	list_free(&instructions);
	return (0);
}
