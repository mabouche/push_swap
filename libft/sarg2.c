/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sarg2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:30:40 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/13 17:30:55 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*s_arg_width(t_flag *ptr_flag, char *buf)
{
	int c;

	if (ptr_flag->width >= 0 && (unsigned int)ptr_flag->width > ft_strlen(buf))
	{
		if (ptr_flag->zero == 1)
			c = '0';
		else if (ptr_flag->zero == 0)
			c = ' ';
		ptr_flag->width -= ft_strlen(buf);
		if (ptr_flag->minus == 0)
			buf = ft_strmjoin(ft_memset(ft_strnew(ptr_flag->width),\
						c, ptr_flag->width), buf, 3);
		else if (ptr_flag->minus == 1)
			buf = ft_strmjoin(buf,\
					ft_memset(ft_strnew(ptr_flag->width),\
					c, ptr_flag->width), 3);
	}
	return (buf);
}

char	*s_up_arg_check_tmp(t_flag *ptr_flag, char *buf, wchar_t *tmp)
{
	if (ptr_flag->prec == -2)
		ptr_flag->prec = 0;
	if (tmp == NULL)
	{
		buf = ft_strdup("(null)");
		ptr_flag->size_arg = ft_strlen(buf);
		return (buf);
	}
	if (!ft_strcmp((const char*)tmp, ""))
	{
		buf = ft_strdup("");
		ptr_flag->size_arg = ft_strlen(buf);
		return (buf);
	}
	return (NULL);
}
