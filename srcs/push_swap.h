/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:04:45 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/19 14:04:46 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFF_SIZE 4096
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

# include "../libft/libft.h"

typedef struct		s_elem
{
	int				value;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_pile
{
	int				count;
	t_elem			*first;
	t_elem			*last;
}					t_pile;

void	push_a(t_pile *a, t_pile *b);
void	rotate_rr(t_pile *a, t_pile *b);
void	push_b(t_pile *a, t_pile *b);
void	rotate_b(t_pile *a, t_pile *b);
void	rotate_a(t_pile *a, t_pile *b);
void	swap_a(t_pile *a, t_pile *b);
void	swap_b(t_pile *a, t_pile *b);
void	swap_ss(t_pile *a, t_pile *b);

#endif