/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:40:42 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/12 17:19:46 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_num_instruct(const char *format, char *conv_spe)
{
	int		i;
	char	conv_char;

	i = 0;
	if (conv_spe != NULL && *conv_spe != '%')
		conv_char = *conv_spe;
	while (format[i] && format[i] != 's' && format[i] != 'S' &&\
			format[i] != 'p' && format[i] != 'd' &&\
			format[i] != 'D' && format[i] != 'i' &&\
			format[i] != 'o' && format[i] != 'O' &&\
			format[i] != 'u' && format[i] != 'U' &&\
			format[i] != 'x' && format[i] != 'X' &&\
			format[i] != 'c' && format[i] != 'C' &&\
			format[i] != '%' && format[i] != 'p' &&
			format[i] != conv_char && format)
		i++;
	return (i);
}

size_t	inc_size(char *buf, size_t size, size_t ptr_size_arg)
{
	if (ft_strcmp("(null)", buf) == 0)
		size += 6;
	else if (ft_strcmp("(null)", buf) != 0)
		size += (ptr_size_arg);
	return (size);
}

int		if_size(t_get_size *t, const char *format, char **res, size_t *size)
{
	if ((int)t->ptr_size_arg == -1)
		return (1);
	if (t->buf)
	{
		add_buff(res, t->buf, *size, t->ptr_size_arg);
		*size = inc_size(t->buf, *size, t->ptr_size_arg);
		t->i += 2;
		t->i += (get_num_instruct(&format[(t->i - 1)], t->conv_spe));
		t->buf = NULL;
		t->j = t->i;
	}
	else
		t->i++;
	t->j = t->i;
	return (0);
}

size_t	get_size(const char *format, char **res, va_list ap, size_t size)
{
	t_get_size t;

	t.conv_spe = ft_memalloc(sizeof(char));
	t.i = 0;
	t.j = 0;
	while (format[t.i])
	{
		while (format[t.i] && format[t.i] != '%')
		{
			t.i++;
			size++;
		}
		t.buf = ft_strsub(format, t.j, t.i - t.j);
		add_buff(res, t.buf, size - ft_strlen(t.buf), (size_t)ft_strlen(t.buf));
		t.buf = NULL;
		if (format[t.i] == '%')
		{
			t.ptr_size_arg = 0;
			t.buf = add_arg(&format[t.i], ap, t.conv_spe, &t.ptr_size_arg);
			if (if_size(&t, format, res, &size))
				return (-1);
		}
	}
	free(t.conv_spe);
	return (size);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	size_t			size;
	char			*res;

	size = 0;
	res = NULL;
	va_start(ap, format);
	size = get_size(format, &res, ap, size);
	if ((int)size == -1)
		return (-1);
	write(1, res, size);
	if (res != 0)
		free(res);
	va_end(ap);
	return ((int)size);
}
