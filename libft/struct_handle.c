/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 19:02:41 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/04 19:56:48 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	reinit_lengths(t_info *info)
{
	int	i;

	i = -1;
	while (++i < NLENS)
		info->lens[i] = -1;
}

void	initialize_struct(t_info *info, char **str, va_list *args)
{
	int	i;

	i = -1;
	while (++i < NFLAGS)
		info->flags[i] = -1;
	i = -1;
	while (++i < NLENS)
		info->lens[i] = -1;
	info->args = args;
	info->str = str;
	info->count = 0;
	info->width = -1;
	info->preci = -1;
	info->speci = '\0';
	info->res = NULL;
	info->wres = NULL;
}

void	reinit_structure(t_info *info)
{
	int	i;

	i = -1;
	while (++i < NFLAGS)
		info->flags[i] = -1;
	i = -1;
	while (++i < NLENS)
		info->lens[i] = -1;
	info->width = -1;
	info->preci = -1;
	info->speci = '\0';
	if (info->res)
	{
		free(info->res);
		info->res = NULL;
	}
	if (info->wres)
	{
		free(info->wres);
		info->wres = NULL;
	}
}
