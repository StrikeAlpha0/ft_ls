/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_staging.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 03:17:49 by msharpe           #+#    #+#             */
/*   Updated: 2018/06/04 03:38:33 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_staging(char *path, t_ls_stru *ls_list)
{
	int i;

	i = 2;
	if(ac == 1)
		ft_listdirectory(".", &ls_list);
	else if(ac == 2)
	{
		if(av[1][0] == '-')
		{
			ft_parse_flags(av[1], &ls_list);
			ft_listdirectory(".", &ls_list);
		}
		else
			ft_listdirectory(av[1], &ls_list);
	}
	else if(ac > 2)
	{
		if(av[1][0] == '-')
		{
			ft_parse_flags(av[1], &ls_list);
			while(i < ac)
				ft_listdirectory(av[i], &ls_list);
		}
		else
		{
			while(av[i++] != '\0')
			{
				ft_printf
			

}
