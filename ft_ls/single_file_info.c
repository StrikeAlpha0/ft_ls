/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_file_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:59:32 by msharpe           #+#    #+#             */
/*   Updated: 2018/05/31 01:14:34 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<dirent.h>
#include	"libftls/libftprintf.h"
#include	<sys/dir.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>

/*
** so if the directory test returns 1, that file should set as a directory to use the "ls" function there as well. If nothing  
*/

int		listdir(const char *path)
{
	struct dirent *entry;
	struct stat door;
	DIR *dp;
	dp = opendir(path);
	int yes;
	yes = 0;
	if (dp == NULL)
	{
		perror("opendir");
		return(-1);
	}
	//need to perform a quick cycle through current directory to check for other folders that might be present.
	//each folder gets added to a list with their path. 
	while((entry = readdir(dp)))
	{
		if (stat(entry->d_name, &door) < 0)
			return(0);
		yes = (S_ISDIR(door.st_mode)) ? 1 : 0;
		if (yes == 1 && entry->d_name[0] != '.') 
			ft_printf("{cyan}%s\n",entry->d_name);
		else if(entry->d_name[0] != '.') //this condition leads to a flat ls call. Remove it for 'a' tag.
		{
			ft_printf("{red}%s\n", entry->d_name);
			//ft_printf("{green}%X\n", door->st_mode);
		}	
		//printf("%d\n", yes);
	}
	closedir(dp);
	return(0);
}

int main(int ac, char **av)
{
	int counter = 1;
	if (ac == 1)
		listdir(".");

	while (++counter <= ac) {
		printf("\nListing %s...\n", av[counter-1]);
		listdir(av[counter-1]);
	}
	return(0);
}
