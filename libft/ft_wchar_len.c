/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 20:50:01 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/06 14:30:05 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wchar_len(wchar_t wc)
{
	int	len;

	len = 0;
	if (wc <= 0xFF)
		return (1);
	else if (wc < 0x0800)
		return (2);
	else if (wc < 0x010000)
		return (3);
	else if (wc < 0x110000)
		return (4);
	return (len);
}
