/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:59:01 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/19 16:59:18 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_pile *a, t_pile *b)
{
	t_elem *new;

	if ((!a->first || !a->first->next))
		return ;
	new = a->first;
	a->first = a->first->next;
	new->next = NULL;
	a->last->next = new;
	a->last = new;
	(void)b;
	a->coups++;
}

void	rotate_b(t_pile *a, t_pile *b)
{
	t_elem *new;

	if ((!b->first || !b->first->next))
		return ;
	new = b->first;
	b->first = b->first->next;
	new->next = NULL;
	b->last->next = new;
	b->last = new;
	(void)a;
	a->coups++;
}

void	rotate_rr(t_pile *a, t_pile *b)
{
	t_elem *new;

	if ((!b->first || !b->first->next) ||
	(!a->first || !a->first->next))
		return ;
	new = a->first;
	a->first = a->first->next;
	new->next = NULL;
	a->last->next = new;
	a->last = new;
	new = b->first;
	b->first = b->first->next;
	new->next = NULL;
	b->last->next = new;
	b->last = new;
	a->coups++;
}
