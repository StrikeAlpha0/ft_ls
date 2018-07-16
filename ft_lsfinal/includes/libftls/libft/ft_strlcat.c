/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <mauricesharpe06@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:06:35 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/05 23:02:04 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	j = 1;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size < dest_len + 1)
		return (src_len + size);
	if (size > dest_len + 1)
	{
		while (src[i] && (dest_len + i) < (size - j))
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[dest_len + i] = 0;
	}
	return (dest_len + src_len);
}
