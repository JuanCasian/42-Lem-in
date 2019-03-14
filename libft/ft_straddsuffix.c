/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddsuffix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 21:22:52 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/06 14:30:46 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddsuffix(char *suffix, char *str)
{
	char	*res;
	int		i;
	int		j;

	i = ft_strlen(suffix) + ft_strlen(str);
	if (!(res = ft_strnew(i)))
		print_error();
	j = -1;
	i = 0;
	while (str[++j])
		res[j] = str[j];
	while (suffix[i])
	{
		res[j] = suffix[i];
		i++;
	}
	free(str);
	return (res);
}
