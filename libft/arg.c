/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:48:23 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/13 16:49:26 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*init_struct(void)
{
	t_flag *ptr_flag;

	ptr_flag = (t_flag*)ft_memalloc(sizeof(t_flag));
	if (ptr_flag == NULL)
		return (NULL);
	ptr_flag->minus = 0;
	ptr_flag->space = 0;
	ptr_flag->sharp = 0;
	ptr_flag->plus = 0;
	ptr_flag->zero = 0;
	ptr_flag->h = 0;
	ptr_flag->hh = 0;
	ptr_flag->l = 0;
	ptr_flag->ll = 0;
	ptr_flag->j = 0;
	ptr_flag->z = 0;
	ptr_flag->width = -1;
	ptr_flag->prec = -1;
	ptr_flag->size_arg = 0;
	return (ptr_flag);
}

char	*choose_arg(va_list ap, char *buf, t_flag *ptr_flag, char *conv_spe)
{
	if (ptr_flag->conv == 'S')
		buf = s_up_arg(ptr_flag, ap, buf);
	else if (ptr_flag->conv == 's')
		buf = s_arg(ptr_flag->conv, ptr_flag, ap, buf);
	else if (ptr_flag->conv == 'd' || ptr_flag->conv == 'i' ||
ptr_flag->conv == 'u' || ptr_flag->conv == 'o' || ptr_flag->conv == 'x'
			|| ptr_flag->conv == 'X' || ptr_flag->conv == 'O' ||
			ptr_flag->conv == 'D' || ptr_flag->conv == 'U')
		buf = int_arg(ptr_flag->conv, ap, buf, ptr_flag);
	else if (ptr_flag->conv == 'C')
		buf = c_up_arg(ptr_flag, ap, buf);
	else if (ptr_flag->conv == 'c')
		buf = c_arg(ptr_flag, ap, buf);
	else if (ptr_flag->conv == '%')
		buf = prct_arg(ptr_flag, buf, '%');
	else if (ptr_flag->conv == 'p')
		buf = p_arg(ptr_flag, ap, buf);
	else if (ptr_flag->conv == '\0')
		buf = NULL;
	else
	{
		buf = prct_arg(ptr_flag, buf, ptr_flag->conv);
		*conv_spe = ptr_flag->conv;
	}
	return (buf);
}

char	*add_arg(const char *format, va_list ap,\
		char *conv_spe, size_t *ptr_size_arg)
{
	char	*buf;
	t_flag	*ptr_flag;

	buf = NULL;
	ptr_flag = init_struct();
	ptr_flag->conv = '\0';
	ptr_flag->conv = search_flag(format, ptr_flag, ptr_flag->conv);
	buf = choose_arg(ap, buf, ptr_flag, conv_spe);
	*ptr_size_arg = ptr_flag->size_arg;
	free(ptr_flag);
	return (buf);
}
