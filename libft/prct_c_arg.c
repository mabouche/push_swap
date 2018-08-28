/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prct_c_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:58:41 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/13 16:58:47 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_up_arg_width_modifier(t_flag *ptr_flag, char *buf)
{
	char c;

	if (ptr_flag->width > 0 && (unsigned int)ptr_flag->width > ft_strlen(buf))
	{
		ptr_flag->width--;
		if (ptr_flag->zero == 1)
			c = '0';
		else if (ptr_flag->zero == 0)
			c = ' ';
		ptr_flag->width -= 1;
		if (ptr_flag->minus == 0)
			buf = ft_memjoin(ft_memset(ft_strnew(ptr_flag->width), c,\
						ptr_flag->width), buf, ptr_flag->width, ft_strlen(buf));
		else if (ptr_flag->minus == 1)
			buf = ft_memjoin(buf, ft_memset(ft_strnew(ptr_flag->width), c,\
						ptr_flag->width), ft_strlen(buf), ptr_flag->width);
	}
	return (buf);
}

char	*c_up_arg(t_flag *ptr_flag, va_list ap, char *buf)
{
	buf = ft_unicode(va_arg(ap, wchar_t));
	if (!ft_strcmp(buf, "UNDEFINED"))
	{
		ptr_flag->size_arg = -1;
		return (NULL);
	}
	if (ptr_flag->width > 0 && (unsigned int)ptr_flag->width > ft_strlen(buf))
		ptr_flag->size_arg += (ptr_flag->width - 1);
	buf = c_up_arg_width_modifier(ptr_flag, buf);
	ptr_flag->size_arg += ft_strlen(buf);
	if (ptr_flag->width > 0 && (unsigned int)ptr_flag->width > ft_strlen(buf))
		ptr_flag->size_arg -= ptr_flag->width + 1;
	if (ft_strlen(buf) == 0)
		ptr_flag->size_arg += 1;
	return (buf);
}

char	*c_arg_width_modifier(t_flag *ptr_flag, char *buf)
{
	int c;

	if (ptr_flag->width > 0)
	{
		if (ptr_flag->zero == 1)
			c = '0';
		else if (ptr_flag->zero == 0)
			c = ' ';
		ptr_flag->width -= 1;
		if (ptr_flag->minus == 0)
			buf = ft_memjoin(ft_memset(ft_strnew(ptr_flag->width), c,\
						ptr_flag->width), buf, ptr_flag->width, 1);
		else if (ptr_flag->minus == 1)
			buf = ft_memjoin(buf, ft_memset(ft_strnew(ptr_flag->width), c,\
						ptr_flag->width), 1, ptr_flag->width);
	}
	return (buf);
}

char	*c_arg(t_flag *ptr_flag, va_list ap, char *buf)
{
	int i;

	if (ptr_flag->l == 1)
	{
		buf = c_up_arg(ptr_flag, ap, buf);
		return (buf);
	}
	i = 0;
	buf = ft_memalloc(sizeof(va_arg(ap, int)));
	*buf = va_arg(ap, int);
	if (ptr_flag->width > 0)
	{
		ptr_flag->size_arg += (ptr_flag->width - 1);
	}
	buf = c_arg_width_modifier(ptr_flag, buf);
	ptr_flag->size_arg += 1;
	return (buf);
}

char	*prct_arg(t_flag *ptr_flag, char *buf, char conv)
{
	char *str;

	str = ft_memalloc(sizeof(conv));
	str[0] = conv;
	str[1] = '\0';
	buf = ft_strmjoin("", str, 2);
	if (ptr_flag->width >= 0 && ptr_flag->width >= ptr_flag->prec &&
			(unsigned int)ptr_flag->width >= (ft_strlen(buf)))
	{
		ptr_flag->width -= ft_strlen(buf);
		if (ptr_flag->minus == 0)
		{
			if (ptr_flag->zero == 1)
				buf = ft_strmjoin(ft_memset(ft_strnew(ptr_flag->width)\
							, '0', ptr_flag->width), buf, 3);
			if (ptr_flag->zero == 0)
				buf = ft_strmjoin(ft_memset(ft_strnew(ptr_flag->width)\
							, ' ', ptr_flag->width), buf, 3);
		}
		else if (ptr_flag->minus == 1)
			buf = ft_strmjoin(buf,\
			ft_memset(ft_strnew(ptr_flag->width), ' ', ptr_flag->width), 3);
	}
	ptr_flag->size_arg = ft_strlen(buf);
	return (buf);
}
