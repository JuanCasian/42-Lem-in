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

typedef struct		s_hash_item
{
	char			*key;
	void			*val;
}					t_hash_item;

typedef struct		s_hash_table
{
	t_hash_item		**items;
	int				size;
}					t_hash_table;

/*
** hash_table functions
*/

t_hash_table	*hash_new_table(int size);
t_hash_item		*hash_new_item();
int				hash_insert();
int				hash_delete();
void			hash_display();

/*
** Linked list functions
*/

t_node			*new_node(void *val);
t_linked		*new_linked(void);
int				add_fnode(t_linked *list, t_node *node);
int				add_bnode(t_linked *list, t_node *node);
t_node			*fpop(t_linked *list);


void			input(void);

#endif