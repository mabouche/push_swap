/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_med.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:56:38 by mabouche          #+#    #+#             */
/*   Updated: 2018/07/21 14:58:14 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_med(int *tab, int size)
{
	int i;

	if (size % 2)
		i = (size / 2) + 1;
	else
		i = (size / 2);
	return (tab[i]);
}

static void	sort_tab(int *tab, int size, t_pile *a, t_pile *b)
{
	int i;
	int tmp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else if (tab[i] == tab[i + 1])
		{
			ft_putendl_fd("Error", 2);
			deconstruct(a, b);
			exit(1);
		}
		else
			i++;
	}
}

int			create_tab(t_pile *pile, t_pile *pile_2, int size)
{
	int		tab[size];
	int		i;
	t_elem	*tmp;

	if (size == 1)
		return (pile->first->value);
	tmp = pile->first;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	size = i;
	free(tmp);
	sort_tab(tab, size, pile, pile_2);
	return (find_med(tab, size));
}
