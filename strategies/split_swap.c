#include "solver.h"

int	split_swap(t_stack *a, t_stack *b, t_list **l)
{
	int		index;
	int	c;
	int	i;
	static int	mem_bc[ARG_MAX];
	t_stack		bc;
	static int	mem_ac[ARG_MAX];
	t_stack		ac;

	bc = stack_init(mem_bc);
	ac = stack_init(mem_ac);
	dd(a, b, 0);
	i = 0;
	c = a->size / 2;
	while (c)
	{
		i += pb(a, b, l);
		c -= 1;
//		dd(a, b, 0);
	}


	// TODO :: CLONE STACKS AND FIND OPTIMAL SWAPS
	stack_clone(&ac, a);
	stack_order_asc(&ac);


	stack_clone(&bc, b);
	stack_order_asc(&bc);


	order_a(a, b, &ac, l);


	order_b(a, b, &bc, l);


	printf("________________\n");
	printf("dd:\n");
	dd(a, b, 0);
	printf("---------====----==-=-=\n");
/*
	while (1)
	{
		ia = order_a(a, &ac);
		ib = order_b(b, &bc);
	
		if (ia == sa && ib == sb)
			ss(a, b, l);
		else if (ia == ra && ib == rb)
			rr(a, b, l);
		else if (ia == rra && ib == rrb)
			rrr(a, b, l);
		else
		{
			if (ia)
				ia(a, b, l);
			if (ib)
				ib(a, b, l);
		}
		if (!ia && !ib)
		{
			printf("END\n");
				break ;
		}

	}*/
/*	printf("FINAL::\n");

	dd(a, b, 0);

	exit(0);*/
/*
	stack_clone(&bc, b);
	stack_order_desc(&bc);


	order_b(a, &ac, l);*/

		//dd(&ac, &bc, 0);

	while (b->size)
	{
		index = find_index_rev(*a, b->data[b->size - 1]);
	
		if (index < a->size / 2)
			i += pa_at(a, b, l, index);
		else
			i += pa_at_rev(a, b, l, index);
		//break ;
		//i += pa(a, b, l);
	}

	dd(a, b, 0);
	exit(0);
	return (i);
}
