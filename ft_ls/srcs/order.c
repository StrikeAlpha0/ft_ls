/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 20:16:36 by msharpe           #+#    #+#             */
/*   Updated: 2018/07/10 21:34:17 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_ls_link	*ft_savedaname(char *path, t_ls_link *head)
{
	if(head->path == NULL)
		head->path = path;
	else if(head->path != '\0')
	{
		while(head->next != NULL)
			head = head->next;
		head->next = (t_ls_link *)malloc(sizeof(t_ls_link));
		head = head->next;
		head->path = (char *)malloc(sizeof(char) * ftstrlen(path));
		head->path = path;
		head->next = NULL;
	}
	return(head);
}

t_ls_link *setll(t_ls_link *head)
{
	head->path = NULL;
	head->next = NULL;
	return(head);
}

char		*name_combo(char *path, char *name)
{
	char *f_name;
	char *s_name;

	f_name = ft_strjoin(path, "/");
	s_name = ft_strjoin(f_name, name); 
	return (s_name);
}

t_ls_link	order_it(char *path, t_ls_stru *ls_list)
{
	char	*true_path;
	int		yes;
	DIR		*d;
	t_alpha *nhead;
	t_alpha *nstart;
	
	d = opendir(path);
	nhead = setll(nhead);
	nstart = nhead;

	while((dir = readdir(d)) != NULL)
	{
		true_path = name_combo(path, dir->d_name);
		stat(bits, &status);
		yes = (S_ISDIR(status.st_mode)) ? 1 : 0;
		nhead = ft_savedaname(bits, ls_list, head);
		nhead->value = yes; 
	}
	mergesort(&nstart);
	return(nstart);
	//organize linked list mergesort function is written
	//send it back to ft_listdirectory to be "parsed". This should be it.
}
