/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:16:35 by mafaussu          #+#    #+#             */
/*   Updated: 2022/05/17 17:50:27 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack ft_stack_new(unsigned int size)
{
	return ((t_stack)	{0, 0, malloc(size * sizeof(void *))});
}

void	ft_stack_swap(t_stack *s, int x, int y)
{
	void	*f;

	f = s->data[s->prefix + x];
	s->data[s->prefix + x] = s->data[s->prefix + y];
	s->data[s->prefix + y] = f;
}

void	ft_stack_push(t_stack *s, void *data)
{
	s->data[s->prefix + (s->len)++] = data;
}

void	ft_stack_rotate_right(t_stack *s)
{
	int		i;
	void	*swp;

	if (s->len < 2)
		return ;
	swp = s->data[s->prefix + s->len - 1];
	i = s->len - 1;
	while (i)
	{
		s->data[s->prefix + i] = s->data[s->prefix + i - 1]; 
		i -= 1;
	}
	s->data[s->prefix] = swp;
}

void	ft_stack_rotate_left(t_stack *s)
{
	int		i;
	void	*swp;

	if (s->len < 2)
		return ;
	swp = s->data[s->prefix];
	i = 0;
	while (i < s->len - 1)
	{
		s->data[s->prefix + i] = s->data[s->prefix + i + 1];
		i += 1;
	}
	s->data[s->prefix + s->len - 1] = swp;
}

void	ft_stack_del_first(t_stack *s)
{
	s->prefix += 1;
}

void	ft_stack_del_last(t_stack *s)
{
	s->len -= 1;
}

void	*ft_stack_get_ptr(t_stack s)
{
	return ((s.data + s.prefix));
}
