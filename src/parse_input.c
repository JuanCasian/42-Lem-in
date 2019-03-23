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
** Creates linked lists with the strings for the rooms and the edges
** Params: Information structure
** returns: 1 if everything was done correctly || 0 if there was an error
*/

static int	get_strings(t_lem *info)
{
	int		step;
	int		res;
	char	*line;

	if (!(info->rooms = new_linked()) || !(info->edges = new_linked()) ||
		((res = get_next_line_sin(FD, &line)) < 0))
		return (0);
	
	
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

	if (!(info = init_info()) || ((info->n_ants = get_num_ants()) == -1))
		return (NULL);
	if (!get_strings(info))
		return (NULL);
	return (info);
}
