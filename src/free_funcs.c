/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:40:07 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/06 14:40:07 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* 
** Frees up the multiple string array
** Params: Address of the array of strings
*/

void		free_split(char ***obj)
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
