/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:12:08 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 19:13:52 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	sa(t_stack *a, t_stack *b, t_list **l)
{
	(void)b;
	list_push(l, "sa");
	stack_swap(*a);
	return (1);
}

int	sb(t_stack *a, t_stack *b, t_list **l)
{
	(void)a;
	list_push(l, "sb");
	stack_swap(*b);
	return (1);
}

int	ss(t_stack *a, t_stack *b, t_list **l)
{
	list_push(l, "ss");
	sa(a, b, 0);
	sb(a, b, 0);
	return (1);
}
