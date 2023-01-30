#ifndef LIST_H
# define LIST_H
# include "stdlib.h"

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;
t_list	*list_new(void *data);
void	list_push(t_list **l, void *data);
void	list_iter(t_list **l, void(*cb)(void *a));
void	list_attach(t_list **l, t_list *i);
void	list_free(t_list **l);
#endif
