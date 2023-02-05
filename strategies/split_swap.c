/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:57:10 by mafaussu          #+#    #+#             */
/*   Updated: 2023/02/03 14:57:36 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int	eval_a(t_stack *a, t_stack *b, t_list **l, char *str)
{
	int	i;

	i = 0;
	if (!ft_strcmp(str, "pa"))
		i += pa(a, b, l);
	else if (!ft_strcmp(str, "sa"))
		i += sa(a, b, l);
	else if (!ft_strcmp(str, "ra"))
		i += ra(a, b, l);
	else if (!ft_strcmp(str, "rra"))
		i += rra(a, b, l);
	return (i);
}

int	eval_b(t_stack *a, t_stack *b, t_list **l, char *str)
{
	int	i;

	i = 0;
	if (!ft_strcmp(str, "pb"))
		i += pb(a, b, l);
	else if (!ft_strcmp(str, "sb"))
		i += sb(a, b, l);
	else if (!ft_strcmp(str, "rb"))
		i += rb(a, b, l);
	else if (!ft_strcmp(str, "rrb"))
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

static int	split_swap_end(t_stack *a, t_stack *b, t_list **l)
{
	t_m	m;

	m.ac = stack_init(m.mem_ac);
	stack_clone(&(m.ac), a);
	m.bc = stack_init(m.mem_bc);
	stack_clone(&(m.bc), b);
	m.ia = 0;
	m.ib = 0;
	insertion_sort(&(m.ac), &(m.ia), (t_stack_instructions){
		.r = ra,
		.rr = rra,
		.p = pa,
		.s = sa
	}, 0);
	insertion_sort(&(m.bc), &(m.ib), (t_stack_instructions){
		.r = rb,
		.rr = rrb,
		.p = pb,
		.s = sb
	}, 1);
	merge_instructions((t_s2l3){a, b, &(m.ia), &(m.ib), l});
	while (b->size)
		pa(a, b, l);
	return (1);
}

int	split_swap(t_stack *a, t_stack *b, t_list **l)
{
	int			c;
	static int	mem_ac[ARG_MAX];
	t_stack		ac;
	int			p;
	int			t;

	if (is_sorted(a, 0))
		return (0);
	c = 0;
	ac = stack_init(mem_ac);
	stack_clone(&ac, a);
	stack_order_asc(&ac);
	p = ac.data[ac.size / 2];
	t = ac.size;
	while (c < t)
	{
		if (a->data[a->size - 1] < p)
			pb(a, b, l);
		else
			ra(a, b, l);
		c += 1;
	}
	return (split_swap_end(a, b, l));
}
