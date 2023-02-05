/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:14:11 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 19:14:12 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	rra(t_stack *a, t_stack *b, t_list **l)
{
	(void)b;
	if (list_push(l, "rra"))
		return (0);
	stack_reverse_rotate(*a);
	return (1);
}

int	rrb(t_stack *a, t_stack *b, t_list **l)
{
	(void)a;
	if (list_push(l, "rrb"))
		return (0);
	stack_reverse_rotate(*b);
	return (1);
}

int	rrr(t_stack *a, t_stack *b, t_list **l)
{
	if (list_push(l, "rrr"))
		return (0);
	rra(a, b, 0);
	rrb(a, b, 0);
	return (1);
}
