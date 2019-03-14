/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 21:27:29 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/06 14:35:20 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*wstr;
	size_t	i;

	i = 0;
	wstr = (wchar_t*)malloc(sizeof(wchar_t) * size + 1);
	if (!wstr)
		return (NULL);
	while (i <= size)
	{
		wstr[i] = 0;
		i++;
	}
	return (wstr);
}
