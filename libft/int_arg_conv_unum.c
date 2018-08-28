/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arg_conv_unum.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:13:54 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/13 17:14:02 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long		get_unum_up(const char conv,\
va_list ap, t_flag *ptr_flag, unsigned long long unum)
{
	if (conv == 'O' || conv == 'U')
	{
		if (ptr_flag->l == 1)
			unum = (unsigned long int)va_arg(ap, unsigned long);
		else if (ptr_flag->ll == 1)
			unum = (unsigned long long int)va_arg(ap, unsigned long);
		else if (ptr_flag->j == 1)
			unum = (intmax_t)va_arg(ap, intmax_t);
		else if (ptr_flag->z == 1)
			unum = (size_t)va_arg(ap, size_t);
		else if (ptr_flag->hh == 1)
			unum = (unsigned long long)va_arg(ap, unsigned long);
		else if (ptr_flag->h == 1)
			unum = (unsigned long long)va_arg(ap, unsigned long);
		else
			unum = (unsigned long long)va_arg(ap, unsigned long);
	}
	return (unum);
}

unsigned long long		get_unum(const char conv, va_list ap, t_flag *ptr_flag)
{
	unsigned long long unum;

	unum = 0;
	if (conv == 'x' || conv == 'u' || conv == 'o' || conv == 'X')
	{
		if (ptr_flag->l == 1)
			unum = (unsigned long int)va_arg(ap, unsigned long long int);
		else if (ptr_flag->ll == 1)
			unum = (unsigned long long int)va_arg(ap, unsigned long long int);
		else if (ptr_flag->j == 1)
			unum = (intmax_t)va_arg(ap, intmax_t);
		else if (ptr_flag->z == 1)
			unum = (size_t)va_arg(ap, size_t);
		else if (ptr_flag->hh == 1)
			unum = (unsigned char)va_arg(ap, unsigned int);
		else if (ptr_flag->h == 1)
			unum = (unsigned short)va_arg(ap, unsigned int);
		else
			unum = (unsigned long long)va_arg(ap, unsigned int);
	}
	unum = get_unum_up(conv, ap, ptr_flag, unum);
	return (unum);
}

char					*int_arg_conv_u(const char conv,\
va_list ap, char *buf, t_flag *ptr_flag)
{
	unsigned long long	unum;
	int					base;

	if (conv == 'u' || conv == 'U')
	{
		unum = get_unum(conv, ap, ptr_flag);
		base = 10;
		buf = ft_utoa_base(unum, base);
		ptr_flag->plus = 0;
	}
	return (buf);
}

char					*int_arg_conv_o_x(const char conv,\
va_list ap, char *buf, t_flag *ptr_flag)
{
	int					i;
	unsigned long long	unum;

	i = -1;
	if (conv == 'o' || conv == 'O')
	{
		unum = get_unum(conv, ap, ptr_flag);
		buf = ft_utoa_base(unum, 8);
		ptr_flag->plus = 0;
	}
	if (conv == 'x' || conv == 'X')
	{
		unum = get_unum(conv, ap, ptr_flag);
		buf = ft_utoa_base(unum, 16);
		if (conv == 'X')
		{
			while (buf[++i])
				buf[i] = (char)ft_toupper(buf[i]);
		}
		ptr_flag->plus = 0;
	}
	return (buf);
}

char					*int_arg_conv_d_i(const char conv,\
va_list ap, char *buf, t_flag *ptr_flag)
{
	int					base;
	long long			num;

	ptr_flag->neg = 0;
	base = 10;
	if (conv == 'd' || conv == 'i' || conv == 'I' || conv == 'D')
	{
		num = get_num(conv, ap, ptr_flag);
		if (num < 0)
		{
			num *= -1;
			ptr_flag->neg = 1;
		}
		buf = ft_itoa_base(num, base);
	}
	return (buf);
}
