/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:05:41 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/06 00:23:30 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlength(int n)
{
	int	i;

	i = 1;
	n /= 10;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		*ft_runit(int n, char *q, size_t length, int sign)
{
	size_t	j;

	j = 1;
	while (length >= j && (sign != -1 || length > j))
	{
		q[length - j] = ((n % 10) + '0');
		n /= 10;
		j++;
	}
	return (q);
}

char			*ft_itoa(int n)
{
	size_t	length;
	char	*q;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
		length++;
	}
	length += ft_intlength(n);
	if (!(q = ft_strnew(length)))
		return (NULL);
	if (sign == -1)
		q[0] = '-';
	if (q)
		ft_runit(n, q, length, sign);
	return (q);
}
