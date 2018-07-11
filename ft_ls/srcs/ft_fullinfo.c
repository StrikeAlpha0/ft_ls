/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:48:22 by msharpe           #+#    #+#             */
/*   Updated: 2018/06/20 11:04:20 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftls.h"
#include "../libftls/libftprintf.h"
#include "../libftls/libft/libft.h"
#include <time.h>

/*
** Used to gather file information and display it
*/
void		ft_fullinfo(char *path, t_ls_stru *ls_list)
{
	struct stat information;
	struct tm timer;

	if(stat(path, &information) < 0)
		return ;
	ft_printf("{white}\0");
	ft_printf((S_ISDIR(information.st_mode)) ? "d" : "-");
	ft_printf((information.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((information.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((information.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((information.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((information.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((information.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((information.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((information.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((information.st_mode & S_IXOTH) ? "x" : "-");
	ft_printf("  %d  ", information.st_nlink);
	ft_printf("%s  ", information.st_gid);
	ft_printf("%s  ", information.st_mtime);
	//ft_printf(month folder);
	ft_printf("\t%lld\t", information.st_size);
	ft_printf("%s  ", timer.tm_mon); //month
	ft_printf("%2d ", timer.tm_mday); //numerical day of the week
	ft_printf("%2d:%2d ", timer.tm_hour, timer.tm_min);
}
