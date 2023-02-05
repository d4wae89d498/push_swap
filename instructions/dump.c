/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:11:03 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 19:16:30 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	dd(t_stack *a, t_stack *b, t_list **l)
{
	(void) l;
	(void) b;
	(void) a;
	return (0);
}

/*
#if LOG == 1
# include "stdio.h"
#endif
int		da(t_stack *a, t_stack *b, t_list **l)
{	
	(void) l;
	(void) b;
	(void) a;
#if LOG == 1
	dd(a, 0, 0);
#endif
	return (0);
}

int		db(t_stack *a, t_stack *b, t_list **l)
{
	(void) l;
	(void) b;
	(void) a;
#if LOG == 1
	dd(0, b, l);
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
}*/
