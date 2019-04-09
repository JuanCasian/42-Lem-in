/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:00:42 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/08 19:00:42 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_arr       *arr_init(void)
{
    t_arr   *arr;
    int     i;
    
    if (!(arr = (t_arr*)malloc(sizeof(t_arr))))
        return (NULL);
    if (!(arr->strs = (char**)malloc(sizeof(char*) * ARR_CAP)))
    {
        free(arr);
        return (NULL);
    }
    i = -1;
    while (++i < ARR_CAP)
        arr->strs[i] = NULL;
    arr->len = 0;
    arr->capacity = ARR_CAP;
    return (arr);
}

int     arr_append(t_arr *arr, char *str)
{
    char    **tmp;
    int     i;

    if (arr->len + 1 >= arr->capacity)
    {
        tmp = arr->strs;
        arr->capacity *= 2;
        if (!(arr->strs = (char**)malloc(sizeof(char*) * arr->capacity)))
            return (0);
        i = -1;

        while (++i < arr->len)
            arr->strs[i] = tmp[i];
        while (i < arr->capacity)
        {
            arr->strs[i] = NULL;
            i++;
        }
    }
    if (!(arr->strs[arr->len] = ft_strdup(str)))
        return (0);
    arr->len += 1;
    return (1);
}
