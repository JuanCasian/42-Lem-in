/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 20:33:45 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/04 21:56:05 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_wchars(wchar_t *wstr)
{
	int i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}

wchar_t		*ft_wstrdup(wchar_t *wstr)
{
	wchar_t	*res;
	int		i;

	i = 0;
	if (!(res = (wchar_t*)malloc(sizeof(wchar_t) * num_wchars(wstr) + 1)))
		return (NULL);
	while (wstr[i])
	{
		res[i] = wstr[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
