/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_address.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 13:26:01 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/06 17:34:50 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	apply_width(t_info *info)
{
	int len;

	if (info->width > (len = ft_strlen(info->res)))
	{
		while (info->flags[Fminus] == 1 && len < info->width)
		{
			info->res = ft_straddsuffix(" ", info->res);
			len++;
		}
		if (info->flags[Fzero] == 1 && info->flags[Fminus] != 1)
			len += 2;
		while (info->flags[Fzero] == 1 && len < info->width)
		{
			info->res = ft_straddprefix("0", info->res);
			len++;
		}
		while (len < info->width)
		{
			info->res = ft_straddprefix(" ", info->res);
			len++;
		}
	}
}

static void	apply_precision(t_info *info)
{
	int len;

	if (info->preci > (len = ft_strlen(info->res)))
	{
		while (info->preci > len)
		{
			info->res = ft_straddprefix("0", info->res);
			len++;
		}
	}
}

void		prepare_address(t_info *info)
{
	void	*arg;

	arg = va_arg(info->args[0], void*);
	if (arg == NULL)
	{
		if (!(info->res = ft_strdup("0")))
			print_error();
	}
	else
	{
		if (!(info->res = ft_utoabaselonglong(
						(unsigned long long int)arg, 16)))
			print_error();
	}
	apply_precision(info);
	if (info->flags[Fzero] == 1 && info->flags[Fminus] != 1)
		apply_width(info);
	info->res = ft_straddprefix("0x", info->res);
	apply_width(info);
	if (info->speci == 'P')
		ft_strtoupper(&info->res);
}
