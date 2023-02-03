/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:56:50 by mafaussu          #+#    #+#             */
/*   Updated: 2023/02/03 19:05:50 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "limits.h"

int	bool_tree_r(t_stack *s, t_list **l, t_possible_instructions pi, int depth)
{
	int	c;

	if (depth > 11)
		return (0);
	if (is_sorted_asc(s))
		return (0);
	c = bool_tree_c(s, l, pi, depth);
	if (c == 's')
		return (sa(s, 0, l) + bool_tree_r(s, l,
				(t_possible_instructions){.s = 0, .r = 1, .rr = 1}, depth + 1));
	if (c == 'r')
		return (ra(s, 0, l) + bool_tree_r(s, l,
				(t_possible_instructions){.s = 1, .r = 1, .rr = 0}, depth + 1));
	if (c == 'i')
		return (rra(s, 0, l) + bool_tree_r(s, l,
				(t_possible_instructions){.s = 1, .r = 0, .rr = 1}, depth + 1));
	return (0);
}

int	bool_tree(t_stack *a, t_stack *b, t_list **l)
{
	int	i;

	(void) b;
	i = 0;
	i += bool_tree_r(a, l,
			(t_possible_instructions){.s = 1, .r = 1, .rr = 1}, 0);
	return (i);
}
