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

	if (!(info->rooms = new_linked()) || !(info->edges = new_linked()) ||
		((res = get_next_line_sin(FD, &line)) < 0))
		return (0);
	while (res != 0)
	{
		if (!is_comment(line))
		{
			if (is_room(line) || (is_command(line) == 1))
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
			res = get_next_line_sin(FD, &line);
		}
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
	t_node	*tmp;

	if (!(info = init_info()) || ((info->n_ants = get_num_ants()) == -1))
		return (NULL);
	if (!get_strings(info))
		return (NULL);
	tmp = info->rooms->head;
	ft_printf("Rooms:\n");
	while (tmp)
	{
		ft_printf("%s\n", tmp->val);
		tmp = tmp->next;
	}
	ft_printf("Edges:\n");
	tmp = info->edges->head;
	while (tmp)
	{
		ft_printf("%s\n", tmp->val);
		tmp = tmp->next;
	}
	return (info);
}
