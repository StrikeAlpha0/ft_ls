/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdirectory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:27:42 by msharpe           #+#    #+#             */
/*   Updated: 2018/07/16 01:42:36 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"
#include "libftls/libftprintf.h"
#include "libftls/libft/libft.h"

void			file_check(char *path, t_ls_link *n_start, t_ls_stru *ls_list)
{
	if (ls_list->a_flag == 1)
	{
		if (ls_list->l_flag == 1)
			ft_fullinfo(name_combo(path, n_start->path));
		ft_printf("{white}%s\n", n_start->path);
	}
	else if (n_start->path[0] != '.')
	{
		if (ls_list->l_flag == 1)
			ft_fullinfo(name_combo(path, n_start->path));
		ft_printf("{white}%s\n", n_start->path);
	}
}

void			directory_check(char *path, t_ls_link *n_start,
		t_ls_link *r_start, t_ls_stru *ls_list)
{
	if (n_start->value == 1 && n_start->path[0] != '.')
	{
		if (ls_list->l_flag == 1)
			ft_fullinfo(name_combo(path, n_start->path));
		if (ls_list->cap_r_flag == 1)
			r_start = ft_savedaname(n_start->path, r_start);
		ft_printf("{cyan}%s\n", n_start->path);
	}
	else if (ls_list->a_flag == 1 && n_start->value == 1)
	{
		if (ls_list->l_flag == 1)
			ft_fullinfo(name_combo(path, n_start->path));
		ft_printf("{cyan}%s\n", n_start->path);
	}
}

void			delete_list(t_ls_link **head_ref)
{
	t_ls_link	*current;
	t_ls_link	*next;

	current = *head_ref;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head_ref = NULL;
}

void			ft_listdirectory(char *path, t_ls_stru *ls_list)
{
	t_ls_link *n_start;
	t_ls_link *r_start;
	t_ls_link *f_start;

	r_start = NULL;
	r_start = setll(r_start);
	f_start = r_start;
	n_start = order_it(path, ls_list);
	ls_list->erase = n_start;
	while (n_start != NULL)
	{
		if (n_start->value == 1)
			directory_check(path, n_start, r_start, ls_list);
		else if (n_start->value != 1)
			file_check(path, n_start, ls_list);
		n_start = n_start->next;
	}
	delete_list(&ls_list->erase);
	if (ls_list->cap_r_flag == 1)
		recursive_line(path, f_start, ls_list);
}
