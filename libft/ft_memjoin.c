/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:04:25 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/06 12:05:13 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void const *s1, void const *s2, size_t l1, size_t l2)
{
	size_t	i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (l1 + l2));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		((char *)str)[i] = ((char *)s1)[i];
		i++;
	}
	while (i < l1 + l2)
	{
		((char *)str)[i] = ((char *)s2)[i - l1];
		i++;
	}
	free((char *)s1);
	free((char *)s2);
	return (str);
}
