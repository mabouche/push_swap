/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:39:43 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/19 18:39:44 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem* remove_back(t_elem* head, t_pile *pile)
{
    if(head == NULL)
        return NULL;

    t_elem *cursor = head;
    while(cursor->next != pile->last)
        cursor = cursor->next;
    cursor->next = NULL;
    pile->last = cursor;
    return head;
}

/*
 * **	Decale d'une position vers le haut tous les elents de la pile a.
 * **	le premier element devient le dernier
 * */

void	r_rotate_a(t_pile *a, t_pile *b)
{
	t_elem *new;
    t_elem *tmp;

	if ((!a->first || !a->first->next) && a->first != a->last)
		return ;
	new = a->last;
    remove_back(a->first, a);
    tmp = a->first;
    a->first = new;
    a->first->next = tmp;
	(void)b;
}

/*
 * **	Decale d'une position vers le haut tous les elents de la pile b.
 * **	le premier element devient le dernier
 * */

void	r_rotate_b(t_pile *a, t_pile *b)
{
    r_rotate_a(b, a);
}

/*
 * **	Rotate a et Rotate b en meme temps
 * */

void	r_rotate_rr(t_pile *a, t_pile *b)
{
	t_elem *new;

	if (((!b->first || !b->first->next) && b->first != b->last) || ((!a->first || !a->first->next) && b->first != b->last))
		return ;
	r_rotate_a(a, b);
    r_rotate_b(a, b);
}
