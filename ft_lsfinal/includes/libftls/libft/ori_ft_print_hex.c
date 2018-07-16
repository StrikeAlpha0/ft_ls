/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:37:57 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/08 00:27:52 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ori_ft_print_hex(int nbr)
{
	char *hex;
	char i;

	i = 0;
	hex = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr > 16)
		ori_ft_print_hex(nbr / 16);
	i = nbr % 16;
	write(1, hex + i, 1);
	return (nbr);
}
