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

/*
** Calculates the index for the hash table
** Params: entry key, hashtable size
** Returns: Index
*/

unsigned int		hash_function(char *key, int size)
{
	unsigned int	hash;
	unsigned int	c;

	hash = 5385;
	while ((c = (int)*key++))
	{
		hash = ((hash << 5) + hash) + c;
	}
	return (hash % size);
}

/*
** Creates a new hashtable
** Params: size of hash table
** Returns: a new hash table
*/

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

/*
** Creates a new item for the hash table
** Params: key for the item, room object
** Returns: new hash item
*/

t_hash_item		*hash_new_item(char *key, t_room *room)
{
	t_hash_item	*item;

	if (!(item = (t_hash_item*)malloc(sizeof(t_hash_item))))
		return (NULL);
	item->key = ft_strdup(key);
	item->room = room;
	item->next = NULL;
	return (item);
}

/*
** Inserts a new item to the hash table
** Params: hash table, item key, room
** Returns: 0 if the item could not be added || 1 if the item was added
*/

int				hash_insert(t_hash_table *table, char *key, t_room *room)
{
	t_hash_item		*item;
	unsigned int	index;
	t_hash_item 	*tmp;

	if (!(item = hash_new_item(key, room)))
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
	table->items[index] = item;
	return (1);	
}

/*
** Searches for an item in the hash table
** Params: hash table, key of the item
** Returs: the item found || null if the item was not found
*/

t_hash_item		*hash_search(t_hash_table *table, char *key)
{
	unsigned int	index;
	t_hash_item		*tmp;
	
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