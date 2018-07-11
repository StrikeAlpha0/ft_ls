/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:03:31 by msharpe           #+#    #+#             */
/*   Updated: 2018/06/01 10:46:08 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls/libftls.h"
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

void		wub(void)
{
	ori_ft_putstr("Wub");
}

t_ls_struct	g_ls_table[] =
{
	{'r', wub},
	{'R', wub},
	{'l', wub},
	{'a', wub},
	{'t', wub}
};

void		ft_dash_rup(char *path)
{
	DIR *d = opendir(path);
	if (d==NULL) 
		return ;
	struct dirent *dir;
	while ((dir = readdir(d)) != NULL)
	{
		if(dir->d_type != DT_DIR)
		{
			//ft_printf("{green}%s\n",dir->d_type);
			ft_printf("{blue}%s\n", dir->d_name);
		}
		else
			if (dir->d_type == DT_DIR || (ft_strcmp(dir->d_name, ".") || ft_strcmp(dir->d_name, "..") != 0))
			{
				ft_printf("{red}%s\n", dir->d_name);
				char d_path[255];
				ft_printf("%s/%s", path, dir->d_name);
				ft_dash_rup(d_path);
			}
	}
}

int		main(int ac, char **av)
{
	int i;
	int q;
	int lstsearch;
	DIR *d;
	struct dirent *dir;

	d = opendir(".");
	i = 0;
	q = 0;
	lstsearch = 0;
	if (ac == 1)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if(dir->d_type != 4)
				ft_printf("{green}%s\n", dir->d_name);
			else
				if (dir->d_type == 4 && dir->d_type != 0)// && ft_strcmp(dir->d_name, ".") && ft_strcmp(dir->d_name, "..") != 0)
				{
					ft_printf("{red}%s\n", dir->d_name);
					char d_path[255];
					ft_printf("%s", dir->d_name);
				//	ft_dash_rup(d_path);
				}
		}
	/*	if (d)
		{
			while ((dir = readdir(d)) != NULL)
				ft_printf("%s\n", dir->d_name);
			closedir(d);
		}*/
	}
	else if (ac >= 2)
	{
		ft_dash_rup(av[1]);	

	/*	while (av[i] != '\0')
		{
			if (av[1][q] == '-' && q == 0)
			{
				q++;
				while (g_ls_table[lstsearch].name != '\0' && g_ls_table[lstsearch].name != av[1][1])
					lstsearch++;
				if (av[1][1] == g_ls_table[lstsearch].name)
					g_ls_table[lstsearch].function();
				else
					ft_printf("%s\n", av[i]);
				i++;
			}
			ft_printf("%s\n", av[i]);
			i++;
		}*/
	//	apply modifiers or search /directory
	//		if -R, 
	}
}
//	else 
