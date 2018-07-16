/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:01:53 by msharpe           #+#    #+#             */
/*   Updated: 2018/07/16 01:42:57 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftls.h"
#include "libftls/libftprintf.h"
#include "libftls/libft/libft.h"

t_ls_link	*sortedmerge(t_ls_link *a, t_ls_link *b)
{
	t_ls_link *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->path, b->path) < 0)
	{
		result = a;
		result->next = sortedmerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sortedmerge(a, b->next);
	}
	return (result);
}

t_ls_link	*r_sortedmerge(t_ls_link *a, t_ls_link *b)
{
	t_ls_link *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (ft_strcmp(a->path, b->path) > 0)
	{
		result = a;
		result->next = r_sortedmerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = r_sortedmerge(a, b->next);
	}
	return (result);
}

t_ls_link	*t_sortedmerge(t_ls_link *a, t_ls_link *b, t_ls_stru *ls_list)
{
	t_ls_link	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if ((ls_list->r_flag) ? a->time < b->time : a->time > b->time)
	{
		result = a;
		result->next = t_sortedmerge(a->next, b, ls_list);
	}
	else
	{
		result = b;
		result->next = t_sortedmerge(a, b->next, ls_list);
	}
	return (result);
}

void		frontbacksplit(t_ls_link *source,
		t_ls_link **frontref, t_ls_link **backref)
{
	t_ls_link *fast;
	t_ls_link *slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontref = source;
	*backref = slow->next;
	slow->next = NULL;
}

void		merge_sort(t_ls_link **headref, t_ls_stru *ls_list)
{
	t_ls_link *head;
	t_ls_link *a;
	t_ls_link *b;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	frontbacksplit(head, &a, &b);
	merge_sort(&a, ls_list);
	merge_sort(&b, ls_list);
	if (ls_list->t_flag == 1)
		*headref = t_sortedmerge(a, b, ls_list);
	else if (ls_list->r_flag == 0)
		*headref = sortedmerge(a, b);
	else if (ls_list->r_flag == 1)
		*headref = r_sortedmerge(a, b);
}
