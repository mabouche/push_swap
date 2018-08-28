/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:38:46 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/13 17:38:51 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_buff(char **str, char *buf,\
		size_t size_str, size_t size_arg)
{
	if (*str == NULL)
		*str = buf;
	else
		*str = ft_memjoin(*str, buf, size_str, size_arg);
}

const char	*search_specifier(const char *format)
{
	char	*spe;
	int		i;
	int		j;
	char	prct;

	prct = '%';
	i = 1;
	j = -1;
	spe = "sSpdDioOuUxXcC%";
	while (format[i] != '\0')
	{
		while (spe[++j])
		{
			if (format[i] == spe[j])
				return (&format[i]);
		}
		j = 0;
		if (ft_isdigit(format[i]) || format[i] == '.' || format[i] == '#' ||
				format[i] == ' ' || format[i] == '-' || format[i] == 'h' ||
format[i] == 'j' || format[i] == 'z' || format[i] == 'l' || format[i] == '+')
			i++;
		else
			break ;
	}
	return (&format[i]);
}

int			ret_width(const char *format, int i, int j, char *str)
{
	int k;

	while (format[i] && format[i] != '%')
	{
		if (format[i] >= '0' && format[i] <= '9')
			j = i;
		while (format[j] && (format[j] >= '0' && format[j] <= '9'))
			j--;
		if (format[j] != '.' && ft_isdigit(format[j + 1]))
		{
			str = ft_strndup(&format[j + 1], (i - j));
			k = ft_atoi(str);
			free(str);
			return (k);
		}
		else
			i--;
	}
	return (-1);
}
