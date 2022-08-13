#include "common.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
#include "string.h"

int main(int ac, char **av)
{
	static int	mem_a[ARG_MAX];
	t_stack		a;
	static int	mem_b[ARG_MAX];
	t_stack		b;

	char		buffer[3];
	size_t		bytes;

	a = parse(ac, av, mem_a);
	b = stack_init(mem_b);
	dd(&a, &b, 0);
	while (1)
	{
		bytes = read(0, buffer, 3);
		if (!bytes)
			break ;
		if (buffer[2] == '\n')
		{
			if (!strncmp(buffer, "pa", 2))
				pa(&a, &b, 0);
			else if (!strncmp(buffer, "pb", 2))
				pb(&a, &b, 0);
			else if (!strncmp(buffer, "sa", 2))
				sa(&a, &b, 0);
			else if (!strncmp(buffer, "sb", 2))
				sb(&a, &b, 0);
			else if (!strncmp(buffer, "ss", 2))
				ss(&a, &b, 0);
			else if (!strncmp(buffer, "ra", 2))
				ra(&a, &b, 0);
			else if (!strncmp(buffer, "rb", 2))
				rb(&a, &b, 0);
			else if (!strncmp(buffer, "rr", 2))
				rr(&a, &b, 0);
			else
			{
				printf("Error %i\n", __LINE__);
				exit(0);
			}
	
		}
		else
		{
			if (!strncmp(buffer, "rrb", 3))
				rrb(&a, &b, 0);
			else if (!strncmp(buffer, "rra", 3))
				rra(&a, &b, 0);
			else if (!strncmp(buffer, "rrr", 3))
				rrr(&a, &b, 0);
			else
			{
				printf("Error %i\n", __LINE__);
				exit(0);
			}
			if (!read(0, buffer, 1))
				break ;
			else if (buffer[0] != '\n')
			{
				printf("Error %i\n", __LINE__);
				exit(0);
			}
		}
		dd(&a, &b, 0);
	}
}
