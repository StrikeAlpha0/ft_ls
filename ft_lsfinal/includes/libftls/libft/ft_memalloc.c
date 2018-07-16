/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <mauricesharpe06@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:58:06 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/09 14:35:31 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*q;

	q = (void *)malloc(size);
	if (q)
		ft_bzero(q, size);
	return (q);
}
