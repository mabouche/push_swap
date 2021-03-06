/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:46:27 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/19 16:46:38 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pile *a, t_pile *b)
{
	int tmp;

	if (!a->first || !a->first->next)
		return ;
	tmp = a->first->value;
	a->first->value = a->first->next->value;
	a->first->next->value = tmp;
	(void)b;
	ft_printf("sa\n");
	a->coups++;
}

void	swap_b(t_pile *a, t_pile *b)
{
	int tmp;

	if (!b->first || !b->first->next)
		return ;
	tmp = b->first->value;
	b->first->value = b->first->next->value;
	b->first->next->value = tmp;
	(void)a;
	ft_printf("sb\n");
	a->coups++;
}

void	swap_ss(t_pile *a, t_pile *b)
{
	int tmp;

	if (!a->first || !a->first->next || !b->first || !b->first->next)
		return ;
	tmp = a->first->value;
	a->first->value = a->first->next->value;
	a->first->next->value = tmp;
	tmp = b->first->value;
	b->first->value = b->first->next->value;
	b->first->next->value = tmp;
	ft_printf("ss\n");
	a->coups++;
}
