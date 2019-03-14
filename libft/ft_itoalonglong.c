/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoalonglong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 16:37:20 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/06 17:17:54 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check_specialcases(long long n)
{
	char *res;

	if (n == -9223372036854775807)
	{
		if (!(res = ft_strdup("-9223372036854775807")))
			print_error();
		return (res);
	}
	else if (n == 0)
	{
		if (!(res = ft_strdup("0")))
			print_error();
		return (res);
	}
	return (NULL);
}

static int	num_digits(long long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoalonglong(long long n)
{
	char	*res;
	int		i;

	if ((res = check_specialcases(n)))
		return (res);
	i = num_digits(n);
	if (n < 0)
		i++;
	if (!(res = ft_strnew(i)))
		print_error();
	if (n < 0)
	{
		res[0] = '-';
		n = n * (-1);
	}
	i--;
	while (n != 0)
	{
		res[i] = (char)(n % 10) + '0';
		i--;
		n /= 10;
	}
	return (res);
}
