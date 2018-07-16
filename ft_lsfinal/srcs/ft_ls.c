/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 14:37:41 by msharpe           #+#    #+#             */
/*   Updated: 2018/07/16 01:37:36 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"
#include "libftls/libftprintf.h"
#include "libftls/libft/libft.h"

/*
** r - reverse
** R - recursive
** l - permissions, inode, user, group, bytes, date modded name
** a - everything in the directory(modifiers)
** t - time modified(organized, not seen)
** z - close the table
*/

void		ft_parse_flags(char *input, t_ls_stru *ls_list)
{
	int		i;
	int		j;
	char	*key;

	j = 0;
	key = "rRlatz";
	while (input[j] != '\0')
	{
		i = 0;
		while ((key[i] != 'z') && (key[i] != input[j]))
			i++;
		if (key[i] == input[j])
		{
			ls_list->r_flag |= (key[i] == 'r') ? 1 : 0;
			ls_list->cap_r_flag |= (key[i] == 'R') ? 1 : 0;
			ls_list->l_flag |= (key[i] == 'l') ? 1 : 0;
			ls_list->a_flag |= (key[i] == 'a') ? 1 : 0;
			ls_list->t_flag |= (key[i] == 't') ? 1 : 0;
		}
		j++;
	}
}

void		initialize_struct(t_ls_stru *ls_list)
{
	ft_bzero(ls_list->flag, 5);
	ls_list->cap_r_flag = 0;
	ls_list->l_flag = 0;
	ls_list->a_flag = 0;
	ls_list->r_flag = 0;
	ls_list->t_flag = 0;
}

void		two_options(char *path, t_ls_stru *ls_list)
{
	int	i;

	i = 0;
	if (path[0] == '-')
	{
		ft_parse_flags(path, ls_list);
		ft_listdirectory(".", ls_list);
	}
	else
		ft_listdirectory(path, ls_list);
}

int			main(int ac, char **av)
{
	t_ls_stru	ls_list;
	int			i;

	i = 1;
	initialize_struct(&ls_list);
	if (ac == 1)
		ft_listdirectory(".", &ls_list);
	else if (ac == 2)
		two_options(av[1], &ls_list);
	else if (ac >= 3)
	{
		while (i < ac)
		{
			if (av[1][0] == '-')
				ft_parse_flags(av[i++], &ls_list);
			while (av[i] != '\0')
			{
				ft_printf("{white}\n%s:\n", av[i]);
				ft_listdirectory(av[i++], &ls_list);
			}
		}
	}
	return (0);
}
