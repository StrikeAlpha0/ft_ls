/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 23:45:59 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/06 12:08:40 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr1;
	char	*ptr2;

	ptr1 = ((char *)dest);
	ptr2 = ((char *)src);
	i = 0;
	while (i < n)
	{
		(*(ptr1 + i)) = (*(ptr2 + i));
		i++;
	}
	return (ptr1);
}
