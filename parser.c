/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaussu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:09:39 by mafaussu          #+#    #+#             */
/*   Updated: 2023/01/30 19:10:58 by mafaussu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "limits.h"
#include "unistd.h"

static int	ft_parse_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

static int	ft_atoi(char *s)
{
	long long	o;
	int			sign;

	sign = 1;
	if (!*s)
		ft_parse_error();
	if (*s == '-' && ++s)
		sign = -1;
	else if (*s == '+')
		s += 1;
	o = 0;
	while (*s >= '0' && *s <= '9')
	{
		o *= 10;
		o += *s - '0';
		if (o > INT_MAX && sign == 1)
			break ;
		if (o > (-1 * (long long)INT_MIN) && sign == -1)
			break ;
		s += 1;
	}
	if (*s)
		ft_parse_error();
	return ((int)o * sign);
}

t_stack	parse(int ac, char **av, void *mem_a)
{
	t_stack		o;
	int			i;
	int			y;
	int			k;

	if (ac < 2)
		exit (0);
	o = stack_init(mem_a);
	ac -= 1;
	av += 1;
	i = ac;
	while (i)
	{
		i -= 1;
		k = ft_atoi(av[i]);
		y = 0;
		while (y < o.size)
		{
			if (o.data[y] == k)
				ft_parse_error();
			y += 1;
		}
		stack_push(&o, k);
	}
	return (o);
}
