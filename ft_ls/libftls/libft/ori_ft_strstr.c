/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ori_ft_strstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 23:07:53 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/08 00:37:43 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ori_ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int it;
	int size;
	int j;

	i = 0;
	size = ft_strlen(haystack);
	it = ft_strlen(needle);
	if (it == 0)
		return (char *)(haystack);
	while (i < size - it + 1)
	{
		j = 0;
		while (j < it)
		{
			if (haystack[i + j] != needle[j])
				break ;
			if (j == it - 1)
				while ((char *)(haystack + i) != '\0')
					return (char *)(haystack + i++);
			j++;
		}
		i++;
	}
	return (NULL);
}
