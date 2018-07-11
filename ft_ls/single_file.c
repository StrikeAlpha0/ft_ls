/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 21:40:11 by msharpe           #+#    #+#             */
/*   Updated: 2018/05/23 21:50:38 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int ac, char **av)
{
	if(ac != 2)
		return (0);

	struct stat hue;
	if (stat(av[1], &hue) < 0)
		return (0);
	
	int yes = 0;
	yes = (S_ISDIR(hue.st_mode)) ? 1 : 0;
	printf("%d", yes);	
	return (0);
}
