/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:07:45 by mabouche          #+#    #+#             */
/*   Updated: 2018/06/06 12:09:35 by mabouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ABS(v) ((v) < 0 ? -(v) : (v))
#include "libft.h"

void	aux(long long n, int b, char *ans, int *p)
{
	char *base;

	base = "0123456789abcdef";
	if (b <= n || n <= -b)
		aux(n / b, b, ans, p);
	ans[(*p)++] = base[ABS(n % b)];
}

char	*ft_itoa_base(long long value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
			|| !(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	if (base == 10 && value < 0)
		ans[p++] = '-';
	aux(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
