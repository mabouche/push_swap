/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:22:05 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/13 17:22:12 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		get_num_up(const char conv,\
va_list ap, t_flag *ptr_flag, long long num)
{
	if (conv == 'd' || conv == 'i')
	{
		if (ptr_flag->l == 1)
			num = (long int)va_arg(ap, long int);
		else if (ptr_flag->ll == 1)
			num = (long long int)va_arg(ap, long long int);
		else if (ptr_flag->j == 1)
			num = (intmax_t)va_arg(ap, intmax_t);
		else if (ptr_flag->z == 1)
			num = (size_t)va_arg(ap, size_t);
		else if (ptr_flag->hh == 1)
			num = (char)va_arg(ap, int);
		else if (ptr_flag->h == 1)
			num = (short)va_arg(ap, int);
		else
			num = (long long)va_arg(ap, int);
	}
	return (num);
}

long long		get_num(const char conv, va_list ap, t_flag *ptr_flag)
{
	long long num;

	num = 0;
	if (conv == 'D')
	{
		if (ptr_flag->l == 1)
			num = (long int)va_arg(ap, long int);
		else if (ptr_flag->ll == 1)
			num = (long long int)va_arg(ap, long long int);
		else if (ptr_flag->j == 1)
			num = (intmax_t)va_arg(ap, intmax_t);
		else if (ptr_flag->z == 1)
			num = (size_t)va_arg(ap, size_t);
		else if (ptr_flag->hh == 1)
			num = (int)va_arg(ap, long int);
		else if (ptr_flag->h == 1)
			num = (int)va_arg(ap, long int);
		else
			num = (long long)va_arg(ap, long int);
	}
	num = get_num_up(conv, ap, ptr_flag, num);
	return (num);
}

char			*ft_unicode2(wchar_t c, char *str)
{
	if (c <= 0x7F)
		str[0] = c;
	else if (c <= 0x7FF)
	{
		str[0] = (c >> 6) + 0xC0;
		str[1] = (c & 0x3F) + 0x80;
	}
	else if (c < 0xFFFF)
	{
		str[0] = (c >> 12) + 0xE0;
		str[1] = ((c >> 6) & 0x3F) + 0x80;
		str[2] = (c & 0x3F) + 0x80;
	}
	else
	{
		str[0] = ((c >> 18) + 0xF0);
		str[1] = ((c >> 12) & 0x3F) + 0x80;
		str[2] = ((c >> 6) & 0x3F) + 0x80;
		str[3] = (c & 0x3F) + 0x80;
	}
	return (str);
}

char			*ft_unicode(wchar_t c)
{
	char	*str;

	if ((c >= 0xd800 && c <= 0xdfff) || c <= -2 || c >= 1114112)
	{
		str = "UNDEFINED";
		return (str);
	}
	str = ft_strnew(4);
	str = ft_unicode2(c, str);
	return (str);
}
