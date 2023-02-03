/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:56:52 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 19:05:53 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# include "common.h"
# include "stdio.h"
# include "stdlib.h"

typedef struct s_stack_instructions
{
	t_instruction	rr;
	t_instruction	r;
	t_instruction	p;
	t_instruction	s;
}		t_stack_instructions;
typedef struct s_possible_instructions
{
	int	s:	1;
	int	r:	1;
	int	rr:	1;
}	t_possible_instructions;
typedef int	(*t_try_cb)(t_stack *s, t_list **l, int depth);
typedef struct s_branch
{
	t_try_cb	try;
	t_stack		*s;
	t_list		**l;
	int			depth;
	int			*ic;
}	t_branch;
/* abstrations */
int		find_index(t_stack s, int n);
int		find_index_rev(t_stack s, int n);
int		order_a(t_stack *a, t_stack *b, t_stack *ac, t_list **l);
int		order_b(t_stack *a, t_stack *b, t_stack *bc, t_list **l);
int		bubble_sort_a(t_stack *a, t_stack *b, t_list **l);
int		bubble_sort_b(t_stack *a, t_stack *b, t_list **l);
int		insertion_sort(t_stack *s, t_list **l,
			t_stack_instructions si, int desc);
int		is_sorted_asc(t_stack *s);
int		is_sorted_desc(t_stack *s);
int		is_sorted(t_stack *s, int desc);
int		cmp(t_stack *s, int ix, int iy, int desc);
/* strategies */
int		merge_instructions(t_stack *a, t_stack *b, t_list *ia, t_list *ib, t_list **l);
int		split_swap(t_stack *a, t_stack *b, t_list **l);
int		radix(t_stack *a, t_stack *b, t_list **l);
int		bool_tree(t_stack *a, t_stack *b, t_list **l);
int		quick_sort(t_stack *a, t_stack *b, t_list **l);
void	set_index(t_stack *s, int *median);
char	bool_tree_get_c(t_stack *s, t_list **l,
			t_possible_instructions pi, int depth);
char	bool_tree_c(t_stack *s, t_list **l, t_possible_instructions pi,
			int depth);
int		bool_tree_r(t_stack *s, t_list **l,
			t_possible_instructions pi, int depth);
#endif
