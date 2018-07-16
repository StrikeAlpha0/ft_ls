/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <mauricesharpe06@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:20:17 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/05 19:52:59 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	const char		*q;
	size_t			i;

	i = 0;
	q = (const char *)s;
	while (i < n)
	{
		if ((unsigned char)c == ((unsigned char)q[i]))
			return ((void *)(q + i));
		i++;
	}
	return (NULL);
}
