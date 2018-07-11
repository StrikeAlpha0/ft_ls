/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:11:08 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/05 23:42:46 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			stuff[i] = f(i, s[i]);
			i++;
		}
	}
	return (stuff);
}
