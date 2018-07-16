/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftls.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:19:05 by msharpe           #+#    #+#             */
/*   Updated: 2018/02/08 12:13:00 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTLS_H
# define LIBFTLS_H

# include "libftprintf.h"
# include "libft/libft.h"

typedef struct		s_ls_struct
{
	char		name;
	void		(*function)(void);
}					t_ls_struct;

int		main(int ac, char **av);

#endif
