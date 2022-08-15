#include "solver.h"

//todo :: impl me

#include <string.h>

static int eval_instructions(t_stack *a, t_stack *b, t_list *ia, t_list *ib, t_list **l)
{
	int	i = 0;

	t_list	*it_a;
	t_list	*it_b;

	it_a = ia;
	it_b = ib;
	while (it_a || it_b)
	{
		if (it_a && it_b)
		{
			if (!strcmp(it_a->data, "sa") && !strcmp(it_b->data, "sb"))
			{
				i += ss(a, b, l);
				goto next;
			}
			else if (!strcmp(it_a->data, "ra") && !strcmp(it_b->data, "rb"))
			{
				i += rr(a, b, l);
				goto next;
			}
			else if (!strcmp(it_a->data, "rra") && !strcmp(it_b->data, "rrb"))
			{
				i += rrr(a, b, l);
				goto next;
			}
		}
		if (it_a)
		{

			if (!strcmp(it_a->data, "pa"))
				i += pa(a, b, l);
			else if (!strcmp(it_a->data, "sa"))
				i += sa(a, b, l);
			else if (!strcmp(it_a->data, "ra"))
				i += ra(a, b, l);
			else if (!strcmp(it_a->data, "rra"))
				i += rra(a, b, l);
		}

		if (it_b)
		{
			if (!strcmp(it_b->data, "pb"))
				i += pb(a, b, l);
			else if (!strcmp(it_b->data, "sb"))
				i += sb(a, b, l);
			else if (!strcmp(it_b->data, "rb"))
				i += rb(a, b, l);
			else if (!strcmp(it_b->data, "rrb"))
				i += rrb(a, b, l);
		}
next:
		if (it_a)
			it_a = it_a->next;
		if (it_b)
			it_b = it_b->next;
	}
	return (i);
}

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
	i = 0;
	c = 0;
	stack_clone(&ac, a);
	stack_order_asc(&ac);
	int p = ac.data[ac.size / 2];
	int	t = ac.size;
	while (c < t)
	{
		if (a->data[a->size - 1] < p)
			i += pb(a, b, l);
		else
			i += ra(a, b, l);
		c += 1;
	}
	c = 0;
	while (c < a->size/2)
	{
		i += rra(a, b, l);
		c += 1;
	}



	stack_clone(&ac, a);
	stack_order_asc(&ac);
	stack_clone(&bc, b);
	stack_order_desc(&bc);
	




	static int	mem_acc[ARG_MAX];
	t_stack		acc;
	static int	mem_bcc[ARG_MAX];
	t_stack		bcc;
	acc = stack_init(mem_acc);
	bcc = stack_init(mem_bcc);
	stack_clone(&acc, a);
	stack_clone(&bcc, b);
	t_list	*ia = 0;
	t_list	*ib = 0;
/*
	order_a(&acc, &bcc, &ac, &ia);
	order_b(&acc, &bcc, &bc, &ib);
**/


	bubble_sort_a(&acc, &bcc, &ia);
	bubble_sort_b(&acc, &bcc, &ib);
//	dd(&acc, &bcc, 0);

//	exit(0);
	i += eval_instructions(a, b, ia, ib, l);


	while (b->size)
	{
		index = find_index_rev(*a, b->data[b->size - 1]);

		if (index < a->size / 2)
			i += pa_at(a, b, l, index);
		else
			i += pa_at_rev(a, b, l, index);
	}
	return (i);
}
