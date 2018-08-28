/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arg1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:02:19 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/13 17:05:51 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_arg_conv_width_minus(char *buf, t_flag *ptr_flag)
{
	if (ptr_flag->minus == 0)
	{
		if (ptr_flag->zero == 1 && ptr_flag->prec == -1)
			buf = ft_strmjoin(ft_memset(ft_strnew(ptr_flag->width)\
						, '0', ptr_flag->width), buf, 3);
		else
		{
			if (ptr_flag->neg == 1 && ft_strcmp(buf, "-9223372036854775808"))
			{
				buf = ft_strmjoin("-", buf, 2);
				ptr_flag->neg = 2;
			}
			buf = ft_strmjoin(ft_memset(ft_strnew(ptr_flag->width)\
						, ' ', ptr_flag->width), buf, 3);
		}
	}
	else if (ptr_flag->minus == 1)
		buf = ft_strmjoin(buf, ft_memset(ft_strnew(ptr_flag->width)\
					, ' ', ptr_flag->width), 3);
	return (buf);
}

char	*int_arg_conv_width(char conv, char *buf, t_flag *ptr_flag)
{
	if (ptr_flag->width >= 0 && ptr_flag->width >= ptr_flag->prec &&
			(unsigned int)ptr_flag->width >= (ft_strlen(buf) + ptr_flag->neg))
	{
		ptr_flag->width -= (ft_strlen(buf) + ptr_flag->plus + ptr_flag->space);
		buf = int_arg_conv_width_sharp(conv, buf, ptr_flag);
		if (ptr_flag->neg == 1 && ptr_flag->plus != 1)
			ptr_flag->width -= 1;
		buf = int_arg_conv_width_minus(buf, ptr_flag);
	}
	return (buf);
}

char	*int_arg_conv_sharp(char conv, char *buf, t_flag *ptr_flag)
{
	if (ptr_flag->width <= 0)
		ptr_flag->width = 0;
	if (ptr_flag->sharp == 1)
	{
		if (conv == 'o' && ft_strcmp(buf + (ptr_flag->width), "0"))
			buf = ft_strmjoin("0", buf, 2);
		if (conv == 'O' && ft_strcmp(buf + (ptr_flag->width), "0"))
			buf = ft_strmjoin("0", buf, 2);
		if (conv == 'x' && ft_strcmp(buf + (ptr_flag->width), "0")
				&& buf[0] != '\0' && ft_strcmp(buf + (ptr_flag->width), "\0"))
			buf = ft_strmjoin("0x", buf, 2);
		if (conv == 'X' && ft_strcmp(buf + (ptr_flag->width), "0") &&
				buf[0] != '\0' && ft_strcmp(buf + (ptr_flag->width), "\0"))
			buf = ft_strmjoin("0X", buf, 2);
	}
	return (buf);
}

char	*int_arg_conv_neg(char conv, char *buf, t_flag *ptr_flag)
{
	if (ptr_flag->neg == 1 && ft_strcmp(buf, "-9223372036854775808"))
	{
		buf = ft_strmjoin("-", buf, 2);
		ptr_flag->neg = 2;
	}
	if (ptr_flag->space == 1 && ptr_flag->plus == 0 &&
			(conv == 'd' || conv == 'i' || conv == 'D'))
	{
		if (ft_atoi(buf) >= 0)
			buf = ft_strmjoin(" ", buf, 2);
		ptr_flag->space = 0;
	}
	return (buf);
}

char	*int_arg(const char conv, va_list ap, char *buf, t_flag *ptr_flag)
{
	ptr_flag->neg = 0;
	buf = int_arg_conv_u(conv, ap, buf, ptr_flag);
	buf = int_arg_conv_o_x(conv, ap, buf, ptr_flag);
	buf = int_arg_conv_d_i(conv, ap, buf, ptr_flag);
	buf = int_space_sign_nul(conv, buf, ptr_flag);
	buf = int_arg_conv_prec(conv, buf, ptr_flag);
	buf = int_arg_conv_width(conv, buf, ptr_flag);
	buf = int_arg_conv_neg(conv, buf, ptr_flag);
	buf = int_arg_conv_sharp(conv, buf, ptr_flag);
	if (ptr_flag->plus == 1)
	{
		if (ft_atoi(buf) >= 0 && ptr_flag->neg == 0)
			buf = ft_strmjoin("+", buf, 2);
	}
	ptr_flag->size_arg = ft_strlen(buf);
	return (buf);
}
