/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:51:23 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 18:56:38 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include "stdlib.h"

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;
typedef void(*t_list_iter_cb)(void*);
t_list	*list_new(void *data);
void	list_push(t_list **l, void *data);
void	list_iter(t_list **l, t_list_iter_cb cb);
void	list_attach(t_list **l, t_list *i);
void	list_free(t_list **l);
#endif
