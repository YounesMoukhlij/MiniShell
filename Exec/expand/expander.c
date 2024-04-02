#include "../../minishell.h"

int grep(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (!ft_isalnum(s[i]))
            break ;
        i++;
    }
    return (i);
}

char    *grep_value(char *s)
{
    int     len;
    int     i;
    char    *r;

    len = 0;
    while (s[len])
    {
        if (!ft_isalnum(s[len]))
            break ;
        len++;
    }
    r = malloc(len + 1);
    if (!r)
        return (NULL);
    i = 0;
    while (i < len)
    {
        r[i] = s[i];
        i++;
    }
    r[len] = '\0';
    return (r);
}

char    *add_t(char *p, char *o)
{
    int i;
    int len;

    i = 0;
    if (ft_strlen(p) > 0 && o)
    {
        len = 0;
        while (p[len])
            len++;
        while (o[i])
        {
            p[len + i] = o[i];
            i++;
        }
    }
    else if (ft_strlen(p) == 0 && o)
    {
        while (o[i])
        {
            p[i] = o[i];
            i++;
        }
    }
    return (p);
}

int even_odd(char *s)
{
    int i;

    i = 0;
    while (s[i] && s[i] == '$')
        i++;
    if (i % 2 == 0)
        return (0);
    return (1);
}

char    *big_work(t_env *envir, char *s)
{
    int     i;
    int     j;
    int     c;
    char    *p;

    i = 0;
    j = 0;
    p = allocate_max(envir);
    if (!p)
        return (NULL);
    while (s[i])
    {
        while (s[i] == '$' && dollar_position(s, i))
        {
            c = 0;
            while (s[i] == '$')
            {
                i++;
                c++;
            }
            if (c % 2 == 0)
                break ;
            if (c == 1 && s[i - 1] == '$' && !ft_isalnum(s[i]))
            {
                i--;
                break ;
            }
            if (!ft_isalpha(s[i]))
            {
                i++;
                break ;
            }
            p = add_t(p, grep_from_env(envir, grep_value(&s[i])));
            if (ft_strlen(p) || !grep_from_env(envir, grep_value(&s[i])))
                i += grep(&s[i]);
            j = ft_strlen(p);
            if (!s[i])
                break ;
        }
        p[j] = s[i];
        i++;
        j++;
    }
    return (p);
}

int is_expanded(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == dbl && s[i + 2] == dbl && s[i + 1] == '~')
            return (0);
        i++;
    }
    return (1);
}

void	rmv_sgl_quotes_cmd(t_minishell *mini, char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = ft_calloc(ft_strlen(str) + 1, 1);
	if (!s)
		return ;
	while (str[i])
	{
		if (str[i] == sgl)
			i++;
		s[j] = str[i];
		j++;
		i++;
	}
	mini->cmd[0] = s;
}

void    expander(t_minishell **mini, t_env *envir)
{
    // char *str;
    int     i;
    // int     flag;

    (void) envir;
    i = 0;
    // flag = 0;
    if (!((*mini)->cmd))
    {
        puts("asdasd\n");
        return ;
    }
    while ((*mini)->cmd[i])
    {
        printf("%s\n", (*mini)->cmd[i]);
    //     if (is_expanded((*mini)->cmd[i]))
    //     {
    //         str = big_work(envir, (*mini)->cmd[i]);
    //         (*mini)->cmd[i] = without_quotes(str, flag);
    //     }
        // i++;
    }
    // rmv_sgl_quotes_cmd((*mini), (*mini)->cmd[0]);
}
