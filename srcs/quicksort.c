/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:30:20 by mabouche          #+#    #+#             */
/*   Updated: 2018/07/20 16:45:29 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	repush(t_pile *a, t_pile *b, int index)
{
	int tmp;

	tmp = 0;
	while (index)
	{
		push_b(a, b);
		index--;
		tmp++;
	}
	return (tmp);
}

int	divide(t_pile *a, t_pile *b, int size)
{
	int n;
	int size_a;
	int size_b;
	int median;

	n = 0;
	size_a = 0;
	size_b = 0;
	median = create_tab(a, b, size);
	while (n < size)
	{
		if (a->first->value < median)
		{
			push_b(a, b);
			size_b++;
		}
		else
		{
			rotate_a(a, b);
			size_a++;
		}
		n++;
	}
	a->count = size_a;
	return (size_b);
}

int	quicksort(t_pile *a, t_pile *b, int size)
{
	int n;
	int size_b;
	int median;

	n = 0;
	size_b = 0;
	if (size < 90)
		return (size);
	median = create_tab(b, a, size);
	while (n < size)
	{
		if (b->first && b->first->value > median)
			push_a(a, b);
		else
		{
			rotate_b(a, b);
			size_b++;
		}
		n++;
	}
	if (size_b < 90)
		return (size_b);
	else
		return (quicksort(a, b, size_b));
}
