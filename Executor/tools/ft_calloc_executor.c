#include "../../minishell.h"

char    *ft_calloc(int num, int size)
{
    int     i;
    int     n;
    char    *r;

    i = 0;
    n = num * size;
    r = malloc(n);
    if (!r)
        return (NULL);
    while (i < n)
    {
        r[i] = '\0';
        i++;
    }
    return (r);
}

