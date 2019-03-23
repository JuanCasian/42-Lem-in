/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:05:37 by jcasian           #+#    #+#             */
/*   Updated: 2019/03/23 13:05:37 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_lem	*info;

	if (!(info = parse_input()))
		print_error();
	ft_printf("number of ants: %i\n", info->n_ants);
	return (0);
}
