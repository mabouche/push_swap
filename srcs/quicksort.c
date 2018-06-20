/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 20:36:59 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/19 20:37:02 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void quicksort(t_pile *a, t_pile *b, int size)
{
    if(size == 1)
        return ;
    int index;
    int median;
    int n;
    n = 0;
    index = 0;
    median = a->last->value;
    while(n >= size )
    {
       if(a->first->value > median)
       {
        push_b(a, b);
        index++;
       }
        n++;
        rotate_a(a, b);
    }
    n = 0;

    while(n <= (size  - index))
    {
        n++;
        r_rotate_a(a, b);
    }
    n = 0;
    while(n <= index)
        {
            push_a(a, b);
            n++;
        }
    quicksort(a, b, index);
    n = 0;
    while(n <= index)
    {
        rotate_a(a, b);
        n++;
    }
    quicksort(a, b, size - index);
    n = 0;
    while(n <= index)
    {
        n++;
        r_rotate_a(a, b);
    }
}
