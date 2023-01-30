/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:49:11 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 18:51:09 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include "list.h"
# include "stack.h"
# include "stdio.h"
# ifndef ARG_MAX
#  define ARG_MAX 262144
# endif

typedef int	(*t_instruction)(t_stack *a, t_stack *b, t_list **l);
int		sa(t_stack *a, t_stack *b, t_list **i);
int		sb(t_stack *a, t_stack *b, t_list **i);
int		ss(t_stack *a, t_stack *b, t_list **i);
int		pa(t_stack *a, t_stack *b, t_list **i);
int		pb(t_stack *a, t_stack *b, t_list **i);
int		ra(t_stack *a, t_stack *b, t_list **i);
int		rb(t_stack *a, t_stack *b, t_list **i);
int		rr(t_stack *a, t_stack *b, t_list **i);
int		rra(t_stack *a, t_stack *b, t_list **i);
int		rrb(t_stack *a, t_stack *b, t_list **i);
int		rrr(t_stack *a, t_stack *b, t_list **i);
int		da(t_stack *a, t_stack *b, t_list **i);
int		db(t_stack *a, t_stack *b, t_list **i);
int		dd(t_stack *a, t_stack *b, t_list **i);
int		max(int a, int b);
t_stack	parse(int ac, char **av, void *mem_a);
#endif
