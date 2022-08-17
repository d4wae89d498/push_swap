#include "solver.h"

//todo :: impl me

#include <string.h>

int	eval_a(t_stack *a, t_stack *b, t_list **l, char *str)
{
	int i = 0;

	if (!strcmp(str, "pa"))
		i += pa(a, b, l);
	else if (!strcmp(str, "sa"))
		i += sa(a, b, l);
	else if (!strcmp(str, "ra"))
		i += ra(a, b, l);
	else if (!strcmp(str, "rra"))
		i += rra(a, b, l);
	return (i);
}

int	eval_b(t_stack *a, t_stack *b, t_list **l, char *str)
{
	int i = 0;

	if (!strcmp(str, "pn"))
		i += pb(a, b, l);
	else if (!strcmp(str, "sb"))
		i += sb(a, b, l);
	else if (!strcmp(str, "rb"))
		i += rb(a, b, l);
	else if (!strcmp(str, "rrb"))
		i += rrb(a, b, l);
	return (i);
}

int	apply_reverse_order_opt(t_list **l)
{
	t_list	*it;
	

	it = *l;
	while (it)
	{
		it = it->next;
	}
	return (0);
}

static int	merge_instructions(t_stack *a, t_stack *b, t_list *ia, t_list *ib, t_list **l)
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
			else if (it_b->next)
			{
				if (!strcmp(it_a->data, "sa") && !strcmp(it_b->next->data, "sb"))
				{
					i += eval_b(a, b, l, it_b->data);
					i += ss(a, b, l);
					it_b = it_b->next;
					goto next;
				}
				else if (!strcmp(it_a->data, "ra") && !strcmp(it_b->next->data, "rb"))
				{
					i += eval_b(a, b, l, it_b->data);
					i += rr(a, b, l);
					it_b = it_b->next;
					goto next;
				}
				else if (!strcmp(it_a->data, "rra") && !strcmp(it_b->next->data, "rrb"))
				{
					i += eval_b(a, b, l, it_b->data);
					i += rrr(a, b, l);
					it_b = it_b->next;
					goto next;
				}
			}
			else if (it_a->next)
			{
				if (!strcmp(it_a->next->data, "sa") && !strcmp(it_b->data, "sb"))
				{
					i += eval_a(a, b, l, it_a->data);
					i += ss(a, b, l);
					it_a = it_a->next;
					goto next;
				}
				else if (!strcmp(it_a->next->data, "ra") && !strcmp(it_b->data, "rb"))
				{
					i += eval_a(a, b, l, it_a->data);
					i += rr(a, b, l);
					it_a = it_a->next;
					goto next;
				}
				else if (!strcmp(it_a->next->data, "rra") && !strcmp(it_b->data, "rrb"))
				{
					i += eval_a(a, b, l, it_a->data);
					i += rrr(a, b, l);
					it_a = it_a->next;
					goto next;
				}
			} 
		}
		if (it_a)
		{
			i += eval_a(a, b, l, it_a->data);
		}

		if (it_b)
		{
			i += eval_b(a, b, l, it_b->data);
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
	
/*	i += insertion_sort(a, l, 
			(t_stack_instructions) {
			.r=ra, 
			.rr=rra, 
			.p=pa, 
			.s=sa
		}, 0);*/
	//sort_five(a, b, a, l, (t_stack_instructions) {.r=ra, .rr=rra, .s=sa, .p=pa});
//	dd(a, b, 0);
//	exit(0);
	if (is_sorted(a, 0))
		return (i);	

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
/*	c = 0;
	while (c < a->size/2)
	{
		i += rra(a, b, l);
		c += 1;
	}
*/


	stack_clone(&ac, a);
	stack_order_asc(&ac);
	stack_clone(&bc, b);
	stack_order_desc(&bc);

	(void) index;



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

*/



	
//	bubble_sort_a(&acc, &bcc, &ia);
//	bubble_sort_b(&acc, &bcc, &ib);

	insertion_sort(&acc, &ia, 
			(t_stack_instructions) {
			.r=ra, 
			.rr=rra, 
			.p=pa, 
			.s=sa
		}, 0);
	

	insertion_sort(&bcc, &ib, 
			(t_stack_instructions) {
			.r=rb, 
			.rr=rrb, 
			.p=pb, 
			.s=sb
		}, 1);

	i += merge_instructions(a, b, ia, ib, l);

//	dd(a, b, 0);

//		exit(0);

	while (b->size)
	{
		i += pa(a, b, l);
/*
		index = find_index_rev(*a, b->data[b->size - 1]);

		if (index < a->size / 2)
			i += pa_at(a, b, l, index);
		else
			i += pa_at_rev(a, b, l, index);*/
	}
	return (i);
}
