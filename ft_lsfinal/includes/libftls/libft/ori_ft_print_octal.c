/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ori_ft_print_octal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:37:57 by msharpe           #+#    #+#             */
/*   Updated: 2018/05/22 01:30:30 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ori_ft_print_octal(int nbr)
{
	char *oct;
	char i;

	i = 0;
	oct = "01234567";
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr > 16)
		ori_ft_print_octal(nbr / 8);
	i = nbr % 8;
	write(1, oct + i, 1);
	return (nbr);
}
