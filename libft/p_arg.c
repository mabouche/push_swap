/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:53:14 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/13 16:54:05 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*p_no_modifier(t_flag *ptr_flag, char *buf)
{
	if (ptr_flag->width == -1 && ptr_flag->prec == -1)
	{
		buf = ft_strmjoin("0x", buf, 2);
		ptr_flag->size_arg = ft_strlen(buf);
		return (buf);
	}
	if (ptr_flag->width == -1 && ptr_flag->prec == -2 && !ft_strcmp(buf, "0"))
	{
		buf = ft_strmjoin(buf, "x", 1);
		ptr_flag->size_arg = ft_strlen(buf);
		return (buf);
	}
	if (ptr_flag->width == -1 && ptr_flag->prec == 0 && !ft_strcmp(buf, "0"))
	{
		buf = ft_strmjoin(buf, "x", 1);
		ptr_flag->size_arg = ft_strlen(buf);
		return (buf);
	}
	else
		return (NULL);
}

char	*p_width_minus_modifier(t_flag *ptr_flag, char *buf)
{
	if (ptr_flag->minus == 0)
	{
		if (ptr_flag->zero == 1)
			buf = ft_strmjoin(buf, ft_memset(ft_strnew(ptr_flag->width)\
						, '0', ptr_flag->width), 3);
		if (ptr_flag->zero == 0)
			buf = ft_strmjoin(ft_memset(ft_strnew(ptr_flag->width)\
						, ' ', ptr_flag->width), buf, 3);
	}
	else if (ptr_flag->minus == 1 && (!ft_strncmp(buf, "0x", 2) ||
				!ft_strncmp(buf, "0x0", 2)))
	{
		buf = ft_strmjoin(buf, ft_memset(ft_strnew(ptr_flag->width)\
					, ' ', ptr_flag->width), 3);
	}
	return (buf);
}

char	*p_width_modifier(t_flag *ptr_flag, char *buf, int pref)
{
	if (ptr_flag->width >= 0 && ptr_flag->width > (int)ft_strlen(buf))
	{
		if ((ptr_flag->prec == -2 || ptr_flag->prec == 0) && pref == 1)
		{
			buf = ft_strmjoin(buf, "x", 1);
			pref = 0;
		}
		else if (pref == 1)
		{
			buf = ft_strmjoin("0x", buf, 2);
			pref = 0;
		}
		ptr_flag->width -= ft_strlen(buf);
		if (ptr_flag->width < 0)
			ptr_flag->width = 0;
		buf = p_width_minus_modifier(ptr_flag, buf);
	}
	if (pref == 1)
		buf = ft_strmjoin("0x", buf, 2);
	return (buf);
}

char	*p_arg(t_flag *ptr_flag, va_list ap, char *buf)
{
	int		pref;
	int		z;
	char	*tmp;

	z = 0;
	pref = 1;
	buf = ft_itoa_base(((unsigned long long)(va_arg(ap, void *))), 16);
	if (!ft_strcmp(buf, "0"))
		z = 1;
	tmp = buf;
	if (NULL == (buf = p_no_modifier(ptr_flag, buf)))
		buf = tmp;
	else
		return (buf);
	if (ptr_flag->prec >= 0 && ptr_flag->prec > (int)ft_strlen(buf))
	{
		ptr_flag->prec -= ft_strlen(buf);
		buf = ft_strmjoin(ft_memset(ft_strnew(ptr_flag->prec),\
					'0', ptr_flag->prec), buf, 3);
		buf = ft_strmjoin("0x", buf, 2);
		pref = 0;
	}
	buf = p_width_modifier(ptr_flag, buf, pref);
	ptr_flag->size_arg = ft_strlen(buf);
	return (buf);
}
