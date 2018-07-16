/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:01:58 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/09 14:35:16 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*q;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	k = start;
	i = 0;
	j = ft_strlen(s + start);
	q = ft_strnew(len);
	if (!q)
		return (NULL);
	if (q && len)
		while (i < len && s[k])
		{
			q[i] = s[k];
			k++;
			i++;
		}
	return (q);
}
