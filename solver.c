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
	int			y;

	a = parse(ac, av, mem_a);
	if (a.size == 1)
		exit(0);
	y = 0;
	while (y < a.size - 1)
	{
		if (a.data[y + 1] >a.data[y])
			break ;
		y += 1;
	}
	if (y == a.size - 1)
		exit(0);
	b = stack_init(mem_b);
	instructions = 0;
//	ic = push_rotate(&a, &b, &instructions);
	ic = split_swap(&a, &b, &instructions);
//	ic = radix(&a, &b, &instructions);
	list_iter(&instructions, (void*) putstr);
	list_free(&instructions);

	dd(&a, &b, 0);
	return (0);
}
