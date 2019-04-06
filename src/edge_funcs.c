/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:51:44 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/06 14:51:44 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_edge	*new_edge(t_room *end)
{
	t_edge *edge;

	if (!(edge = (t_edge*)malloc(sizeof(t_edge))))
		return (NULL);
	edge->room = end;
	edge->next = NULL;
	return (edge);
}
