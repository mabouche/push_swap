/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:35:24 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/13 18:22:39 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFF_SIZE 4096
# define INT_MAX 2147483647
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

# include "libft.h"

typedef struct		s_flag
{
	int		minus;
	int		space;
	int		sharp;
	int		plus;
	int		zero;
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		j;
	int		z;
	int		width;
	int		prec;
	int		neg;
	size_t	size_arg;
	char	conv;
}					t_flag;

typedef struct		s_get_size
{
	size_t	ptr_size_arg;
	int		i;
	int		j;
	char	*buf;
	char	*conv_spe;
}					t_get_size;

t_flag				*init_struct(void);
char				*choose_arg(va_list ap, char *buf,\
		t_flag *ptr_flag, char *conv_spe);
char				*add_arg(const char *format, va_list ap,\
		char *conv_spe, size_t *ptr_size_arg);
char				*p_arg(t_flag *ptr_flag, va_list ap, char *buf);
char				*p_width_modifier(t_flag *ptr_flag, char *buf,\
		int pref);
char				*p_width_minus_modifier(t_flag *ptr_flag, char *buf);
char				*p_no_modifier(t_flag *ptr_flag, char *buf);
char				*prct_arg(t_flag *ptr_flag, char *buf, char conv);
char				*c_arg(t_flag *ptr_flag, va_list ap, char *buf);
char				*c_arg_width_modifier(t_flag *ptr_flag, char *buf);
char				*c_up_arg(t_flag *ptr_flag, va_list ap, char *buf);
char				*c_up_arg_width_modifier(t_flag *ptr_flag, char *buf);
char				*int_arg(const char conv, va_list ap, char *buf\
		, t_flag *ptr_flag);
char				*int_arg_conv_neg(char conv, char *buf, t_flag *ptr_flag);
char				*int_arg_conv_sharp(char conv, char *buf, t_flag *ptr_flag);
char				*int_arg_conv_width(char conv, char *buf\
		, t_flag *ptr_flag);
char				*int_arg_conv_width_minus(char *buf, t_flag *ptr_flag);
char				*int_arg_conv_width_sharp(char conv, char *buf,\
					t_flag *ptr_flag);
char				*int_arg_conv_width_sharp_zero(char conv, char *buf,\
					t_flag *ptr_flag);
char				*int_arg_conv_prec(const char conv, char *buf,\
					t_flag *ptr_flag);
char				*int_arg_conv_prec_plus_space(char *buf, t_flag *ptr_flag);
char				*int_space_sign_nul(const char conv, char *buf, t_flag\
					*ptr_flag);
char				*int_arg_conv_d_i(const char conv,\
		va_list ap, char *buf, t_flag *ptr_flag);
char				*int_arg_conv_o_x(const char conv,\
		va_list ap, char *buf, t_flag *ptr_flag);
char				*int_arg_conv_u(const char conv,\
		va_list ap, char *buf, t_flag *ptr_flag);
unsigned long long	get_unum(const char conv, va_list ap, t_flag *ptr_flag);
unsigned long long	get_unum_up(const char conv,\
		va_list ap, t_flag *ptr_flag, unsigned long long unum);
char				*ft_unicode(wchar_t c);
char				*ft_unicode2(wchar_t c, char *str);
long long			get_num(const char conv, va_list ap, t_flag *ptr_flag);
long long			get_num_up(const char conv,\
		va_list ap, t_flag *ptr_flag, long long num);
char				*s_arg(char conv, t_flag *ptr_flag, va_list ap, char *buf);
char				*s_up_arg(t_flag *ptr_flag, va_list ap, char *buf);
char				*s_up_arg_create_buf(t_flag *ptr_flag,\
		char *buf, wchar_t *tmp);
char				*s_up_arg_check_tmp2(t_flag *ptr_flag,\
		char *buf, wchar_t *tmp);
char				*s_up_arg_undefined(t_flag *ptr_flag, char *temp2);
char				*s_up_arg_check_tmp(t_flag *ptr_flag,\
		char *buf, wchar_t *tmp);
char				*s_arg_width(t_flag *ptr_flag, char *buf);
char				search_flag(const char *format, t_flag *ptr_flag,\
		char conv);
void				flag_list(const char *format, t_flag *ptr_flag, int i);
int					search_prec(const char *format, char conv);
int					ret_prec(const char *format, int i, int j, char *str);
int					search_width(const char *format, char conv);
int					ret_width(const char *format, int i, int j, char *str);
const char			*search_specifier(const char *format);
void				add_buff(char **str, char *buf,\
		size_t size_str, size_t size_arg);
int					ft_printf(const char *format, ...);
size_t				get_size(const char *format, char **res, va_list ap,\
					size_t size);
#endif
