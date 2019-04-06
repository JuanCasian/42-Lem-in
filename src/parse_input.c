/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:07:44 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/23 13:07:44 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Gets the number of ants needed for the problem
** Params: None
** Returns: number of ants || -1 in case of error
*/

static int	get_num_ants(void)
{
	int		res;
	char	*line;
	int		comment;

	if ((res = get_next_line_sin(FD, &line)) < 0)
		return (-1);
	while (res != 0)
	{
		if ((comment = is_comment(line)) != 1)
		{
			if (comment < 0)
				return (-1);
			else if (is_numeric(line))
				return (ft_atoi(line));
			else
				break ;
		}
		res = get_next_line_sin(FD, &line);
	}
	return (-1);
}

/*
** Creates linked lists with the strings for the rooms and the edges and
** puts them into the info structure
** Params: Information structure
** returns: 1 if everything was done correctly || 0 if there was an error
*/

static int	get_strings(t_lem *info)
{
	int		res;
	char	*line;

	if (!(info->rooms = new_linked()) || !(info->edges = new_linked()))
		return (0);
	while ((res = get_next_line_sin(FD, &line)) > 0)
	{
		if (!ft_strcmp(line, ""))
			return (1);
		if (!is_comment(line))
		{
			if (is_room(line) || (is_command(line) >= 1))
			{
				if (!add_bnode(info->rooms, new_node(line)))
					return (0);
			}
			else if (is_link(line))
			{
				if (!add_bnode(info->edges, new_node(line)))
					return (0);
			}
			else if (is_command(line) == 0)
				return (0);
		}
	}
	return (1);
}

/*
** Creates the rooms hashtable to make it faster to add the links,
** and adds it to the information structure
** Params: information structure
** Returns: 1 if all went good || 0 if it didn't
*/

static int	create_rooms_ht(t_lem *info)
{
	t_node	*tmp;
	int		flag;
	t_room	*room;

	if (!(info->ht = hash_new_table(info->rooms->len)))
		return (0);
	tmp = info->rooms->head;
	while (tmp)
	{
		if ((flag = is_command(tmp->val)) >= 1)
		{
			if (!(tmp = tmp->next) || !(room = new_room(tmp->val)) ||
				!(hash_insert(info->ht, room->name, room)))
				return (0);
			info->start = (flag == 1 ? room : info->start);
			info->end = (flag == 2 ? room : info->end);
		}
		else
		{
			if (!(room = new_room(tmp->val)) ||
				!(hash_insert(info->ht, room->name, room)))
				return (0);
		}
		tmp = tmp->next;
	}
	return ((info->start && info->end) ? 1 : 0);
}

/*
** Goes through all the posible nodes and connects them as
** specified by the input
** Params: Information structute
** returns: 1 if all worked || 0 if there was an error
*/

int			create_links(t_lem *info)
{
	t_room 		*A;
	t_room 		*B;
	t_node		*input;
	char		**edge_info;
	t_edge		*edge;

	input = info->edges->head;
	while (input)
	{
		if (!(edge_info = ft_strsplit(input->val, '-')))
			return (0);
		if (!(A = hash_search(info->ht, edge_info[0])) ||
				!(B = hash_search(info->ht, edge_info[1])))
			return (0);
		if (!(edge = new_edge(B)))
			return (0);
		if (!A->edges)
			A->edges = edge;
		else
		{
			edge->next = A->edges;
			A->edges = edge;
		}
		free_split(&edge_info);
		input = input->next;
	}
	return (1);
}

/*
** Reads the input from the standard in and parses it to get the
** information required to solve the problem
** Params: None
** returns: Information structure
*/

t_lem		*parse_input(void)
{
	t_lem	*info;

	open("./res/testmap", O_RDWR);
	if (!(info = init_info()) || ((info->n_ants = get_num_ants()) == -1))
		return (NULL);
	if (!get_strings(info) || !(info->edges->head) || !(info->rooms->head))
		return (NULL);
	if (!create_rooms_ht(info))
		return (NULL);
	if (!create_links(info))
		return (NULL);
	hash_display(info->ht);
	return (info);
}
