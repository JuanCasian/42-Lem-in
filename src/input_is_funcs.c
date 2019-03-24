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

/*
** Checks if the string is a known command, commands appear with double ##
** Params: String to check
** Returns: 1 if the command is start || -1 if it is a unkown command
** 				|| 0 if it is not a command || 2 if the command is end
*/

int	is_command(char *str)
{
	int	len;

	if ((len = ft_strlen(str)) < 2)
		return (0);
	if (!ft_strcmp(str, "##start"))
		return (1);
	if (!ft_strcmp(str, "##end"))
		return (2);
	if (str[0] == '#' && str[1] == '#')
		return (-1);
	return (0);
}

/*
** Check if the string is a room
** Params: string to check
** Returns: 1 if it is a room || 0 if is not
*/

int is_room(char *str)
{
	int spaces;
	int numbers;

	spaces = 0;
	numbers = 0;
	while (*str && !ft_is_space(*str))
		str++;
	while (*str && ft_is_space(*str))
	{
		spaces += 1;
		str++;
	}
	if (*str && ft_isdigit(*str))
		numbers += 1;
	while(*str && ft_isdigit(*str))
		str++;
	while (*str && ft_is_space(*str))
	{
		spaces += 1;
		str++;
	}
	if (*str && ft_isdigit(*str))
		numbers += 1;
	while (*str && ft_isdigit(*str))
		str++;
	if (!(*str) && numbers == 2 && spaces == 2)
		return (1);
	return (0);
}

/*
** Checks if the string is a valid link between 2 nodes
** Params: string to check
** Returns: 1 if is valid || 0 if it is not
*/

int	is_link(char *str)
{
	int bars;
	int i;

	bars = 0;
	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	while (str[i] && str[i] == '-')
	{
		i++;
		bars += 1;
	}
	while (str[i] && str[i] != '-')
		i++;
	if (!str[i] && bars == 1)
		return (1);
	return (0);
}
