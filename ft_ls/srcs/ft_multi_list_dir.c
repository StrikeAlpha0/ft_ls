/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_list_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 03:16:12 by msharpe           #+#    #+#             */
/*   Updated: 2018/06/04 15:43:45 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_multi_list_dir(char *path, t_ls_stru *ls_list)
{
	int yes;
	int why
	DIR *d = opendir(path);
	if (d == NULL)
		return ;
	//ls_list->a_flag = 1;
	//ls_list->l_flag = 1;
	struct dirent	*dir;
	struct stat		status;
	char 			*true_path;

	while((dir = readdir(d)) != NULL) // read directory going forward
	{
		true_path = ft_strjoin(path, dir->d_name);
		//true_path = "./";
		//ft_printf("{magenta}I'm working!");
		/*if ((why = stat(dir->d_name, &status)) != 0)// replace dir->d_name with true_path to search outside of the directory!*/
		if((why = stat(true_path, &status)) != 0)
		{
			ft_printf("{red}I'm cutting out here!");
			ft_printf("%d ", why);
			ft_printf("%s ", true_path);
			ft_printf("%s", dir->d_name);
			return ;
		}
		yes = (S_ISDIR(status.st_mode)) ? 1 : 0;
		//ft_printf("{blue}%d", yes);
		//ft_printf("{red}%d", why);
		//if (ls_list->l_flag == 1)//need to prevent . and .. text from printing
		//	ft_fullinfo(dir->d_name, ls_list);
		if (yes == 1 && dir->d_name[0] != '.')
		{
		//	ft_savedaname(dir->d_name)//add "filename" to linked list
			if(ls_list->l_flag == 1)
				//ft_fullinfo(dir->d_name, ls_list);
				ft_fullinfo(true_path, ls_list);
			ft_printf("{cyan}%s\n", dir->d_name);
		}
		else if(ls_list->a_flag == 1 && yes == 1)
		{
			if(ls_list->l_flag == 1)
				//ft_fullinfo(dir->d_name, ls_list);
				ft_fullinfo(true_path, ls_list);
			ft_printf("{cyan}%s\n", dir->d_name);
		}
		else if(ls_list->a_flag == 1) //a_flag is present
		{
			if(ls_list->l_flag == 1)
				//ft_fullinfo(dir->d_name, ls_list);
				ft_fullinfo(true_path, ls_list);
			ft_printf("{red}%s\n", dir->d_name);
		}
		else if(dir->d_name[0] != '.') //no flag is present
		{	if(ls_list->l_flag == 1)
				//ft_fullinfo(dir->d_name, ls_list);
				ft_fullinfo(true_path, ls_list);
			ft_printf("{red}%s\n", dir->d_name);
		}
	}
	closedir(d);
	/*if(cap_r_flag == 1 && ls_link->next != NULL)
		ft_listdirectory(ls_link->path);;
}
