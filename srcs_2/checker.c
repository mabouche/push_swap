/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:44:17 by mabouche          #+#    #+#             */
/*   Updated: 2018/07/21 11:47:38 by mabouche         ###   ########.fr       */
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
			j = 0;
			free(dest);
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

	if (check_err_arg(ac, av))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	else
		start_a = init_pile_a(ac, av);
	pile_a = init(start_a);
	pile_b = init_pile_b();
	create_tab(pile_a, pile_b, pile_a->count);
	if (checker(pile_a, pile_b))
		ft_putendl_fd("Error", 2);
	else
	{
		if (!(order_checker(pile_a)))
			ft_printf("KO\n");
		else
			ft_printf("OK\n");
	}
	deconstruct(pile_a, pile_b);
}
