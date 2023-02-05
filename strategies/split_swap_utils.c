/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_swap_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:00:01 by mafaussu          #+#    #+#             */
/*   Updated: 2023/02/03 15:00:22 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static int	try_simple(t_s2l3 args)
{
	if (!ft_strcmp((*(args.ia))->data, "sa")
		&& !ft_strcmp((*(args.ib))->data, "sb"))
		return (ss(args.a, args.b, args.l));
	else if (!ft_strcmp((*(args.ia))->data, "ra")
		&& !ft_strcmp((*(args.ib))->data, "rb"))
		return (rr(args.a, args.b, args.l));
	else if (!ft_strcmp((*(args.ia))->data, "rra")
		&& !ft_strcmp((*(args.ib))->data, "rrb"))
		return (rrr(args.a, args.b, args.l));
	return (0);
}

static int	try_next_a(t_s2l3 args)
{
	int	i;

	i = 0;
	if (!ft_strcmp((*(args.ia))->next->data, "sa")
		&& !ft_strcmp((*(args.ib))->data, "sb"))
	{
		i = eval_a(args.a, args.b, args.l, (*(args.ia))->data);
		i += ss(args.a, args.b, args.l);
		(*(args.ia)) = (*(args.ia))->next;
	}
	else if (!ft_strcmp((*(args.ia))->next->data, "ra")
		&& !ft_strcmp((*(args.ib))->data, "rb"))
	{
		i = eval_a(args.a, args.b, args.l, (*(args.ia))->data);
		i += rr(args.a, args.b, args.l);
		(*(args.ia)) = (*(args.ia))->next;
	}
	else if (!ft_strcmp((*(args.ia))->next->data, "rra")
		&& !ft_strcmp((*(args.ib))->data, "rrb"))
	{
		i = eval_a(args.a, args.b, args.l, (*(args.ia))->data);
		i += rrr(args.a, args.b, args.l);
		(*(args.ia)) = (*(args.ia))->next;
	}
	return (i);
}

static int	try_next_b(t_s2l3 args)
{
	int	i;

	i = 0;
	if (!ft_strcmp((*(args.ia))->data, "sa")
		&& !ft_strcmp((*(args.ib))->next->data, "sb"))
	{
		i = eval_b(args.a, args.b, args.l, (*(args.ib))->data);
		i += ss(args.a, args.b, args.l);
		(*(args.ib)) = (*(args.ib))->next;
	}
	else if (!ft_strcmp((*(args.ia))->data, "ra")
		&& !ft_strcmp((*(args.ib))->next->data, "rb"))
	{
		i = eval_b(args.a, args.b, args.l, (*(args.ib))->data);
		i += rr(args.a, args.b, args.l);
		(*(args.ib)) = (*(args.ib))->next;
	}
	else if (!ft_strcmp((*(args.ia))->data, "rra")
		&& !ft_strcmp((*(args.ib))->next->data, "rrb"))
	{
		i = eval_b(args.a, args.b, args.l, (*(args.ib))->data);
		i += rrr(args.a, args.b, args.l);
		(*(args.ib)) = (*(args.ib))->next;
	}
	return (i);
}

static int	optimize(t_s2l3 args)
{
	int	i;

	i = 0;
	if (try_simple((t_s2l3){args.a, args.b, args.ia, args.ib, args.l}))
		i += 1;
	else if ((*(args.ia))->next && try_next_a((t_s2l3){args.a, args.b, args.ia,
			args.ib, args.l}))
		i += 2;
	else if ((*(args.ib))->next && try_next_b((t_s2l3){args.a, args.b, args.ia,
			args.ib, args.l}))
		i += 2;
	return (i);
}

int	merge_instructions(t_s2l3 args)
{
	int		i;
	int		s;
	t_list	*it_a;
	t_list	*it_b;

	i = 0;
	s = 0;
	it_a = *args.ia;
	it_b = *args.ib;
	while (it_a || it_b)
	{
		s = 0;
		if (it_a && it_b)
			s = optimize((t_s2l3){args.a, args.b, &it_a, &it_b, args.l});
		if (!s)
		{
			if (it_a)
				i += eval_a(args.a, args.b, args.l, it_a->data);
			if (it_b)
				i += eval_b(args.a, args.b, args.l, it_b->data);
		}
		next(&it_a, &it_b);
	}
	return (i);
}
