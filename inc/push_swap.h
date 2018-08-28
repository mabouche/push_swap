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

typedef struct			s_elem
{
	int					flag_tri;
	int					value;
	struct s_elem		*next;
}						t_elem;

typedef struct			s_pile
{
	int					coups;
	int					count;
	int					val_med;
	t_elem				*first;
	t_elem				*last;
}						t_pile;

void					push_a(t_pile *a, t_pile *b);
void					rotate_rr(t_pile *a, t_pile *b);
void					push_b(t_pile *a, t_pile *b);
void					rotate_b(t_pile *a, t_pile *b);
void					rotate_a(t_pile *a, t_pile *b);
void					swap_a(t_pile *a, t_pile *b);
void					swap_b(t_pile *a, t_pile *b);
void					swap_ss(t_pile *a, t_pile *b);
int						create_tab(t_pile *pile, t_pile *pile_2, int size);
t_pile					*init(t_elem *start);
void					insertion_sort(t_pile *a, t_pile *b, int size);
int						divide(t_pile *a, t_pile *b, int size);
void					r_rotate_a(t_pile *a, t_pile *b);
void					r_rotate_b(t_pile *a, t_pile *b);
void					r_rotate_a_do(t_pile *a, t_pile *b);
void					r_rotate_b_do(t_pile *a, t_pile *b);
void					r_rotate_rr(t_pile *a, t_pile *b);
void					tri_three(t_pile *a, t_pile *b);
void					tri_two(t_pile *a, t_pile *b);
void					tri_five(t_pile *a, t_pile *b);
int						tri_five_y(t_pile *a, t_pile *b, int start);
void					tri_five_z(t_pile *a, t_pile *b, int start);
void					r_tri_two_b(t_pile *a, t_pile *b);
int						repush(t_pile *a, t_pile *b, int index);
int						repush_2(t_pile *a, t_pile *b, int index);
int						divide(t_pile *a, t_pile *b, int size);
int						quicksort(t_pile *a, t_pile *b, int size);
void					deconstruct(t_pile *a, t_pile *b);
t_elem					*remove_back(t_elem *head, t_pile *pile);
int						make_abs(int x);
int						find_dist(t_pile *b, int value);
void					do_if_max(t_pile *a, t_pile *b, int dist);
void					do_if_min(t_pile *a, t_pile *b, int dist);
int						push_mid_max_check(t_pile *a, t_pile *b, int size);
t_elem					*create_elem(int data, t_elem *next);
t_elem					*append_elem(t_elem *start, int data);
void					free_pile(t_pile *pile);
t_pile					*init(t_elem *start);
t_pile					*init_pile_b(void);
intmax_t				ft_atoi_int_max(const char *str);
int						make_abs(int x);
void					baby_sort(t_pile *pile_a, t_pile *pile_b);
void					big_sort(t_pile *pile_a, t_pile *pile_b);
void					short_sort(t_pile *pile_a, t_pile *pile_b);
int						ft_str_is_numeric_space(char *s);
int						order_checker(t_pile *pile_a);
void					checker_do(t_pile *pile_a, t_pile *pile_b, char **line);
int						checker(t_pile *pile_a, t_pile *pile_b);
void					check_tri(t_pile *a, t_pile *b);
int						check_err_arg(int ac, char **av);
int						check_err_mult_arg(char **dest, int j);
char					**split_arg(char *av);
int						ft_error(char *av);
#endif
