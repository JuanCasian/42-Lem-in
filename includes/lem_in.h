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

typedef struct		s_room
{
	char*			name;
	int				x;
	int				y;
	struct s_edge	*edges;
	int				visited;
	int				selected;
	struct s_room	*parent;
	int				ant;
}					t_room;

typedef struct		s_hash_item
{
	char				*key;
	t_room				*room;
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
	t_hash_table	*ht;
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

/*
** hash_table functions
*/

t_hash_table	*hash_new_table(int size);
t_hash_item		*hash_new_item(char *key, t_room *room);
int				hash_insert(t_hash_table *table, char *key, t_room *room);
void			hash_display(t_hash_table *table);
t_room			*hash_search(t_hash_table *table, char *key);
unsigned int	hash_function(char *key, int size);

/*
** Room functions
*/

t_room			*new_room(char *str);

/*
** Edge functions
*/

t_edge			*new_edge(t_room *end);

/*
** Freeing memory functions
*/

void			free_split(char ***obj);

#endif