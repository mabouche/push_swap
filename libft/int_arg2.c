/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arg2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:08:24 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/13 17:08:30 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_space_sign_nul(const char conv, char *buf, t_flag *ptr_flag)
{
	if (ptr_flag->space == 1 && ptr_flag->plus == 0 && ptr_flag->prec == -1 &&
			ptr_flag->zero == 0 && (conv == 'd' || conv == 'i' || conv == 'D'))
	{
		if (ptr_flag->neg != 1)
			buf = ft_strmjoin(" ", buf, 2);
		ptr_flag->space = 0;
	}
	if (ptr_flag->prec == -2 && !ft_strcmp(buf, "0"))
		buf[0] = '\0';
	if (ptr_flag->prec == 0 && !ft_strcmp(buf, "0"))
		buf[0] = '\0';
	return (buf);
}

char	*int_arg_conv_prec_plus_space(char *buf, t_flag *ptr_flag)
{
	if (ptr_flag->plus == 1)
	{
		if (ft_atoi(buf) >= 0 && ptr_flag->neg == 0)
			buf = ft_strmjoin("+", buf, 2);
		ptr_flag->plus = 0;
	}
	if (ptr_flag->space == 1 && ptr_flag->plus == 0)
	{
		if (ptr_flag->neg != 1)
			buf = ft_strmjoin(" ", buf, 2);
		ptr_flag->space = 0;
	}
	return (buf);
}

char	*int_arg_conv_prec(const char conv, char *buf, t_flag *ptr_flag)
{
	if (ptr_flag->prec >= 0 &&
			(unsigned int)ptr_flag->prec >= (ft_strlen(buf) + ptr_flag->neg))
	{
		ptr_flag->prec -= ft_strlen(buf);
		if (ptr_flag->sharp == 1)
		{
			if ((conv == 'o' || conv == 'O') && ptr_flag->prec != 1)
				ptr_flag->prec -= 1;
		}
		if (ptr_flag->prec >= 0)
			buf = ft_strmjoin(ft_memset(ft_strnew(ptr_flag->prec),\
						'0', ptr_flag->prec), buf, 3);
		buf = int_arg_conv_prec_plus_space(buf, ptr_flag);
	}
	return (buf);
}

char	*int_arg_conv_width_sharp_zero(char conv, char *buf, t_flag *ptr_flag)
{
	if ((ptr_flag->zero == 0 || ptr_flag->prec != -1))
	{
		if (conv == 'x' && ft_strcmp(buf, "0") && buf[0] != '\0')
		{
			ptr_flag->sharp = 0;
			buf = ft_strmjoin("0x", buf, 2);
		}
		if (conv == 'X' && ft_strcmp(buf, "0") && buf[0] != '\0')
		{
			ptr_flag->sharp = 0;
			buf = ft_strmjoin("0X", buf, 2);
		}
	}
	return (buf);
}

char	*int_arg_conv_width_sharp(char conv, char *buf, t_flag *ptr_flag)
{
	if (ptr_flag->sharp == 1)
	{
		if (((conv == 'o') || (conv == 'O')) && (ptr_flag->width > 0) &&
				ft_strcmp(buf, "0") && buf[0] != '\0')
			ptr_flag->width -= 1;
		if (((conv == 'x') || (conv == 'X')) && (ptr_flag->width > 0) &&
				ft_strcmp(buf, "0") && buf[0] != '\0')
			ptr_flag->width -= 2;
		if (conv == 'o' && ft_strcmp(buf, "0"))
		{
			ptr_flag->sharp = 0;
			buf = ft_strmjoin("0", buf, 2);
		}
		if (conv == 'O' && ft_strcmp(buf, "0"))
		{
			ptr_flag->sharp = 0;
			buf = ft_strmjoin("0", buf, 2);
		}
		buf = int_arg_conv_width_sharp_zero(conv, buf, ptr_flag);
	}
	return (buf);
}
