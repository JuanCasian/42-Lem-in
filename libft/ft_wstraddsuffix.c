/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstraddsuffix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 21:28:31 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/06 14:32:46 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstraddsuffix(wchar_t *suffix, wchar_t *str)
{
	int		i;
	int		j;
	wchar_t	*res;

	j = 0;
	i = 0;
	while (suffix[i])
		i++;
	while (str[j++])
		i++;
	if (!(res = ft_wstrnew(i)))
		print_error();
	j = -1;
	while (str[++j])
		res[j] = str[j];
	i = 0;
	while (suffix[i])
	{
		res[j++] = suffix[i];
		i++;
	}
	free(str);
	return (res);
}
