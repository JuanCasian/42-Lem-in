/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_is_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:26:54 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/23 13:26:54 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* 
** Checks if the string is filled only by whitespaces and numbers
** params: string to check
** returns: 1 if the whole string is only of spaces and digits || 0 if not
*/


int	is_numeric(char *str)
{
	int	flag;
	int i;

	flag = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]))
			flag = 1;
		else if (!ft_isdigit(str[i]) && !ft_is_space(str[i]))
			return (0);
	}
	if (flag)
		return (1);
	return (0);
}

/*
** Checks if the string is a comment, a comment is a line starting with only one #
** Params: string to check
** returns: -1 if str is empty || 1 if string is comment || 0 if not
*/

int	is_comment(char *str)
{
	int len;

	if ((len = ft_strlen(str)) == 0)
		return (-1);
	if (len == 1 && str[0] == '#')
		return (1);
	if (str[0] == '#' && str[1] != '#')
		return (1);
	return (0);
}
