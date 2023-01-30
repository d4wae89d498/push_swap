#include "solver.h"

//todo :: impl me

#include <string.h>



int split_swap_begin(t_stack *a, t_stack *b, t_list **l)
{
    static int mem_ac[ARG_MAX];
    t_stack ac;
    int c;
    int i;

    i = 0;
    c = 0;
    ac = stack_init(mem_ac);
    stack_clone(&ac, a);
    stack_order_asc(&ac);
    int p = ac.data[ac.size / 2];
    int t = ac.size;
    while (c < t)
    {
        if (a->data[a->size - 1] < p)
            i += pb(a, b, l);
        else
            i += ra(a, b, l);
        c += 1;
    }
    return (i);
}

void split_swap_end(t_stack *a, t_stack *b, t_list **ia, t_list **ib)
{
    static int mem_acc[ARG_MAX];
    t_stack acc;
    static int mem_bcc[ARG_MAX];
    t_stack bcc;

    acc = stack_init(mem_acc);
    bcc = stack_init(mem_bcc);
    stack_clone(&acc, a);
    stack_clone(&bcc, b);
    insertion_sort(&acc, ia,
                   (t_stack_instructions){
                       .r = ra,
                       .rr = rra,
                       .p = pa,
                       .s = sa},
                   0);

    insertion_sort(&bcc, ib,
                   (t_stack_instructions){
                       .r = rb,
                       .rr = rrb,
                       .p = pb,
                       .s = sb},
                   1);
}

int	split_swap(t_stack *a, t_stack *b, t_list **l)
{
	int		i;
	t_list	*ia;
	t_list	*ib;

	if (is_sorted(a, 0))
		return (0);	
	i = split_swap_begin(a, b, l);
	ia = 0;
	ib = 0;
	split_swap_end(a, b, &ia, &ib);
	i += merge_instructions(a, b, ia, ib, l);
	while (b->size)
		i += pa(a, b, l);
	return (i);
}
