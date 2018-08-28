/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 11:59:26 by mabouche          #+#    #+#             */
/*   Updated: 2018/07/21 11:04:04 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_three_sec(t_pile *a, t_pile *b)
{
	if (a->first->value < a->first->next->value &&
			a->first->next->value > a->last->value)
	{
		if (a->first->value > a->last->value)
		{
			r_rotate_a(a, b);
			return ;
		}
		r_rotate_a(a, b);
		swap_a(a, b);
		return ;
	}
	if (a->first->value < a->last->value &&
			a->first->value > a->first->next->value)
	{
		swap_a(a, b);
		rotate_a(a, b);
		return ;
	}
}

void	tri_three(t_pile *a, t_pile *b)
{
	if (a->first->value > a->first->next->value)
	{
		if (a->first->value < a->last->value)
		{
			swap_a(a, b);
			return ;
		}
		if (a->first->value > a->last->value &&
				a->first->next->value > a->last->value)
		{
			rotate_a(a, b);
			swap_a(a, b);
			return ;
		}
		if (a->first->value > a->last->value &&
				a->first->next->value < a->last->value)
		{
			rotate_a(a, b);
			return ;
		}
	}
	tri_three_sec(a, b);
}

void	r_tri_two_b(t_pile *a, t_pile *b)
{
	if (b->first->value < b->first->next->value)
	{
		swap_b(a, b);
	}
}

void	tri_two(t_pile *a, t_pile *b)
{
	if (a->first->value > a->first->next->value)
	{
		swap_a(a, b);
	}
}

void	baby_sort(t_pile *pile_a, t_pile *pile_b)
{
	create_tab(pile_a, pile_b, pile_a->count);
	if (pile_a && pile_a->count == 3)
		tri_three(pile_a, pile_b);
	else if (pile_a && pile_a->count == 2)
		tri_two(pile_a, pile_b);
	else if (pile_a && pile_a->count == 5)
		tri_five(pile_a, pile_b);
}
