#include "solver.h"
#include "limits.h"

static int  is_s(t_stack *s, t_list **l, int depth, int *ic)
{
    int success;

    success = try_s(s, l, depth);
    if (success && success < *ic)
    {
        *ic = success;
        return 1;
    }
    return 0;
}

static int is_r(t_stack *s, t_list **l, int depth, int *ic)
{
    int success;

    success = try_r(s, l, depth);
    if (success && success < *ic)
    {
        *ic = success;
        return 1;
    }
    return 0;
}

static int is_rr(t_stack *s, t_list **l, int depth, int *ic)
{
    int success;

    success = try_rr(s, l, depth);
    if (success && success < *ic)
    {
        *ic = success;
        return 1;
    }
    return 0;
}

char bool_tree_get_c(t_stack *s, t_list **l,
                     t_possible_instructions pi, int depth)
{
    char c;
    int ic;

    c = 'r';
    ic = INT_MAX;
    if (pi.s && is_s(s, l, depth, &ic))
        c = 's';
    if (pi.r && is_r(s, l, depth, &ic))
        c = 'r';
    if (pi.rr && is_rr(s, l, depth, &ic))
        c = 'i';
    return (c);
}