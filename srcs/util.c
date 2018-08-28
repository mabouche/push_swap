/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:06:02 by mabouche          #+#    #+#             */
/*   Updated: 2018/07/21 15:06:03 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem			*remove_back(t_elem *head, t_pile *pile)
{
	t_elem *cursor;

	cursor = head;
	if (head == NULL)
		return (NULL);
	while (cursor->next != pile->last)
		cursor = cursor->next;
	cursor->next = NULL;
	pile->last = cursor;
	return (head);
}

int				make_abs(int x)
{
	return ((x < 0) ? -x : x);
}

intmax_t		ft_atoi_int_max(const char *str)
{
	int			index;
	int			posneg;
	intmax_t	res;

	index = 0;
	posneg = 1;
	res = 0;
	while (ft_isspace(str[index]) == 1)
		index++;
	if (str[index] == 45)
		posneg = -1;
	if (str[index] == 45 || str[index] == 43)
		index++;
	while (ft_isdigit(str[index]) == 1)
	{
		res = res * 10 + str[index] - 48;
		index++;
	}
	return (res * posneg);
}

int				ft_str_is_numeric_space(char *s)
{
	unsigned int index;

	index = 0;
	while (s[index])
	{
		if (s[index] == '-' && (s[index + 1] < 48 || s[index + 1] > 57))
			return (0);
		if (!(s[index] > 47 && s[index] < 58) &&\
		s[index] != ' ' && s[index] != '-')
			return (0);
		index++;
	}
	return (1);
}

void			deconstruct(t_pile *a, t_pile *b)
{
	free_pile(a);
	free_pile(b);
	free(a);
	free(b);
}
