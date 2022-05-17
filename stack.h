/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:16:30 by mafaussu          #+#    #+#             */
/*   Updated: 2022/05/17 17:50:25 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "stdlib.h"

typedef struct s_stack
{
	int		prefix;
	int		len;
	void	**data;
}	t_stack;
t_stack ft_stack_new(unsigned int size);
void	ft_stack_swap(t_stack *s, int x, int y);
void	ft_stack_push(t_stack *s, void *data);
void	ft_stack_rotate_right(t_stack *s);
void	ft_stack_rotate_left(t_stack *s);
void	ft_stack_del_first(t_stack *s);
void	ft_stack_del_last(t_stack *s);
void	*ft_stack(t_stack s);
#endif
