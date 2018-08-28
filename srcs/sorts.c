/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:27:03 by mabouche          #+#    #+#             */
/*   Updated: 2018/07/21 15:27:04 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				short_sort_first(t_pile *a, t_pile *b)
{
	int last_value;
	int tmp;
	int median;

	tmp = 0;
	last_value = a->last->value;
	median = create_tab(a, b, a->count);
	while (a && a->first && a->first->value != last_value)
	{
		if (a && a->first->value <= median)
		{
			tmp++;
			push_b(a, b);
		}
		else
			rotate_a(a, b);
	}
	if (a && a->first->value <= median)
	{
		tmp++;
		push_b(a, b);
	}
	else
		rotate_a(a, b);
	return (tmp);
}

void			short_sort(t_pile *a, t_pile *b)
{
	int median;
	int tmp;

	median = create_tab(a, b, a->count);
	tmp = short_sort_first(a, b);
	b->count = tmp;
	insertion_sort(a, b, b->count);
	tmp = 0;
	while (a && a->first)
	{
		if (a && a->first->value < median)
			break ;
		else
		{
			push_b(a, b);
			tmp++;
		}
	}
	tmp = b->count;
	if (b->count)
		insertion_sort(a, b, b->count);
}

void			loop_big_sort(t_pile *pile_a, t_pile *pile_b, int tmp)
{
	while (pile_a->count)
	{
		tmp = repush(pile_a, pile_b, pile_a->count);
		pile_b->count = quicksort(pile_a, pile_b, tmp);
		insertion_sort(pile_a, pile_b, pile_b->count);
		pile_a->count -= tmp;
		pile_a->count += (tmp - pile_b->count);
		if (pile_a->count <= 1)
			break ;
	}
}

void			loop_big_sort_2(t_pile *pile_a, t_pile *pile_b, int tmp)
{
	while (pile_a->count)
	{
		tmp = repush(pile_a, pile_b, pile_a->count);
		pile_b->count = quicksort(pile_a, pile_b, pile_b->count);
		insertion_sort(pile_a, pile_b, tmp);
		pile_a->count -= tmp;
		if (pile_a->count <= 1)
			break ;
	}
}

void			big_sort(t_pile *pile_a, t_pile *pile_b)
{
	int median;
	int pushed_to_b;
	int tmp;

	median = create_tab(pile_a, pile_b, pile_a->count);
	tmp = pile_a->count;
	pushed_to_b = divide(pile_a, pile_b, pile_a->count);
	tmp -= pushed_to_b;
	pile_b->count = pushed_to_b;
	pile_b->count = quicksort(pile_a, pile_b, pushed_to_b);
	insertion_sort(pile_a, pile_b, pile_b->count);
	pile_a->count = (pushed_to_b - pile_b->count);
	if (pile_a->count > 1)
		loop_big_sort_2(pile_a, pile_b, pile_a->count);
	pile_a->count = tmp;
	if (pile_a->count > 1)
		loop_big_sort(pile_a, pile_b, pushed_to_b);
}
