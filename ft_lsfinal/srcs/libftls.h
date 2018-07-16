/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftls.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:19:05 by msharpe           #+#    #+#             */
/*   Updated: 2018/07/16 00:45:10 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTLS_H
# define LIBFTLS_H

#include <dirent.h>
#include <sys/dir.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct	s_ls_table
{
	char		name[6];
}				t_ls_table;

typedef struct			s_ls_link
{
	char				*path;
	char				*truepath;
	int					value;
	long				time;
	int					cont;
	struct s_ls_link	*next;
}						t_ls_link;

typedef struct			s_ls_stru
{;
	char				*true_path;
	int					cap_r_flag;
	int					a_flag;
	int					l_flag;
	int					r_flag;
	int					t_flag;
	char				flag[5];
	int					yes;
	int					no;
	struct s_ls_link	*erase;
}						t_ls_stru;

void			merge_sort(t_ls_link **head_ref, t_ls_stru *ls_list);
void			ft_listdirectory(char *path, t_ls_stru *ls_list);
void			ft_fullinfo(char *path);
void			recursive_line(char *path,
		t_ls_link *f_start, t_ls_stru *ls_list);
char			*name_combo(char *path, char *name);
t_ls_link		*order_it(char *path, t_ls_stru *ls_list);
t_ls_link		*ft_savedaname(char *path, t_ls_link *head);
t_ls_link		*setll(t_ls_link *head);


#endif
