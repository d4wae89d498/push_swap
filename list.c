#include "list.h"

t_list	*list_new(void *data)
{
	t_list	*l;

	l = malloc(sizeof(t_list));
	l->data = data;
	l->next = 0;
	return (l);
}

void	list_push(t_list **l, void *data)
{
	list_attach(l, list_new(data));
}

void	list_iter(t_list **l, void(*cb)(void*))
{
	t_list	*it;

	it = *l;
	while (it)
	{
		cb(it->data);
		it = it->next;
	}
}

void	list_attach(t_list **l, t_list *i)
{
	t_list	*it;

	if (!*l)
		*l = i;
	it = *l;
	while (it)
	{
		if (!it->next)
			it->next = i;
		it = it->next;
	}
}

void	list_free(t_list **l)
{
	t_list	*it;
	t_list	*swp;

	it = *l;
	while (it)
	{
		swp = it->next;
		free(it);
		it = swp;
	}
	*l = 0;
}

