/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:57:19 by mabouche          #+#    #+#             */
/*   Updated: 2018/07/20 16:15:29 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char			**split_arg(char *av)
{
	int		i;
	char	**dest;

	i = 0;
	dest = ft_strsplit(av, ' ');
	if (ft_strlen(dest[0]) == ft_strlen(av))
	{
		free(dest[0]);
		free(dest);
		return (NULL);
	}
	else
		return (dest);
}

void			init_pile_a_follow(int ac, char **av, int i, t_elem **start)
{
	char	**dest;
	int		j;

	j = 0;
	while (i < ac)
	{
		dest = split_arg(av[i]);
		if (dest)
		{
			while (dest[j])
			{
				*start = append_elem(*start, ft_atoi_int_max(dest[j]));
				free(dest[j]);
				j++;
			}
			free(dest);
			j = 0;
		}
		else
			*start = append_elem(*start, ft_atoi_int_max(av[i]));
		i++;
	}
}

t_elem			*init_pile_a(int ac, char **av)
{
	int		i;
	int		j;
	char	**dest;
	t_elem	*start;

	j = 0;
	i = 1;
	dest = split_arg(av[i]);
	if (dest)
	{
		start = create_elem(ft_atoi_int_max(dest[j]), NULL);
		free(dest[j]);
		j++;
		while (dest[j])
		{
			start = append_elem(start, ft_atoi_int_max(dest[j]));
			free(dest[j]);
			j++;
		}
		free(dest);
	}
	else
		start = create_elem(ft_atoi_int_max(av[i]), NULL);
	init_pile_a_follow(ac, av, ++i, &start);
	return (start);
}

int				ft_error(char *av)
{
	if (!ft_str_is_numeric_space(av))
		return (1);
	if (ft_atoi_int_max(av) > INT_MAX ||
	ft_atoi_int_max(av) < INT_MIN)
		return (1);
	if (ft_atoi_int_max(av) == 0 && ft_strcmp("0", av))
		return (1);
	else
		return (0);
}

int				main(int ac, char **av)
{
	t_elem *start_a;
	t_pile *pile_a;
	t_pile *pile_b;

	if (check_err_arg(ac, av) || ac <= 1)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	else
		start_a = init_pile_a(ac, av);
	pile_a = init(start_a);
	pile_b = init_pile_b();
	check_tri(pile_a, pile_b);
	if (pile_a && (pile_a->count == 2 || pile_a->count == 1 ||
	pile_a->count == 3 || pile_a->count == 5))
		baby_sort(pile_a, pile_b);
	else if (pile_a && pile_a->count < 70)
		short_sort(pile_a, pile_b);
	else
		big_sort(pile_a, pile_b);
	deconstruct(pile_a, pile_b);
}
