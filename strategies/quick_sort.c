#include "solver.h"

static void	dump_chunks(t_stack *a, t_stack *b, int *num_chunks)
{
	int	i;

	i = a->size > b->size ? a->size : b->size;
	while (i)
	{
		printf("[%i]\t", i - 1);
		if (i <= a->size)
		{
			printf("%i", a->data[i - 1]);
		}
		printf("\t");
		if (i <= b->size)
		{
			printf("%i #%i", b->data[i - 1], *(num_chunks + b->data[i - 1]));
		}
		printf("\n");
		i -= 1;
	}
}

static int	get_midpoint(t_stack *s)
{
	int			midpoint;
	static int	mem_sc[ARG_MAX];
	t_stack		sc;

	sc = stack_init(mem_sc);
	stack_clone(&sc, s);
	sc.size = s->size;
	stack_order_asc(&sc);
	printf("sc:\n");
	dd(s, &sc, 0);

	midpoint = sc.data[sc.size / 2];
	return (midpoint);
}

int	quick_sort_b(t_stack *a, t_stack *b, t_list **l, int chunk, int *num_chunks)
{
	t_stack	bc;
	int		midpoint;
	int		i;
	int		k;

	(void) l;
	(void) a;
	chunk += 1;
	i = 0;
	k = 1;
	while (chunk >= 0)
	{
		chunk -= 1;

		while (k > 0 && num_chunks[b->data[b->size - k]] == chunk)
		{
			k += 1;
		}

		bc.data = b->data + b->size - k;
		bc.size = k;
		dd(b, &bc, 0);
		printf("---\n");
		printf("START\n");
		midpoint = get_midpoint(&bc);
		printf("midpoint=%i for chunk=%i size=%i bc.data[bc.size - 1]=%i\n", midpoint, chunk, bc.size, bc.data[bc.size - 1]);
	//	printf("END\n");
//		printf("---\n");
	}
	return (i);
}

int	quick_sort(t_stack *a, t_stack *b, t_list **l)
{
	int			i;
	int			j;
	int			k;

	int			chunk;
	int			midpoint;

	static int	num_chunks[ARG_MAX];

	dd(a, b, 0);
	j = 0;
	i = 0;
	chunk = 0;
	while (a->size > 2)
	{
		midpoint = get_midpoint(a);
		j = a->size;
		while (j && a->size > 2)
		{
			printf("%i\n", a->data[a->size - 1] );
			if (a->data[a->size - 1] <= midpoint)
			{
				num_chunks[a->data[a->size - 1]] = chunk + 1;
				i += pb(a, b, l);
			}
			else
				i += ra(a, b, l);
			j -= 1;
		}
		printf("first midpoint = %i\n", midpoint);
		dd(a, b, 0);
		printf("END\n");
	//	dump_chunks(a, b, num_chunks);
		chunk += 1;

	}

	(void) k;
	if (a->data[a->size - 1] > a->data[a->size - 2])
		i += sa(a, b, l);



	dump_chunks(a, b, num_chunks);

//	i += quick_sort_b(a, b, l, chunk, num_chunks);

//	dump_chunks(a, b, num_chunks);
	exit(0);
	return (i);
}
