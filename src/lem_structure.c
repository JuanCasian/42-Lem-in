/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_structure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:43:18 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/08 18:43:18 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem   *init_lemstruct(void)
{
    t_lem   *info;

    if (!(info = (t_lem*)malloc(sizeof(t_lem))))
        return (NULL);
    info->n_ants = -1;
    return (info);
}
