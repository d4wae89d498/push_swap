#include "common.h"
#if LOG == 1
# include "stdio.h"
#endif

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
	(void) a;
#if LOG == 1
	stack_dump(*a);
#endif
	return (0);
}

int		db(t_stack *a, t_stack *b, t_list **l)
{
	(void) l;
	(void) b;
	(void) a;
#if LOG == 1
	stack_dump(*b);
#endif
	return (0);
}


int		dd(t_stack *a, t_stack *b, t_list **l)
{
	int	i;

	(void) a;
	(void) b;
	(void) l;
	(void) i;
#if LOG == 1
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
#endif
	return (0);
}
