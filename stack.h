/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:06:09 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 19:06:10 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int	size;
	int	*data;
}	t_stack;

t_stack	stack_init(void *data);
void	stack_order_asc(t_stack *s);
void	stack_order_desc(t_stack *s);
void	stack_clone(t_stack *dst, t_stack *src);
void	stack_push(t_stack *s, int i);
void	stack_pull(t_stack *s);
void	stack_swap(t_stack s);
void	stack_rotate(t_stack s);
void	stack_reverse_rotate(t_stack s);
void	stack_dump(t_stack s);
#endif
