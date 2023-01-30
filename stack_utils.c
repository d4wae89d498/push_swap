#include "solver.h"

/*
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
*/

t_stack	stack_init(void *data)
{
	t_stack	s;

	s.size = 0;
	s.data = data;
	return (s);
}

void	stack_clone(t_stack *dst, t_stack *src)
{
	int	i;

	dst->size = src->size;
	i = 0;
	while (i < src->size)
	{
		dst->data[i] = src->data[i];
		i += 1;
	}
}

void	stack_order_asc(t_stack *s)
{
	int	i;
	int	y;
	int	swp;

	i = 0;
	while (i < s->size)
	{
		i += 1;
		y = 0;
		while (y < s->size - 1)
		{
			if (s->data[y] < s->data[y + 1])
			{
				swp = s->data[y];
				s->data[y] = s->data[y + 1];
				s->data[y + 1] = swp;
			}
			y += 1;
		}
	}
}

void	stack_order_desc(t_stack *s)
{
	int	i;
	int	y;
	int	swp;

	i = 0;
	while (i < s->size)
	{
		i += 1;
		y = 0;
		while (y < s->size - 1)
		{
			if (s->data[y] > s->data[y + 1])
			{
				swp = s->data[y];
				s->data[y] = s->data[y + 1];
				s->data[y + 1] = swp;
			}
			y += 1;
		}
	}
}