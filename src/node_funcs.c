/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:18:27 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/15 19:18:27 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*new_node(void *val)
{
	t_node	*node;
	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->val = val;
	node->next = NULL;
	return (node);
}
