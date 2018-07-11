/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 14:37:41 by msharpe           #+#    #+#             */
/*   Updated: 2018/06/24 19:23:24 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftls.h"
#include "../libftls/libftprintf.h"
#include "../libftls/libft/libft.h"

/*t_ls_table		g_flag_table[] =
{
	{'r'}, //reverse(modifiers)
	{'R'}, //Recursive
	{'l'}, //permissions, inode, user, group, bytes, date modded name
	{'a'}, //everything in the directory(modifiers)
	{'t'}, //time modified(organized, not seen)
	{'z'}  //close the table
};
*/
// take ../ft_ls.c file searching system and implement a file checker system in that function. 
// File checker goes through each file and if a directory is found, 
// it is ran as the file path in another instance of the file checker.



void		ft_parse_flags(char *input, t_ls_stru *ls_list)
{
	int i;
	int j;
	char *key;

	j = 0;
	key = "rRlatz";
	while(input[j] != '\0')
	{
		i = 0;
		while((key[i] != 'z') && (key[i] != input[j]))
			i++;
		if(key[i] == input[j])
		/*
		while((g_flag_table[i].name != "z") && (g_flag_table[i].name != input[j]))
			i++;
		if(g_flag_table.name == input[i])*/
		{
			ls_list->flag[ls_list->f_count] = input[i];
			ls_list->f_count++;
		}
		j++;
	}	
}

void		initialize_struct(t_ls_stru *ls_list)
{
	ls_list->f_count = 0;
	ft_bzero(ls_list->flag, 5);
	ls_list->cap_r_flag = 0;
	ls_list->l_flag = 0;
	ls_list->a_flag = 0;
	ls_list->r_flag = 0;
	ls_list->t_flag = 0;
	ls_list->l_list_flag = 0;
	//ls_list->ls_link->path = '\0';
	//ls_list->ls_link->next = NULL;

}


int main(int ac, char **av)
{
	t_ls_stru ls_list;
	int i;

	i = 0;
	initialize_struct(&ls_list);
	if (ac == 1)
		ft_listdirectory(".", &ls_list);
	else if (ac == 2)
	{
		if(av[1][0] == '-')
		{
			//parse it out 5 options needed at minimum
			ft_parse_flags(av[1], &ls_list);
			ft_listdirectory(".", &ls_list);
			//this will apply to the current directory
		}
		else
			ft_listdirectory(av[1], &ls_list);
	}
	else if (ac >= 3)
	{
		if(av[1][0] == '-')
		{
			i = 1;
			ft_parse_flags(av[i++], &ls_list);
			while(av[i] != '\0') //i needs to be set to avoid av0 and av1
				ft_listdirectory(av[i++], &ls_list);
			//parse it out 5 options needed at minimum
		}
		else
		{
			while(av[i++] != '\0')
			{
				ft_printf("{white}\n%s:\n", av[i]);
				ft_listdirectory(av[i], &ls_list);
			}
			ft_printf("Just work through the directories as they are listed");
		}
	}
	return(0);
}		
