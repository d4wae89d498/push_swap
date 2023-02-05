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

	if (!strcmp(str, "pb"))
		i += pb(a, b, l);
	else if (!strcmp(str, "sb"))
		i += sb(a, b, l);
	else if (!strcmp(str, "rb"))
		i += rb(a, b, l);
	else if (!strcmp(str, "rrb"))
		i += rrb(a, b, l);
	return (i);
}

void	next(t_list **it_a, t_list **it_b)
{
		if (*it_a)
			*it_a = (*it_a)->next;
		if (*it_b)
			*it_b = (*it_b)->next;
}

int	try_simple(t_stack *a, t_stack *b, t_list **it_a, t_list **it_b, t_list **l)
{
	if (!strcmp((*it_a)->data, "sa") && !strcmp((*it_b)->data, "sb"))
		ss(a, b, l);
	else if (!strcmp((*it_a)->data, "ra") && !strcmp((*it_b)->data, "rb"))
		rr(a, b, l);
	else if (!strcmp((*it_a)->data, "rra") && !strcmp((*it_b)->data, "rrb"))
		rrr(a, b, l);
	else
		return (0);
	return (1);
}

int try_next_a()
{
	return (0);
}

int try_next_b(t_stack *a, t_stack *b, t_list **it_a, t_list **it_b, t_list **l)
{
	int i;

	i = 0;
	if (!strcmp((*it_a)->data, "sa") && !strcmp((*it_b)->next->data, "sb"))
	{
		i += eval_b(a, b, l, (*it_b)->data);
		i += ss(a, b, l);
		(*it_b) = (*it_b)->next;
	}
	else if (!strcmp((*it_a)->data, "ra") && !strcmp((*it_b)->next->data, "rb"))
	{
		i += eval_b(a, b, l, (*it_b)->data);
		i += rr(a, b, l);
		(*it_b) = (*it_b)->next;
	}
	else if (!strcmp((*it_a)->data, "rra") && !strcmp((*it_b)->next->data, "rrb"))
	{
		i += eval_b(a, b, l, (*it_b)->data);
		i += rrr(a, b, l);
		(*it_b) = (*it_b)->next;
	}
	return (i);
}

int	merge_instructions(t_stack *a, t_stack *b, t_list *ia, t_list *ib, t_list **l)
{
	int		i;
	int		s;
	t_list	*it_a;
	t_list	*it_b;

	i = 0;
	s = 0;
	it_a = ia;
	it_b = ib;
	while (it_a || it_b)
	{
		s = 0;
		if (it_a && it_b)
		{
			s = 1;
			if (try_simple(a, b, &it_a, &it_b, l))
				;
			else if (it_b->next && try_next_b(a, b, &it_a, &it_b, l))
				;
			else if (it_a->next)
			{
				if (!strcmp(it_a->next->data, "sa") && !strcmp(it_b->data, "sb"))
				{
					i += eval_a(a, b, l, it_a->data);
					i += ss(a, b, l);
					it_a = it_a->next;
				}
				else if (!strcmp(it_a->next->data, "ra") && !strcmp(it_b->data, "rb"))
				{
					i += eval_a(a, b, l, it_a->data);
					i += rr(a, b, l);
					it_a = it_a->next;
				}
				else if (!strcmp(it_a->next->data, "rra") && !strcmp(it_b->data, "rrb"))
				{
					i += eval_a(a, b, l, it_a->data);
					i += rrr(a, b, l);
					it_a = it_a->next;
				}
				else
					s = 0;
			}
			else
				s = 0;
		}
		if (!s)
		{
			if (it_a)
				i += eval_a(a, b, l, it_a->data);
			if (it_b)
				i += eval_b(a, b, l, it_b->data);
		}
		next(&it_a, &it_b);
	}
	return (i);
}

static int	split_swap_init(t_stack *a, t_stack *b, t_list **l)
{

	int			c;
	static int	mem_ac[ARG_MAX];
	t_stack		ac;
	int			p;
	int			t;

	c = 0;
	ac = stack_init(mem_ac);
	stack_clone(&ac, a);
	stack_order_asc(&ac);
	p = ac.data[ac.size / 2];
	t  = ac.size;
	while (c < t)
	{
		if (a->data[a->size - 1] < p)
			pb(a, b, l);
		else
			ra(a, b, l);
		c += 1;
	}
	return (0);
}

static int	split_swap_end(t_stack *a, t_stack *b, t_list **l)
{
	int		mem_ac[ARG_MAX];
	t_stack	ac;
	int		mem_bc[ARG_MAX];
	t_stack	bc;
	t_list	*ia;
	t_list	*ib;
	int		i;

	ac = stack_init(mem_ac);
	stack_clone(&ac, a);
	bc = stack_init(mem_bc);
	stack_clone(&bc, b);
	i = 0;
	ia = 0;
	ib = 0;
	insertion_sort(&ac, &ia, 
			(t_stack_instructions) {
			.r=ra, 
			.rr=rra, 
			.p=pa, 
			.s=sa
		}, 0);
	insertion_sort(&bc, &ib, 
			(t_stack_instructions) {
			.r=rb, 
			.rr=rrb, 
			.p=pb, 
			.s=sb
		}, 1);
	i += merge_instructions(a, b, ia, ib, l);
	while (b->size)
		i += pa(a, b, l);
	return (i);
}

int	split_swap(t_stack *a, t_stack *b, t_list **l)
{
	int			i;

	if (is_sorted(a, 0))
		return (0);	
	i = 0;
	i += split_swap_init(a, b, l);
	return (i + split_swap_end(a, b, l));
}
