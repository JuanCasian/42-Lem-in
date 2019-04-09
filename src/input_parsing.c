/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:39:56 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/08 18:39:56 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Gets the number of ants needed for the problem
** Params: None
** Returns: number of ants || -1 in case of error
*/

static int  get_ants(void)
{
    char    *line;
    int     comment;
    int     ant;

    while (get_next_line_sin(FD, &line) > 0)
    {
        if ((comment = is_comment(line)) != 1)
        {
            if (comment < 0)
                return (-1);
            else if (is_numeric(line))
            {
                ant = ft_atoi(line);
                free(line);
                return (ant);
            }
            else
            {
                free(line);
                break ;
            }
        }
        free(line);
    }
    return (-1);
}

/*
** Creates dynamics arrays with the strings for the rooms and the edges
** Params: rooms dyn arr, edges dyn arr
** returns: 1 if everything was done correctly || 0 if there was an error
*/

static int  get_strings(t_arr *rooms, t_arr *edges)
{
    char    *line;

    while (get_next_line_sin(FD, &line) > 0 && ft_strcmp(line, ""))
    {
        if (!is_comment(line))
		{
			if (is_room(line) || (is_command(line) >= 1))
			{
				if (!(arr_append(rooms, line)))
					return (0);
			}
			else if (is_link(line))
			{
				if (!(arr_append(edges, line)))
					return (0);
			}
			else if (is_command(line) == 0)
				return (0);
		}
        free(line);
    }
    return (1);
}

/*
** Reads the input from the STD_IN and returns and object with all
** the neded information;
** Return: <t_lem *> information structure
*/

t_lem   *parse_input(void)
{
    t_lem   *info;
    t_arr   *rooms;
    t_arr   *edges;

    open("./res/testmap", O_RDWR);
    if (!(info = init_lemstruct()))
        return (NULL);
    if ((info->n_ants = get_ants()) == -1)
        return (NULL);
    if (!(rooms = arr_init()) || !(edges = arr_init()))
        return (NULL);
    if (!(get_strings(rooms, edges)) || rooms->len == 0 || edges->len == 0)
        return (NULL);
    ft_printf("Ant num: %i\nRooms:\n", info->n_ants);
    for (int i = 0; i < rooms->len; i++)
        ft_printf("%s\n", rooms->strs[i]);
    for (int i = 0; i < edges->len; i++)
        ft_printf("%s\n", edges->strs[i]);
    while (1);
    return (info);
}
