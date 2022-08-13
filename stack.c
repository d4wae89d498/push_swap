#include "stack.h"

t_stack	stack_init(void *data)
{
	t_stack	s;

	s.size = 0;
	s.data = data;
	return (s);
}

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

#include <stdio.h>
void	stack_dump(t_stack s)
{
	int	i;

	i = s.size;
	while (i)
	{
		i -= 1;
		printf("[%i] %i\n", i, s.data[i]);
	}
	printf("-\n");
}
