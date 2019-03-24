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

#include "libft.h"

typedef struct		s_node
{
	char			*val;
	struct s_node	*next;
}					t_node;

typedef struct		s_linked
{
	t_node			*head;
	t_node			*tail;
	int				len;
}					t_linked;

typedef struct		s_edge
{
	struct s_room	*room;
	struct s_edge	*next;
}					t_edge;

typedef struct		s_rooom
{
	char*			name;
	int				x;
	int				y;
	struct t_edge	*edge;
	int				visited;
	int				selected;
	struct s_room	*parent;
}					t_room;

typedef struct		s_hash_item
{
	char				*key;
	void				*val;
	struct s_hash_item	*next;
}					t_hash_item;

typedef struct		s_hash_table
{
	t_hash_item		**items;
	int				size;
}					t_hash_table;



typedef struct		s_lem
{
	int 			n_ants;
	t_linked		*rooms;
	t_linked		*edges;
	t_room			*start;
	t_room			*end;
}					t_lem;



t_lem				*parse_input(void);

/*
** information structure function(s)
*/

t_lem				*init_info(void);

/*
** Input is functions
*/

int					is_comment(char *str);
int					is_numeric(char *str);
int					is_command(char *str);
int					is_room(char *str);
int					is_link(char *str);

/*
** Linked list functions
*/

t_node				*new_node(char *val);
t_linked			*new_linked(void);
int					add_fnode(t_linked *list, t_node *node);
int					add_bnode(t_linked *list, t_node *node);
t_node				*fpop(t_linked *list);

#endif