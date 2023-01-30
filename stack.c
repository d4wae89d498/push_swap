/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:08:39 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 19:08:40 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_push(t_stack *s, int i)
{
	s->data[s->size] = i;
	s->size += 1;
}

void	stack_pull(t_stack *s)
{
	s->size -= 1;
}

void	stack_swap(t_stack s)
{
	int	swp;

	swp = s.data[s.size - 1];
	s.data[s.size - 1] = s.data[s.size - 2];
	s.data[s.size - 2] = swp;
}

void	stack_rotate(t_stack s)
{
	int	i;
	int	last;

	if (s.size < 2)
		return ;
	last = s.data[s.size - 1];
	i = s.size - 1;
	while (i)
	{
		s.data[i] = s.data[i - 1];
		i -= 1;
	}
	s.data[0] = last;
}

void	stack_reverse_rotate(t_stack s)
{
	int	i;
	int	first;

	if (s.size < 2)
		return ;
	first = s.data[0];
	i = 0;
	while (i < s.size - 1)
	{
		s.data[i] = s.data[i + 1];
		i += 1;
	}
	s.data[s.size - 1] = first;
}
