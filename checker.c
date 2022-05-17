#include "stack.h"

void	sa(t_stack *a, t_stack *b)
{
	ft_stack_swap(a, 0, 1);
}

void	sb(t_stack *a, t_stack *b)
{
	ft_stack_swap(b, 0, 1);
}


void	ss(t_stack *a, t_stack *b)
{
	sa(a, a);
	sb(a, b);
}

void	pa(t_stack *a, t_stack *b)
{
	ft_stack_push(a, ft_stack(b)[b->len - 1]);
	ft_stack_del_last(b);
}

void	pb(t_stack *a, t_stack *b)
{
	ft_stack_push(b, ft_stack(a)[a->len - 1]);
	ft_stack_del_last(a);
}

void	ra(t_stack *a, t_stack *b)
{
	ft_stack_rotate_right(a);
}

void	rb(t_stack *a, t_stack *b)
{
	ft_stack_rotate_right(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, b);
	rb(a, b);
}

void	rra(t_stack *a, t_stack *b)
{
	ft_stack_rotate_left(a);
}

void	rrb(t_stack *a, t_stack *b)
{
	ft_stack_rotate_left(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, b);
	rrb(a, b);
}

int main(int ac, char **av)
{

}
