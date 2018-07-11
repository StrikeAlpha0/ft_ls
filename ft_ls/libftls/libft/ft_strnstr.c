/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <mauricesharpe06@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:05:16 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/06 00:26:11 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		it;
	int		size;
	int		j;

	i = 0;
	size = ft_strlen(haystack);
	it = ft_strlen(needle);
	if (it == 0)
		return (char *)(haystack);
	while ((int)i < size - it + 1 && i < len)
	{
		j = 0;
		while (j < it && i + j < len)
		{
			if (haystack[i + j] != needle[j])
				break ;
			if (j == it - 1)
				return (char *)(haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
