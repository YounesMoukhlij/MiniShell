/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getstr_fpromt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:23:08 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/20 18:23:13 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int cas_1 (char *str,char *ns, int *j ,int *i)
{
   int op;

   op = 0;
   while (str[*i] && op == 0)
    {
                    ns[(*j)++] = str[(*i)++];
                    if (str[*i] == '\"')
                        op =1;
        }
   return (op);
}

static int cas_2 (char *str,char *ns, int *j ,int *i)
{
   int op;

   op = 0;
   while (str[*i] && op == 0)
    {
                    ns[(*j)++] = str[(*i)++];
                    if (str[*i] == '\'')
                        op = 1;
    }
   return (op);
}
char *getstr_fpromt (char *str)
{
   int i;
   int j;
   int op;

   i = 0;
   j = 0;
 char *ns = ft_calloc(ft_strlen(str) * 10, 1);
 while (i < ft_strlen(str))
   {
        if (str[i] == '\"' )
      {
              op = cas_1(str, ns, &j, &i);
              ns[j++] = str[i++];
              if (op == 1 )
            {
                if (str[i] != '\"' && str[i] != '\'')
                        ns[j++] = ' ';
                op = 0;
            }
        }
        else if (str[i] == '\'')
        {
            op = cas_2(str, ns, &j, &i);
            ns[j++] = str[i++];
            if (op == 1)
            {
                if (str[i] != '\"' && str[i] != '\'')
                        ns[j++] = ' ';
                op = 0;
            }
        }
        else
            ns[j++] = str[i++];
    }
    return (ns);
}