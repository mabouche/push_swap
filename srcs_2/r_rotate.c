/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:39:43 by mabouche          #+#    #+#             */
/*   Updated: 2018/07/21 10:47:55 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a_do(t_pile *a, t_pile *b)
{
	t_elem *new;
	t_elem *tmp;

	if ((!a->first || !a->first->next) && !(a->first != a->last))
		return ;
	new = a->last;
	remove_back(a->first, a);
	tmp = a->first;
	a->first = new;
	a->first->next = tmp;
	(void)b;
	a->coups++;
}

void	r_rotate_a(t_pile *a, t_pile *b)
{
	r_rotate_a_do(a, b);
	a->coups++;
}

void	r_rotate_b_do(t_pile *a, t_pile *b)
{
	t_elem *new;
	t_elem *tmp;

	if ((!b->first || !b->first->next) && !(b->first != b->last))
		return ;
	new = b->last;
	remove_back(b->first, b);
	tmp = b->first;
	b->first = new;
	b->first->next = tmp;
	(void)b;
	a->coups++;
}

void	r_rotate_b(t_pile *a, t_pile *b)
{
	r_rotate_b_do(a, b);
	a->coups++;
}

void	r_rotate_rr(t_pile *a, t_pile *b)
{
	if (((!b->first || !b->first->next) && b->first != b->last) ||
	((!a->first || !a->first->next) && b->first != b->last))
		return ;
	r_rotate_a_do(a, b);
	r_rotate_b_do(a, b);
}
