/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 21:18:03 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/22 21:18:03 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem	*init_info(void)
{
	t_lem	*info;

	if (!(info = (t_lem*)malloc(sizeof(t_lem))))
		return (NULL);
	info->n_ants = -1;
	info->table = NULL;
	info->input = NULL;
	info->rooms = NULL;
	info->con = NULL;
	return (info);
}
