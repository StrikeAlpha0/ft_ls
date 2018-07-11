/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftls.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:19:05 by msharpe           #+#    #+#             */
/*   Updated: 2018/07/09 13:08:48 by msharpe          ###   ########.fr       */
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
	struct s_ls_link	*next;
}						t_ls_link;

typedef struct			s_alpha
{
	char				*path;
	int					value;
	struct s_alpha		*previous;
	struct s_alpha		*next;
}						t_alpha;

typedef struct			s_ls_stru
{
	int					f_count;
	int					cap_r_flag;
	int					a_flag;
	int					l_flag;
	int					r_flag;
	int					t_flag;
	char				flag[5];
	int					l_list_flag;
}						t_ls_stru;

void			ft_listdirectory(char *path, t_ls_stru *ls_list);
void			ft_fullinfo(char *path, t_ls_stru *ls_list);

#endif
