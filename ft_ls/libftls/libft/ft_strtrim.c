/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:04:29 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/06 00:24:10 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_strlensp(char *str)
{
	int i;
	int j;
	int b;

	j = 0;
	i = 0;
	b = 0;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[j] == ' ' || str[j] == '\t' || str[j] == '\n' || str[j] == '\0')
		j--;
	b = j - i + 1;
	return (b);
}

char				*ft_strtrim(char const *s)
{
	size_t	j;
	size_t	i;
	size_t	k;
	char	*q;

	i = 0;
	k = 0;
	if (!s || s[0] == '\0')
		return ("");
	j = ft_strlensp((char *)s);
	q = ft_strnew(j);
	if (!q)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[i] != '\0' && k < (j))
	{
		q[k] = s[i];
		k++;
		i++;
	}
	q[k] = 0;
	return (q);
}
