#include "../../minishell.h"

int case_1(char *s, int pos)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == dbl)
        {
            i++;
            while (s[i] != dbl && s[i])
            {
                if (i == pos)
                    return (1);
                i++;
            }
        }
        i++;
    }
    return (0);
}

int case_2(char *s, int pos)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == sgl)
        {
            i++;
            while (s[i] != sgl && s[i])
            {
                if (i == pos)
                    return (0);
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
        return (1);
    if (case_2(s, pos))
        return (1);
    return (0);
}

char    *without_quotes(char *s, int flag)
{
    int     i;
    int     j;
    char    *res;

    i = 0;
    j = 0;
    res = calloc(strlen(s) + 1, 1);
    if (!res)
        return (NULL);
    while (s[i])
    {
        if (s[i] == dbl && s[i] && flag == 0)
        {
            flag = 1;
            i++;
        }
        if (s[i] == dbl && flag == 1)
        {
            i++;
            flag = 0;
        }
        while (s[i] == sgl && flag == 0)
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

