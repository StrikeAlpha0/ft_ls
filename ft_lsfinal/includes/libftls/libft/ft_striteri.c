/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:57:29 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/08 16:21:11 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	i = 0;
	if (!s)
		return ;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (!f)
				return ;
			f(i, &s[i]);
			i++;
		}
	}
}
