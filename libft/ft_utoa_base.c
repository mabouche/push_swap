/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:19:27 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/06 12:23:48 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ABS(v) ((v) < 0 ? -(v) : (v))
#include "libft.h"

void	auxu(unsigned long long n, int b, char *ans, int *p)
{
	char	*base;

	base = "0123456789abcdef";
	if ((unsigned long long)b <= n)
		auxu(n / b, b, ans, p);
	ans[(*p)++] = base[ABS(n % b)];
}

char	*ft_utoa_base(unsigned long long value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
			|| !(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	auxu(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
