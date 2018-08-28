/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:11:02 by mabouche          #+#    #+#             */
/*   Updated: 2018/07/21 15:11:03 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_dist(t_pile *b, int value)
{
	t_elem		*current;
	int			res;
	int			res2;
	int			fin;

	res = 0;
	res2 = 0;
	current = b->first;
	while (current && current->value != value)
	{
		res++;
		current = current->next;
	}
	while (current)
	{
		res2++;
		current = current->next;
	}
	if (res2 <= res)
		fin = res2;
	else
		fin = -res;
	return (fin);
}

void	do_if_max(t_pile *a, t_pile *b, int dist)
{
	int index;

	index = 0;
	if (dist == 0)
		push_a(a, b);
	if (dist < 0)
	{
		while (dist != 0)
		{
			rotate_b(a, b);
			dist++;
		}
		push_a(a, b);
	}
	if (dist > 0)
	{
		while (dist != 0)
		{
			r_rotate_b(a, b);
			dist--;
		}
		push_a(a, b);
	}
}

void	do_if_min(t_pile *a, t_pile *b, int dist)
{
	if (dist == 0)
	{
		push_a(a, b);
		rotate_a(a, b);
	}
	if (dist < 0)
	{
		while (dist != 0)
		{
			rotate_b(a, b);
			dist++;
		}
		push_a(a, b);
		rotate_a(a, b);
	}
	if (dist > 0)
	{
		while (dist != 0)
		{
			r_rotate_b(a, b);
			dist--;
		}
		push_a(a, b);
		rotate_a(a, b);
	}
}

int		push_mid_max_check(t_pile *a, t_pile *b, int size)
{
	if (size == 0)
		return (0);
	if (size == 1)
	{
		push_a(a, b);
		rotate_a(a, b);
		return (0);
	}
	else
		return (1);
}
