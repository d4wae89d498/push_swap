/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:14:00 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 19:14:01 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ra(t_stack *a, t_stack *b, t_list **l)
{
	(void)b;
	if(list_push(l, "ra"))
		return (0);
	stack_rotate(*a);
	return (1);
}

int	rb(t_stack *a, t_stack *b, t_list **l)
{
	(void)a;
	if (list_push(l, "rb"))
		return (0);
	stack_rotate(*b);
	return (1);
}

int	rr(t_stack *a, t_stack *b, t_list **l)
{
	if (list_push(l, "rr"))
		return (0);
	ra(a, b, 0);
	rb(a, b, 0);
	return (1);
}
