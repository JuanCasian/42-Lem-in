/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:34:27 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/24 19:34:27 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	free_split(char ***obj)
{
	int i;
	
	i = -1;
	while ((*obj)[++i])
	{
		free((*obj)[i]);
		(*obj)[i] = NULL;
	}
	free((*obj));
}

t_room		*new_room(char *str)
{
	t_room	*room;
	char	**info;

	if (!(room = (t_room*)malloc(sizeof(t_room))) ||
		!(info = ft_strsplit(str, ' ')))
		return (NULL);
	if (!(room->name = ft_strdup(info[0])))
	{
		free(room);
		free_split(&info);
		return (NULL);
	}
	room->x = ft_atoi(info[1]);
	room->y = ft_atoi(info[2]);
	room->edge = NULL;
	room->visited = 0;
	room->selected = 0;
	room->parent = NULL;
	return (room);
}
