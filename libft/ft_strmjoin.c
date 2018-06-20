/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:00:38 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/06 12:02:55 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmjoin(const char *s1, const char *s2, int tofree)
{
	char *back;

	back = ft_strjoin(s1, s2);
	if (!back)
		return (NULL);
	if (tofree % 2)
		free((char *)s1);
	if (tofree / 2)
		free((char *)s2);
	return (back);
}
