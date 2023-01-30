#include "solver.h"

static int strcmp(const char *a, const char *b)
{
    while (*a && *a == *b)
    {
        a += 1;
        b += 1;
    }
    return (*a - *b);
}

static int	eval_a(t_stack *a, t_stack *b, t_list **l, char *str)
{
	int i = 0;

	if (!strcmp(str, "pa"))
		i += pa(a, b, l);
	else if (!strcmp(str, "sa"))
		i += sa(a, b, l);
	else if (!strcmp(str, "ra"))
		i += ra(a, b, l);
	else if (!strcmp(str, "rra"))
		i += rra(a, b, l);
	return (i);
}

static int	eval_b(t_stack *a, t_stack *b, t_list **l, char *str)
{
	int i = 0;

	if (!strcmp(str, "pn"))
		i += pb(a, b, l);
	else if (!strcmp(str, "sb"))
		i += sb(a, b, l);
	else if (!strcmp(str, "rb"))
		i += rb(a, b, l);
	else if (!strcmp(str, "rrb"))
		i += rrb(a, b, l);
	return (i);
}

static void next(t_list **it_a, t_list **it_b)
{
    if (*it_a)
        *it_a = (*it_a)->next;
    if (*it_b)
        *it_b = (*it_b)->next;
}

int merge_instructions(t_stack *a, t_stack *b, t_list *ia, t_list *ib, t_list **l)
{
    int i = 0;

    t_list *it_a;
    t_list *it_b;

    it_a = ia;
    it_b = ib;
    while (it_a || it_b)
    {
        if (it_a && it_b)
        {
            if (!strcmp(it_a->data, "sa") && !strcmp(it_b->data, "sb"))
            {
                i += ss(a, b, l);
                next(&it_a, &it_b);
                continue ;
            }
            else if (!strcmp(it_a->data, "ra") && !strcmp(it_b->data, "rb"))
            {
                i += rr(a, b, l);
                next(&it_a, &it_b);
                continue ;
            }
            else if (!strcmp(it_a->data, "rra") && !strcmp(it_b->data, "rrb"))
            {
                i += rrr(a, b, l);
                next(&it_a, &it_b);
                continue ;
            }
            else if (it_b->next)
            {
                if (!strcmp(it_a->data, "sa") && !strcmp(it_b->next->data, "sb"))
                {
                    i += eval_b(a, b, l, it_b->data);
                    i += ss(a, b, l);
                    it_b = it_b->next;
                    next(&it_a, &it_b);
                    continue ;
                }
                else if (!strcmp(it_a->data, "ra") && !strcmp(it_b->next->data, "rb"))
                {
                    i += eval_b(a, b, l, it_b->data);
                    i += rr(a, b, l);
                    it_b = it_b->next;
                    next(&it_a, &it_b);
                    continue ;
                }
                else if (!strcmp(it_a->data, "rra") && !strcmp(it_b->next->data, "rrb"))
                {
                    i += eval_b(a, b, l, it_b->data);
                    i += rrr(a, b, l);
                    it_b = it_b->next;
                    next(&it_a, &it_b);
                    continue ;
                }
            }
            else if (it_a->next)
            {
                if (!strcmp(it_a->next->data, "sa") && !strcmp(it_b->data, "sb"))
                {
                    i += eval_a(a, b, l, it_a->data);
                    i += ss(a, b, l);
                    it_a = it_a->next;
                    next(&it_a, &it_b);
                    continue ;
                }
                else if (!strcmp(it_a->next->data, "ra") && !strcmp(it_b->data, "rb"))
                {
                    i += eval_a(a, b, l, it_a->data);
                    i += rr(a, b, l);
                    it_a = it_a->next;
                    next(&it_a, &it_b);
                    continue ;
                }
                else if (!strcmp(it_a->next->data, "rra") && !strcmp(it_b->data, "rrb"))
                {
                    i += eval_a(a, b, l, it_a->data);
                    i += rrr(a, b, l);
                    it_a = it_a->next;
                    next(&it_a, &it_b);
                    continue ;
                }
            }
        }
        if (it_a)
        {
            i += eval_a(a, b, l, it_a->data);
        }

        if (it_b)
        {
            i += eval_b(a, b, l, it_b->data);
        }
        next(&it_a, &it_b);
    }
    return (i);
}
