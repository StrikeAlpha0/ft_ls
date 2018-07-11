/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 22:40:44 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/05 22:41:50 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s1, int c)
{
	int i;
	int s1_len;

	s1_len = ft_strlen(s1) + 1;
	i = s1_len;
	while (--i >= 0)
	{
		if (s1[i] == (char)c)
			return ((char *)s1 + i);
	}
	return (NULL);
}
