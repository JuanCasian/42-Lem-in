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

	if (!(list = new_linked()))
		return (NULL);
	if ((res = get_next_line_sin(STDIN_FILENO, &line)) < 0)
		return (NULL);
	while (res != 0)
	{
		if (!add_bnode(list, new_node((void*)line)))
			return (NULL);
		res = get_next_line_sin(STDIN_FILENO, &line);
	}
	return (list);
}

void		input(void)
{
	t_linked	*input;
	t_node		*tmp;

	if (!(input = read_input()))
		print_error();
	while ((tmp = fpop(input)))
		ft_printf("%s\n", tmp->val);
}
