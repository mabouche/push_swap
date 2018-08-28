/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_five_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:18:31 by mabouche          #+#    #+#             */
/*   Updated: 2018/07/21 15:18:31 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_five_z(t_pile *a, t_pile *b, int start)
{
	while (b->first != NULL)
	{
		if (b->first->value < a->first->value &&
		b->first->value > a->last->value)
		{
			push_a(a, b);
			break ;
		}
		else
			rotate_a(a, b);
	}
	if (a->last->value == start)
	{
		r_rotate_a(a, b);
		return ;
	}
	if (a->first->next->next->next->value == start)
	{
		r_rotate_a(a, b);
		r_rotate_a(a, b);
		return ;
	}
	while (a->first->value != start)
		rotate_a(a, b);
}

int		tri_five_y(t_pile *a, t_pile *b, int start)
{
	if (b->first->value < start)
	{
		if (a->last->value == start)
		{
			r_rotate_a(a, b);
			push_a(a, b);
			return (1);
		}
		if (a->first->next->next->next->value == start)
		{
			r_rotate_a(a, b);
			r_rotate_a(a, b);
			return (1);
		}
		while (a->first->value != start)
			rotate_a(a, b);
		push_a(a, b);
		return (1);
	}
	return (0);
}
