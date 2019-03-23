/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:41:31 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/14 16:41:31 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_linked	*read_input(void)
{
	t_linked	*list;
	int			res;
	char		*line;
	int fd;

	if (!(list = new_linked()))
		return (NULL);
	fd = open("./res/testmap", O_RDWR);
	if ((res = get_next_line_sin(fd, &line)) < 0)
		return (NULL);
	while (res != 0)
	{
		if (!add_bnode(list, new_node((void*)line)))
			return (NULL);
		res = get_next_line_sin(fd, &line);
	}
	return (list);
}

t_lem		*input(void)
{
	t_lem	*info;
	t_node 	*tmp;
	if (!(info = init_info()) || !(info->input = read_input()) ||
		!(info->table = hash_new_table(info->input->len)))
		print_error();
	
	return(info);
}
