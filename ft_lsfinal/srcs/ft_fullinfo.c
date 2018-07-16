/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:48:22 by msharpe           #+#    #+#             */
/*   Updated: 2018/07/16 01:42:13 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"
#include "libftls/libftprintf.h"
#include "libftls/libft/libft.h"
#include <time.h>
#include <grp.h>
#include <pwd.h>

char		*parse_time(char *time)
{
	char	*want;
	int		i;
	int		j;

	want = (char *)malloc(sizeof(char) * ft_strlen(time));
	i = 4;
	j = 0;
	while (i < 16)
	{
		want[j] = time[i];
		j++;
		i++;
	}
	want[j] = '\0';
	return (want);
}

void		most_info(struct stat *stuff)
{
	ft_printf((stuff->st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((stuff->st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((stuff->st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((stuff->st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((stuff->st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((stuff->st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((stuff->st_mode & S_IROTH) ? "r" : "-");
	ft_printf((stuff->st_mode & S_IWOTH) ? "w" : "-");
}

/*
** Used to gather file information and display it
*/

void		ft_fullinfo(char *path)
{
	struct stat		information;
	struct group	*gp;
	struct passwd	*pw;

	if (lstat(path, &information) < 0)
		return ;
	gp = getgrgid(information.st_gid);
	pw = getpwuid(information.st_uid);
	if (S_ISLNK(information.st_mode))
		ft_printf("{magenta}l");
	else
		ft_printf((S_ISDIR(information.st_mode)) ? "{white}d" : "{white}-");
	most_info(&information);
	if (S_ISVTX & information.st_mode)
		ft_printf((information.st_mode & S_ISVTX) ? "t" : "-");
	else
		ft_printf((information.st_mode & S_IXOTH) ? "x" : "-");
	ft_printf("  %d ", information.st_nlink);
	ft_printf("%s  ", pw->pw_name);
	ft_printf("%s  ", gp->gr_name);
	ft_printf("% 9lld\t ", information.st_size);
	ft_printf(" %s  ", parse_time(ctime(&information.st_ctime)));
}
