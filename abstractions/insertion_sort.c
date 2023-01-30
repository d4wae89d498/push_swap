/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:17:18 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 19:17:32 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static int	insertion_sort_rotation(t_stack *s, t_list **l,
	t_stack_instructions si, int *k)
{
	int	i;

	i = 0;
	if (*k > s->size / 2)
	{
		*k = s->size - *k;
		while (*k)
		{
			*k -= 1;
			i += si.rr(s, s, l);
		}
	}
	else
	{
		while (*k)
		{
			*k -= 1;
			i += si.r(s, s, l);
		}
	}
	return (i);
}

int	insertion_sort(t_stack *s, t_list **l,
			t_stack_instructions si, int desc)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (j < s->size)
	{
		k = 0;
		while (k < j
			&& ((!desc && s->data[s->size - 1] > s->data[s->size - 2])
				|| (desc && s->data[s->size - 1] < s->data[s->size - 2])))
		{
			i += si.s(s, s, l);
			i += si.rr(s, s, l);
			k += 1;
		}
		k += 1;
		i += insertion_sort_rotation(s, l, si, &k);
		j += 1;
	}
	i += si.r(s, s, l);
	return (i);
}
