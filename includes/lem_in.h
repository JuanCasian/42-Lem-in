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

#include "libft.h"

typedef struct 		s_node
{
	void			*val;
	struct s_node 	*next;
}					t_node;

typedef struct		s_linked
{
	t_node			*head;
	t_node			*tail;
	int 			len;
}					t_linked;

t_node		*new_node(void *val);
t_linked	*new_linked(void);
int			add_fnode(t_linked *list, t_node *node);
int			add_bnode(t_linked *list, t_node *node);
t_node		*fpop(t_linked *list);
void		input(void);

#endif