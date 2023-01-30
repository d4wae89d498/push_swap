/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:17:43 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 19:17:54 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int	is_sorted_asc(t_stack *s)
{
	return (is_sorted(s, 0));
}

int	is_sorted_desc(t_stack *s)
{
	return (is_sorted(s, 1));
}

int	is_sorted(t_stack *s, int desc)
{
	int	i;

	i = 0;
	while (i < s->size - 1)
	{
		if (!desc && s->data[i] < s->data[i + 1])
			return (0);
		if (desc && s->data[i] > s->data[i + 1])
			return (0);
		i += 1;
	}
	return (1);
}

int	cmp(t_stack *s, int ix, int iy, int desc)
{
	if (desc)
		return (s->data[ix] > s->data[iy]);
	return (s->data[ix] < s->data[iy]);
}
