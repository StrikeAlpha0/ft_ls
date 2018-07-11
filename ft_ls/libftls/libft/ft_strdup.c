/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <mauricesharpe06@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:04:30 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/06 00:33:47 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		s1_length;
	char	*mems;

	s1_length = ft_strlen(s1);
	mems = (char *)malloc(sizeof(*s1) * (s1_length + 1));
	if (mems == 0)
		return (NULL);
	ft_strcpy(mems, s1);
	return (mems);
}
