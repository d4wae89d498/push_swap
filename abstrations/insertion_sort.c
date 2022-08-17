#include "solver.h"


int	insertion_sort(t_stack *s, t_list **l, t_stack_instructions si, int desc)
{
	int	i;
	int	j;
	int	k;


//	printf("--[%i]\n", s->size);
	i = 0;
	j = 0;
	while (j < s->size)
	{
		k = 0;
		while (k < j && ((!desc && s->data[s->size - 1] > s->data[s->size - 2]) || (desc && s->data[s->size - 1] < s->data[s->size - 2])))
		{
			i += si.s(s, s, l);
			i += si.rr(s, s, l);
			k += 1;
		}
		k += 1;
		if (k > s->size / 2)
		{
			k = s->size - k;
			while (k)
			{
				k -= 1;
				i += si.rr(s, s, l);
			}
		}
		else
		{
			while (k)
			{
				k -= 1;
				i += si.r(s, s, l);
			}
		}


//		printf("j=%i\n", j);
		j += 1;
	}

			i += si.r(s, s, l);
//	printf("--\n");
	return (i);
}
