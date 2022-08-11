#include "common.h"

int	max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void	da(t_stack *a, t_stack *b)
{
	stack_dump(*a);
}

void	db(t_stack *a, t_stack *b)
{
	stack_dump(*b);
}

#include <stdio.h>
void	dd(t_stack *a, t_stack *b)
{
	int	i;

	i = max(a->size, b->size);
	while (i)
	{
		i -= 1;
		printf("[%i]", i);
		if (i < a->size)
			printf("\t%i", a->data[i]);
		else
			printf("\t");
		if (i < b->size)
			printf("\t%i", b->data[i]);
		else
			printf("\t");
		printf("\n");
	}
	printf("   \t-\t-\n");
	printf("   \ta\tb\n-----------------------------------\n");
}
