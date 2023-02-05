/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_tree_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:56:50 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/03 18:05:50 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "limits.h"

static inline int	try_s(t_stack *s, t_list **l, int depth)
{
	int		*mem_sc;
	t_stack	sc;
	int		i;

	(void) l;
	mem_sc = malloc(s->size * sizeof(int));
	if (!mem_sc)
		return (0);
	sc = stack_init(mem_sc);
	stack_clone(&sc, s);
	i = 0;
	i += sa(&sc, 0, 0);
	i += bool_tree_r(&sc, 0,
			(t_possible_instructions){.s = 0, .r = 1, .rr = 1}, depth + 1);
	if (is_sorted_asc(&sc))
	{
		free(mem_sc);
		return (i);
	}
	free(mem_sc);
	return (0);
}

static inline int	try_r(t_stack *s, t_list **l, int depth)
{
	int		*mem_sc;
	t_stack	sc;
	int		i;

	(void) l;
	mem_sc = malloc(s->size * sizeof(int));
	if (!mem_sc)
		return (0);
	sc = stack_init(mem_sc);
	stack_clone(&sc, s);
	i = (ra(&sc, 0, 0));
	i += bool_tree_r(&sc, 0,
			(t_possible_instructions){.s = 1, .r = 1, .rr = 0}, depth + 1);
	if (is_sorted_asc(&sc))
	{
		free(mem_sc);
		return (i);
	}
	free(mem_sc);
	return (0);
}

static inline int	try_rr(t_stack *s, t_list **l, int depth)
{
	int		*mem_sc;
	t_stack	sc;
	int		i;

	(void) l;
	mem_sc = malloc(s->size * sizeof(int));
	if (!mem_sc)
		return (0);
	sc = stack_init(mem_sc);
	stack_clone(&sc, s);
	i = (rra(&sc, 0, 0));
	i += bool_tree_r(&sc, 0,
			(t_possible_instructions){.s = 1, .r = 0, .rr = 1}, depth + 1);
	if (is_sorted_asc(&sc))
	{
		free(mem_sc);
		return (i);
	}
	free(mem_sc);
	return (0);
}

static int	is_branch(t_branch b)
{
	int	success;

	success = b.try(b.s, b.l, b.depth);
	if (success && success < *(b.ic))
	{
		*(b.ic) = success;
		return (1);
	}
	return (0);
}

char	bool_tree_c(t_stack *s, t_list **l, t_possible_instructions pi,
			int depth)
{
	char	c;
	int		ic;
	int		success;

	ic = INT_MAX;
	success = 0;
	c = 0;
	if (pi.s && is_branch((t_branch){try_s, s, l, depth, &ic}))
		c = 's';
	if (pi.r && is_branch((t_branch){try_r, s, l, depth, &ic}))
		c = 'r';
	if (pi.rr && is_branch((t_branch){try_rr, s, l, depth, &ic}))
		c = 'i';
	if (!ic)
		c = 'r';
	return (c);
}
