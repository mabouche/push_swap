/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_five.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:17:33 by mabouche          #+#    #+#             */
/*   Updated: 2018/07/21 15:17:37 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_five_x(t_pile *a, t_pile *b)
{
	if (a->first->value < b->first->value &&
	a->first->next->value < b->first->value)
	{
		r_rotate_a(a, b);
		push_a(a, b);
	}
	else
	{
		while (a->first->value < b->first->value)
			rotate_a(a, b);
		push_a(a, b);
	}
}

int		tri_five_w(t_pile *a, t_pile *b, int start)
{
	push_a(a, b);
	if (a->last->value == start)
	{
		r_rotate_a(a, b);
		return (1);
	}
	if (a->first->next->next->next->value == start)
	{
		r_rotate_a(a, b);
		r_rotate_a(a, b);
		return (1);
	}
	else
	{
		while (a->first->value != start)
			rotate_a(a, b);
		return (1);
	}
	return (0);
}

int		tri_five_check(t_pile *a, t_pile *b)
{
	push_b(a, b);
	push_b(a, b);
	tri_three(a, b);
	r_tri_two_b(a, b);
	while (a->first->value > b->first->value)
	{
		push_a(a, b);
		if (!b->first)
			return (1);
	}
	return (0);
}

int		tri_five_v(t_pile *a, t_pile *b, int start)
{
	if (b->first->value > a->last->value)
	{
		push_a(a, b);
		while (a->first->value != start)
			rotate_a(a, b);
		return (1);
	}
	return (0);
}

void	tri_five(t_pile *a, t_pile *b)
{
	int start;

	if (tri_five_check(a, b))
		return ;
	start = a->first->value;
	if (a->last->value < b->first->value)
	{
		if (b->first->value < start)
			start = b->first->value;
		if (b->first->next->value < start)
			start = b->first->next->value;
		push_a(a, b);
		if (tri_five_v(a, b, start))
			return ;
		rotate_a(a, b);
		while (a->first->value < b->first->value)
			rotate_a(a, b);
		if (tri_five_w(a, b, start))
			return ;
	}
	tri_five_x(a, b);
	if (tri_five_y(a, b, start))
		return ;
	tri_five_z(a, b, start);
}
