/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:23:47 by mabouche          #+#    #+#             */
/*   Updated: 2018/07/21 15:23:50 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Creation element
*/

t_elem			*create_elem(int data, t_elem *next)
{
	t_elem *new_list;

	new_list = (t_elem*)ft_memalloc(sizeof(t_elem));
	if (new_list == NULL)
		return (NULL);
	new_list->value = data;
	new_list->next = next;
	new_list->flag_tri = 0;
	return (new_list);
}

/*
** Lie element en fin de liste
*/

t_elem			*append_elem(t_elem *start, int data)
{
	t_elem *cursor;
	t_elem *new;

	if (start == NULL)
		return (NULL);
	cursor = start;
	while (cursor->next != NULL)
		cursor = cursor->next;
	new = (create_elem(data, NULL));
	cursor->next = new;
	return (start);
}

void			free_pile(t_pile *pile)
{
	t_elem *cursor;

	if (!pile->first)
		return ;
	while (pile->first)
	{
		cursor = pile->first;
		pile->first = pile->first->next;
		if (cursor)
			free(cursor);
	}
}

t_pile			*init(t_elem *start)
{
	t_pile	*pile;
	t_elem	*cursor;
	int		i;

	pile = init_pile_b();
	i = 1;
	pile->first = start;
	cursor = start;
	while (cursor->next != NULL)
	{
		i++;
		cursor = cursor->next;
	}
	pile->last = cursor;
	pile->count = i;
	pile->val_med = 0;
	pile->coups = 0;
	return (pile);
}

t_pile			*init_pile_b(void)
{
	t_pile *start;

	start = (t_pile*)ft_memalloc(sizeof(t_pile));
	start->first = NULL;
	start->last = NULL;
	start->count = 0;
	start->val_med = 0;
	start->coups = 0;
	return (start);
}
