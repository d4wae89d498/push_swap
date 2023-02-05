/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:14:20 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 19:14:37 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	pa(t_stack *a, t_stack *b, t_list **i)
{
	if (!b->size)
		return (1);
	if (list_push(i, "pa"))
		return (0);
	stack_push(a, b->data[b->size - 1]);
	stack_pull(b);
	return (1);
}

int	pb(t_stack *a, t_stack *b, t_list **i)
{
	if (!a->size)
		return (1);
	if (list_push(i, "pb"))
		return (0);
	stack_push(b, a->data[a->size - 1]);
	stack_pull(a);
	return (1);
}
