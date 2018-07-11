/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:54:13 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/08 16:00:37 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*action;
	t_list	*newlst;

	if (!lst)
		return (NULL);
	newlst = f(lst);
	if (!newlst)
		return (NULL);
	action = newlst;
	while (lst && lst->next)
	{
		lst = lst->next;
		if (!(newlst->next = f(lst)))
			return (NULL);
		else
			newlst = newlst->next;
	}
	if (!action)
		return (NULL);
	return (action);
}
