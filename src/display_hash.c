/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:14:44 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/22 16:14:44 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	hash_display(t_hash_table *table)
{
	t_hash_item *tmp;
	t_edge		*tmp_e;
	int			i;

	i = -1;
	while (++i < table->size)
	{
		if (table->items[i] != NULL)
		{
			tmp = table->items[i];
			while (tmp)
			{
				ft_printf("(index: %i)\t[%s]\t\t%p\n", i, tmp->key, tmp->room);
				tmp_e = tmp->room->edges;
				ft_printf("Edges:");
				while (tmp_e)
				{
					ft_printf("\t%p", tmp_e->room);
					tmp_e = tmp_e->next;
				}
				ft_printf("\n\n");
				tmp = tmp->next;
			}
		}
	}
}
