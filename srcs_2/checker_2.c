/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:42:21 by mabouche          #+#    #+#             */
/*   Updated: 2018/07/21 15:42:22 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					order_checker(t_pile *pile_a)
{
	t_elem *cursor;

	if (pile_a->first)
		cursor = pile_a->first;
	else
		return (0);
	while (cursor->value != pile_a->last->value)
	{
		if (cursor->next && cursor->value >= cursor->next->value)
			return (0);
		else
		{
			if (cursor->next)
				cursor = cursor->next;
			else
				break ;
		}
	}
	return (1);
}

void				checker_do(t_pile *pile_a, t_pile *pile_b, char **line)
{
	if (!ft_strcmp(*line, "pa"))
		push_a(pile_a, pile_b);
	else if (!ft_strcmp(*line, "pb"))
		push_b(pile_a, pile_b);
	else if (!ft_strcmp(*line, "ra"))
		rotate_a(pile_a, pile_b);
	else if (!ft_strcmp(*line, "rb"))
		rotate_b(pile_a, pile_b);
	else if (!ft_strcmp(*line, "rr"))
		rotate_rr(pile_a, pile_b);
	else if (!ft_strcmp(*line, "rra"))
		r_rotate_a(pile_a, pile_b);
	else if (!ft_strcmp(*line, "rrb"))
		r_rotate_b(pile_a, pile_b);
	else if (!ft_strcmp(*line, "rrr"))
		r_rotate_rr(pile_a, pile_b);
	else if (!ft_strcmp(*line, "sa"))
		swap_a(pile_a, pile_b);
	else if (!ft_strcmp(*line, "sb"))
		swap_b(pile_a, pile_b);
	else if (!ft_strcmp(*line, "ss"))
		swap_ss(pile_a, pile_b);
	else
		*line = NULL;
}

int					checker(t_pile *pile_a, t_pile *pile_b)
{
	char *line;

	if (pile_b->first)
		return (1);
	while (get_next_line(0, &line) == 1)
	{
		checker_do(pile_a, pile_b, &line);
		if (!line)
			return (1);
		free(line);
	}
	free(line);
	return (0);
}

static void			sort_tab(int *tab, int size, t_pile *a, t_pile *b)
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

int					create_tab(t_pile *pile, t_pile *pile_2, int size)
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
	return (0);
}
