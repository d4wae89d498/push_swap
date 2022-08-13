#include "common.h"


int	max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int		da(t_stack *a, t_stack *b, t_list **l)
{	
	(void) l;
	(void) b;
	stack_dump(*a);
	return (0);
}

int		db(t_stack *a, t_stack *b, t_list **l)
{
	(void) l;
	(void) a;
	stack_dump(*b);
	return (0);
}

#include <stdio.h>
int		dd(t_stack *a, t_stack *b, t_list **l)
{
	int	i;

	(void) l;
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
	return (0);
}

