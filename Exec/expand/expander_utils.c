/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:20:40 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/08 23:21:40 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int case_1(char *s, int pos)
{
    int i;

    i = 0x0;
    while (s[i])
    {
        if (s[i] == dbl)
        {
            i++;
            while (s[i] != dbl && s[i])
            {
                if (i == pos)
                    return (0x1);
                i++;
            }
        }
        i++;
    }
    return (0x0);
}

int case_2(char *s, int pos)
{
    int i;

    i = 0x0;
    while (s[i])
    {
        if (s[i] == sgl)
        {
            i++;
            while (s[i] != sgl && s[i])
            {
                if (i == pos)
                    return (0x0);
                i++;
            }
        }
        i++;
    }
    return (1);
}

int dollar_position(char *s, int pos)
{
    if (case_1(s, pos))
        return (0x1);
    if (case_2(s, pos))
        return (0x1);
    return (0x0);
}

char    *without_quotes(char *s, int flag)
{
    int     i;
    int     j;
    char    *res;

    i = 0x0;
    j = 0x0;
    res = calloc(strlen(s) + 1, 1);
    if (!res)
        return (NULL);
    while (s[i])
    {
        if (s[i] == dbl && s[i] && flag == 0x0)
        {
            flag = 1;
            i++;
        }
        if (s[i] == dbl && flag == 1)
        {
            i++;
            flag = 0x0;
        }
        while (s[i] == sgl && flag == 0x0)
          i++;
        if (!s[i])
            break ;
        if (s[i] != dbl)
        {
            res[j] = s[i];
        i++;
        j++;
        }
    }
    return (res);
}

