#include "stack.h"

#include <stdio.h>

char	**ft_stack_str(t_stack s)
{
	return ((char**)ft_stack(s));
}

int main(int ac, char **av)
{
	t_stack		a;

	int			i;

	a = ft_stack_new(ac);
	
	i = 1;
	while (i < ac)
		ft_stack_push(&a, av[i++]);

	ft_stack_rotate_right(&a);

	i = 0;
	while (i < a.len)
		printf("-%s\n", ft_stack_str(a)[i++]);
}
