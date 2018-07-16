/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:03:28 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/06 23:23:44 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	j;
	char	*q;
	size_t	i;
	size_t	w;

	j = 0;
	i = -1;
	w = 0;
	if (!s1 || !s2)
		return (NULL);
	j += ft_strlen(s1);
	j += ft_strlen(s2);
	q = ft_strnew(j + 1);
	if (!q)
		return (NULL);
	while (s1[++i] != '\0')
		q[i] = s1[i];
	w = i;
	i = -1;
	while (s2[++i] != '\0')
		q[w + i] = s2[i];
	return (q);
}
