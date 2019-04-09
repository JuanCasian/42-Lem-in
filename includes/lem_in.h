/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:31:00 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/14 16:31:00 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H
# define FD 3
# define ARR_CAP 16

# include "libft.h"

typedef struct	s_lem
{
	int		n_ants;
}				t_lem;

typedef struct	s_arr
{
	char	**strs;
	int		len;
	int		capacity;
}				t_arr;

/*
** Input parsing functions
*/

t_lem				*parse_input(void);
t_lem				*init_lemstruct(void);
int					is_comment(char *str);
int					is_numeric(char *str);
int					is_command(char *str);
int					is_room(char *str);
int					is_link(char *str);

/*
**	Dynamic array functions
*/

t_arr				*arr_init(void);
int					arr_append(t_arr *arr, char *str);

#endif