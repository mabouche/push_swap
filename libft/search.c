/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:35:20 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/13 17:35:26 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		search_width(const char *format, char conv)
{
	int		i;
	int		j;
	char	*str;

	str = NULL;
	i = 1;
	j = 0;
	while (format[i] != '\0' && format[i] != conv)
		i++;
	i -= 1;
	if (format[i] == '.')
		i--;
	if (format[i] == '%')
		return (-1);
	return (ret_width(format, i, j, str));
}

int		ret_prec(const char *format, int i, int j, char *str)
{
	int k;

	while (format[i] && format[i] != *format)
	{
		if (format[i] >= '0' && format[i] <= '9')
			j = i;
		while (format[j] && format[j] != '.' && (format[j]\
					>= '0' && format[j] <= '9'))
			j--;
		if (format[j] == '.')
		{
			if (format[j + 1] >= '0' && format[j + 1] <= '9')
			{
				str = ft_strndup(&format[j + 1], ((i + 1) - j));
				k = ft_atoi(str);
				free(str);
				return (k);
			}
			else
				return (-2);
		}
		else
			i--;
	}
	return (-1);
}

int		search_prec(const char *format, char conv)
{
	int		i;
	int		j;
	char	*str;
	char	*str2;

	i = 1;
	j = 0;
	str = NULL;
	while (format[i] && format[i] != conv)
		i++;
	str2 = ft_strsub(format, 0, i);
	i -= 1;
	str = ft_strchr(str2, '.');
	if (format[i] == '.')
		return (-2);
	if (str != NULL)
	{
		str++;
		if (!ft_isdigit(str[0]))
			return (-2);
	}
	free(str2);
	return (ret_prec(format, i, j, str));
}

void	flag_list(const char *format, t_flag *ptr_flag, int i)
{
	if (format[i] == '#')
		ptr_flag->sharp = 1;
	if (format[i] == ' ')
		ptr_flag->space = 1;
	if (format[i] == '-')
		ptr_flag->minus = 1;
	if (format[i] == '+')
		ptr_flag->plus = 1;
	if (format[i] == 'h' && format[i + 1] != 'h')
		ptr_flag->h = 1;
	if (format[i] == 'h' && format[i + 1] == 'h')
		ptr_flag->hh = 1;
	if (format[i] == 'l' && format[i + 1] != 'l')
		ptr_flag->l = 1;
	if (format[i] == 'l' && format[i + 1] == 'l')
		ptr_flag->ll = 1;
	if (format[i] == 'j')
		ptr_flag->j = 1;
	if (format[i] == 'z')
		ptr_flag->z = 1;
}

char	search_flag(const char *format, t_flag *ptr_flag, char conv)
{
	const char	*spe;
	int			i;

	i = 1;
	spe = search_specifier(format);
	conv = '\0';
	if (spe != NULL)
	{
		conv = *spe;
		ptr_flag->prec = search_prec(format, conv);
		ptr_flag->width = search_width(format, conv);
		while (format[i] != *spe)
		{
			flag_list(format, ptr_flag, i);
			if (format[i] == '0')
			{
				if (format[i - 1] == '%' || format[i - 1] == ' ' ||
						format[i - 1] == '#' || format[i - 1] == '+' ||
						format[i - 1] == ' ')
					ptr_flag->zero = 1;
			}
			i++;
		}
	}
	return (conv);
}
