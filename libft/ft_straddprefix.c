/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddprefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 21:19:33 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/06 14:31:40 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddprefix(char *prefix, char *str)
{
	int		i;
	int		j;
	char	*res;

	j = -1;
	i = ft_strlen(prefix) + ft_strlen(str);
	if (!(res = ft_strnew(i)))
		print_error();
	while (prefix[++j])
		res[j] = prefix[j];
	i = 0;
	while (str[i])
	{
		res[j] = str[i];
		i++;
		j++;
	}
	free(str);
	return (res);
}
