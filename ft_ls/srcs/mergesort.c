/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:01:53 by msharpe           #+#    #+#             */
/*   Updated: 2018/07/10 19:31:54 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct Node* SortedMerge(struct Node* a, struct Node*b)
{
	struct Node* result = NULL;

	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);

	if(a->data <= b->data)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return(result);
}

void		FrontBackSplit(struct Node* source, struct Node **frontref, struct Node** backRef)
{
	struct Node* fast;
	struct Node* slow;

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
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

void		push(struct Node** head_ref, int new_data)
{
	struct Node* new node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void		MergeSort(struct Node** headRef)
{
	struct Node* head = *headRef;
	struct Node* a;
	struct Node* b;

	if((head == NULL) || (head->next == NULL))
		return ;
	FrontBackSplit(head, &a, &b);
	MergeSort(&a);
	MergeSort(&b);

	*headRef = SortedMerge(a, b);
}
