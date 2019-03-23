/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:18:38 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/15 19:18:38 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Creates a new node 
** params: string
** returns: new node <t_node>
*/

t_node	*new_node(char *val)
{
	t_node	*node;
	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->val = ft_strdup(val);
	node->next = NULL;
	return (node);
}

/*
** params: none
** return: new linked list
*/

t_linked	*new_linked(void)
{
	t_linked	*list;
	
	if (!(list = (t_linked*)malloc(sizeof(t_linked))))
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->len = 0;
	return (list);
}

/*
** adds node to the front of the linked list
** params: list, node to add
** return: 1 if successful || 0 if failed to add it
*/

int			add_fnode(t_linked *list, t_node *node)
{
	if (!list || !node)
		return (0);
	if (!list->head || !list->tail)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		node->next = list->head;
		list->head = node;
	}
	list->len += 1;
	return (1);
}

/*
** adds node to the end of the linked list
** params: list, node to add
** return: 1 if successful || 0 if failed to add it
*/

int			add_bnode(t_linked *list, t_node *node)
{
	if (!list || !node)
		return (0);
	if (!list->head || !list->tail)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
	list->len += 1;
	return (1);
}

/*
** Pops the node of the front of the linked list
** params: linked list pointer
** returns: node pointer
*/

t_node		*fpop(t_linked *list)
{
	t_node	*tmp;
	
	tmp = list->head;
	if (list->tail && list->head == list->tail)
		list->tail = list->tail->next;
	if (list->head)
		list->head = list->head->next;
	list->len -= 1;
	if (list->len < 0)
		list->len = 0;
	return (tmp);
}
