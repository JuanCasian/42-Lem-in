/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:37:56 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/08 18:37:56 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**  This program finds and optimized way to send ants from one node
**  in a graph to the other
*/

int     main(void)
{
    t_lem   *info;
    
    if (!(info = parse_input()))
        print_error();
    return (0);
}
