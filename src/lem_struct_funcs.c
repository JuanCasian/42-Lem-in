/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_struct_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:10:29 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/23 13:10:29 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Initialize the information structure
** Params: None
** Returns: t_lem object initialized
*/

t_lem	*init_info(void)
{
	t_lem	*info;

	if (!(info = (t_lem*)malloc(sizeof(t_lem))))
		return (NULL);
	info->n_ants = -1;
	info->rooms = NULL;
	info->edges = NULL;
	info->start = NULL;
	info->end = NULL;
	info->ht = NULL;
	return (info);
}
