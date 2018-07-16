/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 20:16:36 by msharpe           #+#    #+#             */
/*   Updated: 2018/07/16 01:41:28 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"
#include "libftls/libftprintf.h"
#include "libftls/libft/libft.h"

void		recursive_line(char *path, t_ls_link *f_start, t_ls_stru *ls_list)
{
	while (f_start->path)
	{
		ft_printf("{white}\n%s:\n", name_combo(path, f_start->path));
		ft_listdirectory(name_combo(path, f_start->path), ls_list);
		if (f_start->next == NULL)
			break ;
		f_start = f_start->next;
	}
	free(f_start);
}

t_ls_link	*ft_savedaname(char *path, t_ls_link *head)
{
	if (path == NULL)
		return (0);
	if (head->path == NULL)
		head->path = ft_strdup(path);
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = (t_ls_link *)malloc(sizeof(t_ls_link));
		head = head->next;
		head->path = ft_strdup(path);
		head->next = NULL;
	}
	return (head);
}

t_ls_link	*setll(t_ls_link *head)
{
	head = (t_ls_link *)malloc(sizeof(t_ls_link));
	head->path = NULL;
	head->next = NULL;
	return (head);
}

char		*name_combo(char *path, char *name)
{
	char *f_name;
	char *s_name;

	f_name = ft_strjoin(path, "/");
	s_name = ft_strjoin(f_name, name);
	return (s_name);
}

t_ls_link	*order_it(char *path, t_ls_stru *ls_list)
{
	struct stat		status;
	struct dirent	*dir;
	DIR				*d;
	t_ls_link		*nhead;
	t_ls_link		*nstart;

	d = opendir(path);
	nhead = NULL;
	if (d == NULL)
		return (0);
	nhead = setll(nhead);
	nstart = nhead;
	while ((dir = readdir(d)) != NULL)
	{
		ls_list->true_path = name_combo(path, dir->d_name);
		lstat(ls_list->true_path, &status);
		ls_list->yes = (S_ISDIR(status.st_mode)) ? 1 : 0;
		nhead = ft_savedaname(dir->d_name, nhead);
		nhead->value = ls_list->yes;
		nhead->time = (status.st_ctime);
	}
	merge_sort(&nstart, ls_list);
	closedir(d);
	return (nstart);
}
