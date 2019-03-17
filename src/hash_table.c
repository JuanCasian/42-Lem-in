/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:55:07 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/16 17:55:07 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_hash_table	*hash_new_table(int size)
{
	t_hash_table	*hash;
	int				i;

	if (!(hash = (t_hash_table*)malloc(sizeof(t_hash_table))))
		return (NULL);
	hash->size = size;
	if (!(hash->items = (t_hash_item**)malloc(sizeof(t_hash_item) * size)))
	{
		hash->size = 0;
		free(hash);
		return (NULL);
	}
	i = -1;
	while (++i < size)
		hash->items[i] = NULL;
	return (hash);
}

t_hash_item		*hash_new_item(char key, void *val)
{
	t_hash_item	*item;

	if (!(item = (t_hash_item*)malloc(sizeof(t_hash_item))))
		return (NULL);
	
}