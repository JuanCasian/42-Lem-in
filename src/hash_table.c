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

int				hash_function(char *key, int size)
{
	int	hash;
	int	c;

	hash = 5385;
	while (c = (int)*key++)
	{
		hash = ((hash << 5) + hash) + c;
	}
	return (hash / size);
}

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

t_hash_item		*hash_new_item(char *key, void *val)
{
	t_hash_item	*item;

	if (!(item = (t_hash_item*)malloc(sizeof(t_hash_item))))
		return (NULL);
	item->key = key;
	item->val = val;
	item->next = NULL;
	return (item);
}

int				hash_insert(t_hash_table *table, char *key, void *val)
{
	t_hash_item	*item;
	int			index;
	t_hash_item *tmp;

	if (!(item = hash_new_item(key, val)))
		return (0);
	index = hash_function(key, table->size);
	tmp = table->items[index];
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			free(item);
			return (0);
		}
		tmp = tmp->next;
	}
	item->next = table->items[index];
	table->items[index] = item->next;
	return (1);	
}

t_hash_item		hash_search(t_hash_table *table, char *key)
{
	int			index;
	t_hash_item	*tmp;
	
	index = hash_function(key, table->size);
	tmp = table->items[index];
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}