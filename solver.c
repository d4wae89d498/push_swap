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

/*
 *	1) Parse av into stack a
 *	2) Check if stack a is already ordered, if so exit
 *	3) Init stack b
 *	4) Check if a stack a is small, if so apply small orders algo and exit
 *	5) Apply long sort algos
 *
 */ 
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
	
	dd(&a, &b, 0);
	instructions = 0;


/*	if (ac == 4)
	{
		sort_tree(&a, &b, &a, &instructions, (t_stack_instructions) {
			.rr=rra,
			.r=ra,
			.p=pa,
			.s=sa
		});
	}*/
	if (ac <= 6)
	{
		ic = bool_tree(&a, &b, &instructions);
	}
	else if (ac <= 26)//ac <= 10)
	{
		//ic = push_rotate(&a, &b, &instructions);
		ic = split_swap(&a, &b, &instructions);
	}
	else 
	{
			ic = radix(&a, &b, &instructions);
		//	ic = quick_sort(&a, &b, &instructions);
	}


	list_iter(&instructions, (void*) putstr);
	list_free(&instructions);

	dd(&a, &b, 0);
	return (0);
}
