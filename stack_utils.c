/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:09:04 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 19:09:05 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

t_stack	stack_init(void *data)
{
	t_stack	s;

	s.size = 0;
	s.data = data;
	return (s);
}

void	stack_clone(t_stack *dst, t_stack *src)
{
	int	i;

	dst->size = src->size;
	i = 0;
	while (i < src->size)
	{
		dst->data[i] = src->data[i];
		i += 1;
	}
}

void	stack_order_asc(t_stack *s)
{
	int	i;
	int	y;
	int	swp;

	i = 0;
	while (i < s->size)
	{
		i += 1;
		y = 0;
		while (y < s->size - 1)
		{
			if (s->data[y] < s->data[y + 1])
			{
				swp = s->data[y];
				s->data[y] = s->data[y + 1];
				s->data[y + 1] = swp;
			}
			y += 1;
		}
	}
}

void	stack_order_desc(t_stack *s)
{
	int	i;
	int	y;
	int	swp;

	i = 0;
	while (i < s->size)
	{
		i += 1;
		y = 0;
		while (y < s->size - 1)
		{
			if (s->data[y] > s->data[y + 1])
			{
				swp = s->data[y];
				s->data[y] = s->data[y + 1];
				s->data[y + 1] = swp;
			}
			y += 1;
		}
	}
}
