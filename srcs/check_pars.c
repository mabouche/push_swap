/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:53:41 by mabouche          #+#    #+#             */
/*   Updated: 2018/08/17 15:53:43 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				check_err_mult_arg(char **dest, int j)
{
	while (dest[j])
	{
		if (ft_error(dest[j]))
			return (1);
		j++;
	}
	return (0);
}

int				free_arg(char **dest, int j)
{
	while (dest[j])
	{
		free(dest[j]);
		j++;
	}
	free(dest);
	return (0);
}

int				check_err_arg(int ac, char **av)
{
	int			i;
	int			j;
	char		**dest;

	i = 1;
	j = 0;
	while (i < ac)
	{
		dest = split_arg(av[i]);
		if (dest)
		{
			if (check_err_mult_arg(dest, j))
				return (1);
			free_arg(dest, j);
			j = 0;
		}
		else
		{
			if (ft_error(av[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

void			check_tri(t_pile *a, t_pile *b)
{
	int			i;
	t_elem		*cursor;

	i = 1;
	cursor = a->first;
	while (cursor->next)
	{
		if (cursor->value < cursor->next->value)
			cursor = cursor->next;
		else
			break ;
		i++;
	}
	if (i == a->count)
	{
		deconstruct(a, b);
		exit(1);
	}
}
