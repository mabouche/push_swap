/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:26:38 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/13 17:26:48 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*s_up_arg_undefined(t_flag *ptr_flag, char *temp2)
{
	if (!ft_strcmp(temp2, "UNDEFINED"))
	{
		ptr_flag->size_arg = -1;
		free(temp2);
		return (NULL);
	}
	return (temp2);
}

char	*s_up_arg_check_tmp2(t_flag *ptr_flag, char *buf, wchar_t *tmp)
{
	char *temp2;

	temp2 = ft_unicode(tmp[1]);
	if (!ft_strcmp(temp2, "UNDEFINED"))
	{
		ptr_flag->size_arg = -1;
		buf = NULL;
	}
	if (ft_strlen(temp2) <= (unsigned int)ptr_flag->prec)
		buf = ft_strmjoin("", ft_unicode(tmp[0]), 2);
	else
		buf = ft_strdup("");
	free(temp2);
	return (buf);
}

char	*s_up_arg_create_buf(t_flag *ptr_flag, char *buf, wchar_t *tmp)
{
	char	*temp2;
	int		i;
	int		y;

	i = 1;
	while (tmp[i])
	{
		temp2 = ft_unicode(tmp[i]);
		if (s_up_arg_undefined(ptr_flag, temp2) == NULL)
			return (NULL);
		if (ptr_flag->prec >= 0)
		{
			y = ft_strlen(temp2) + ft_strlen(buf);
			if (y <= ptr_flag->prec)
				buf = ft_strmjoin(buf, temp2, 3);
			else
				break ;
		}
		else
			buf = ft_strmjoin(buf, temp2, 3);
		i++;
	}
	i = ptr_flag->size_arg;
	return (buf);
}

char	*s_up_arg(t_flag *ptr_flag, va_list ap, char *buf)
{
	wchar_t	*tmp;

	tmp = va_arg(ap, wchar_t*);
	buf = s_up_arg_check_tmp(ptr_flag, buf, tmp);
	if (buf)
		return (buf);
	buf = s_up_arg_check_tmp2(ptr_flag, buf, tmp);
	if (buf == NULL)
		return (buf);
	buf = s_up_arg_create_buf(ptr_flag, buf, tmp);
	if (buf == NULL)
		return (buf);
	if (ptr_flag->prec >= 0 && (unsigned int)ptr_flag->prec < ft_strlen(buf))
	{
		while ((int)ptr_flag->size_arg < ptr_flag->prec)
			ptr_flag->size_arg++;
		buf[ptr_flag->size_arg] = '\0';
	}
	buf = s_arg_width(ptr_flag, buf);
	ptr_flag->size_arg = ft_strlen(buf);
	return (buf);
}

char	*s_arg(char conv, t_flag *ptr_flag, va_list ap, char *buf)
{
	int i;

	i = 0;
	if (ptr_flag->l == 1)
		return (s_up_arg(ptr_flag, ap, buf));
	if (conv == 's')
		buf = ft_strdup(va_arg(ap, char *));
	if (buf == NULL)
		buf = ft_strdup("(null)");
	if (ptr_flag->prec == -2)
		ptr_flag->prec = 0;
	if (ptr_flag->prec >= 0 && (unsigned int)ptr_flag->prec < ft_strlen(buf))
	{
		while (i < ptr_flag->prec)
			i++;
		buf[i] = '\0';
	}
	buf = s_arg_width(ptr_flag, buf);
	ptr_flag->size_arg = ft_strlen(buf);
	return (buf);
}
