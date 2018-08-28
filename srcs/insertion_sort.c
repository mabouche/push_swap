/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 20:31:31 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/27 16:00:56 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_mid_max_find(t_pile *b, int *min, int *max)
{
	t_elem *current;

	current = b->first;
	*min = current->value;
	*max = current->value;
	while (current != NULL)
	{
		current = current->next;
		if (current && current->value > *max)
			*max = current->value;
		if (current && current->value < *min)
			*min = current->value;
	}
}

void	rotate_a_flag_max(t_pile *a, t_pile *b, int flag_max)
{
	while (flag_max >= 1)
	{
		rotate_a(a, b);
		flag_max--;
	}
}

void	push_mid_max(t_pile *a, t_pile *b, int size)
{
	int	min;
	int	max;
	int	dist;
	int	flag_max;

	if (!push_mid_max_check(a, b, size))
		return ;
	flag_max = 0;
	while (b->first != NULL)
	{
		push_mid_max_find(b, &min, &max);
		if (make_abs(find_dist(b, max)) < make_abs(find_dist(b, min)))
		{
			dist = find_dist(b, max);
			do_if_max(a, b, dist);
			flag_max++;
		}
		else
		{
			dist = find_dist(b, min);
			do_if_min(a, b, dist);
		}
	}
	rotate_a_flag_max(a, b, flag_max);
}

void	insertion_sort(t_pile *a, t_pile *b, int size)
{
	int n;
	int median;
	int index;

	n = 1;
	index = 0;
	if (size == 0)
		return ;
	median = create_tab(b, a, size);
	push_mid_max(a, b, size);
}
