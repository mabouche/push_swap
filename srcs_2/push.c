/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:57:37 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/19 16:57:45 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	prend le premier élément au sommet de b et le met sur a.
**	Ne fait rien si b est vide
*/

void	push_a(t_pile *a, t_pile *b)
{
	t_elem	*new;

	if (b->first)
	{
		new = b->first;
		b->first = new->next;
		if (a->first == NULL)
		{
			new->next = NULL;
			a->first = new;
			a->last = new;
		}
		else
		{
			new->next = a->first;
			a->first = new;
		}
		a->coups++;
	}
}

void	push_b(t_pile *a, t_pile *b)
{
	t_elem	*new;

	if (a->first)
	{
		new = a->first;
		a->first = new->next;
		if (b->first == NULL)
		{
			new->next = NULL;
			b->first = new;
			b->last = new;
		}
		else
		{
			new->next = b->first;
			b->first = new;
		}
		a->coups++;
	}
}
