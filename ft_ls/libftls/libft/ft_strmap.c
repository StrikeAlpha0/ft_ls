/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:18:35 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/06 00:27:32 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*stuff;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	stuff = ft_strnew(j);
	if (stuff)
	{
		while (s[i] != '\0')
		{
			stuff[i] = f(s[i]);
			i++;
		}
	}
	return (stuff);
}
