/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_swap_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:04:57 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 19:04:58 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static int ft_strcmp(const char *a, const char *b)
{
    while (*a && *a == *b)
    {
        a += 1;
        b += 1;
    }
    return (*a - *b);
}

static int	eval_a(t_stack *a, t_stack *b, t_list **l, char *str)
{
	int i = 0;

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

static int	eval_b(t_stack *a, t_stack *b, t_list **l, char *str)
{
	int i = 0;

	if (!ft_strcmp(str, "pn"))
		i += pb(a, b, l);
	else if (!ft_strcmp(str, "sb"))
		i += sb(a, b, l);
	else if (!ft_strcmp(str, "rb"))
		i += rb(a, b, l);
	else if (!ft_strcmp(str, "rrb"))
		i += rrb(a, b, l);
	return (i);
}

static void next(t_list **it_a, t_list **it_b)
{
    if (*it_a)
        *it_a = (*it_a)->next;
    if (*it_b)
        *it_b = (*it_b)->next;
}

t_list *merge_instructions(t_stack *a, t_stack *b, t_list *ia, t_list *ib)
{
    int		i;
	t_list	*l;
    t_list 	*it_a;
    t_list 	*it_b;

	i = 0;
	l = 0;
    it_a = ia;
    it_b = ib;
    while (it_a || it_b)
    {
        if (it_a && it_b)
        {
            if (!ft_strcmp(it_a->data, "sa") && !ft_strcmp(it_b->data, "sb"))
            {
                i += ss(a, b, &l);
                next(&it_a, &it_b);
                continue ;
            }
            else if (!ft_strcmp(it_a->data, "ra") && !ft_strcmp(it_b->data, "rb"))
            {
                i += rr(a, b, &l);
                next(&it_a, &it_b);
                continue ;
            }
            else if (!ft_strcmp(it_a->data, "rra") && !ft_strcmp(it_b->data, "rrb"))
            {
                i += rrr(a, b, &l);
                next(&it_a, &it_b);
                continue ;
            }
            else if (it_b->next)
            {
                if (!ft_strcmp(it_a->data, "sa") && !ft_strcmp(it_b->next->data, "sb"))
                {
                    i += eval_b(a, b, &l, it_b->data);
                    i += ss(a, b, &l);
                    it_b = it_b->next;
                    next(&it_a, &it_b);
                    continue ;
                }
                else if (!ft_strcmp(it_a->data, "ra") && !ft_strcmp(it_b->next->data, "rb"))
                {
                    i += eval_b(a, b, &l, it_b->data);
                    i += rr(a, b, &l);
                    it_b = it_b->next;
                    next(&it_a, &it_b);
                    continue ;
                }
                else if (!ft_strcmp(it_a->data, "rra") && !ft_strcmp(it_b->next->data, "rrb"))
                {
                    i += eval_b(a, b, &l, it_b->data);
                    i += rrr(a, b, &l);
                    it_b = it_b->next;
                    next(&it_a, &it_b);
                    continue ;
                }
            }
            else if (it_a->next)
            {
                if (!ft_strcmp(it_a->next->data, "sa") && !ft_strcmp(it_b->data, "sb"))
                {
                    i += eval_a(a, b, &l, it_a->data);
                    i += ss(a, b, &l);
                    it_a = it_a->next;
                    next(&it_a, &it_b);
                    continue ;
                }
                else if (!ft_strcmp(it_a->next->data, "ra") && !ft_strcmp(it_b->data, "rb"))
                {
                    i += eval_a(a, b, &l, it_a->data);
                    i += rr(a, b, &l);
                    it_a = it_a->next;
                    next(&it_a, &it_b);
                    continue ;
                }
                else if (!ft_strcmp(it_a->next->data, "rra") && !ft_strcmp(it_b->data, "rrb"))
                {
                    i += eval_a(a, b, &l, it_a->data);
                    i += rrr(a, b, &l);
                    it_a = it_a->next;
                    next(&it_a, &it_b);
                    continue ;
                }
            }
        }
        if (it_a)
        {
            i += eval_a(a, b, &l, it_a->data);
        }

        if (it_b)
        {
            i += eval_b(a, b, &l, it_b->data);
        }
        next(&it_a, &it_b);
    }
    return (l);
}
