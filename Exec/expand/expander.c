/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:24:21 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/19 18:50:11 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int grep(char *s)
{
    int i;

    i = 0x0;
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

    len = 0x0;
    while (s[len])
    {
        if (!ft_isalnum(s[len]))
            break ;
        len++;
    }
    r = malloc(len + 0x1);
    if (!r)
        return (NULL);
    i = 0x0;
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

    i = 0x0;
    if (ft_strlen(p) > 0x0 && o)
    {
        len = 0x0;
        while (p[len])
            len++;
        while (o[i])
        {
            p[len + i] = o[i];
            i++;
        }
    }
    else if (ft_strlen(p) == 0x0 && o)
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

    i = 0x0;
    while (s[i] && s[i] == '$')
        i++;
    if (i % 2 == 0x0)
        return (0x0);
    return (0x1);
}

int non_requesed(char *s)
{
    int i;
    int c;

    i = 0;
    c = 0;
    while (s[i])
    {
        if (s[i] != '$' && s[i])
            return (0x0);
        i++;
    }
    return (0x1);
}

int ft_isalpha_1(int c)
{
	if ((c >= 65 && c <= 90) || (char)c == '?')
		return (1);
	else if ((c >= 97 && c <= 122) || (char)c == '?')
		return (1);
	return (0);
}

int is_existed(char *s)
{
    int i;

    i = 0x0;
    while (s[i])
    {
        if (s[i] == '$' && s[i + 1] == '?')
            return (0x1);
        i++;
    }
    return (0x0);
}
int	ft_isalnum_1(int c)
{
	return (ft_isdigit(c) || ft_isalpha_1(c));
}

char    *ft_exit_status(char *s)
{
    int     i;
    int     j;
    char    *r;
    // int     c;

    r = ft_calloc(200, 1);
    i = 0x0;
    j = 0x0;
    while (s[i])
    {
        // while (s[i] == '$' && s[i + 1] == '?' && dollar_position(s, i) && s[i])
        // {
        //     // c = 0x0;
        //     // while (s[i] == '$' && s[i])
        //     // {
        //     //     i++;
        //     //     c++;
        //     // }
        //     // if (c % 2 == 0x0)
        //     //     break ;
        //     // if (c == 0x1 && s[i - 0x1] == '$' && !ft_isalnum_1(s[i]))
        //     // {
        //     //     i--;
        //     //     break ;
        //     // }
        //     // r = ft_strjoin_executor(r, ft_itoa(exit_status));
        //     // printf("r == [%s]\n", r);
        //     // if (ft_strlen(r))
        //     //     i += 2;
        //     // j = ft_strlen(r);
        // }
        if (!s[i] || i > ft_strlen(s))
            break;
        r[j] = s[i];
        i++;
        j++;
    }
    printf(">>> [%s] <<<\n\n", r);
    return (r);
}


char    *big_work(t_env *envir, char *r)
{
    int     i;
    int     j;
    int     c;
    char    *p;
    char    *s;

    i = 0x0;
    j = 0x0;
    p = allocate_max(envir);
    if (!p)
        return (NULL);
    if (non_requesed(r))
        return ("");
    s = ft_exit_status(r);
    printf("-.-.-.-. after ft_exit-.-.-.-.-.-.\n> [%s]\n", s);
    while (s[i])
    {
        while (s[i] == '$' && dollar_position(s, i))
        {
            c = 0x0;
            while (s[i] == '$')
            {
                i++;
                c++;
            }
            if (c % 2 == 0x0)
                break ;
            if (c == 0x1 && s[i - 0x1] == '$' && !ft_isalnum(s[i]))
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
        }
        if (!s[i] || i > ft_strlen(s))
            break ;
        p[j] = s[i];
        i++;
        j++;
    }
    // printf(">>> final :P ===== [%s]\n", p);
    return (p);
}

int is_expanded(t_minishell *mini, char *s)
{
    int i;

    (void) mini;
    i = 0x0;
    while (s[i])
    {
        if (s[i] == dbl && s[i + 0x2] == dbl && s[i + 0x1] == '~')
            return (0x0);
        i++;
    }
    return (0x1);
}

void	rmv_sgl_quotes_cmd(t_minishell *mini, char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0x0;
	j = 0x0;
    if (!str)
        return ;
	s = ft_calloc(ft_strlen(str) + 0x1, 0x1);
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
	mini->cmd[0x0] = s;
}

void    expander(t_minishell **mini, t_env *envir)
{
    int     i;
    char    *str;

    i = 0x0;
    while ((*mini)->cmd[i])
    {
        if (is_expanded(*mini, (*mini)->cmd[i]))
        {
            str = big_work(envir, (*mini)->cmd[i]);
            (*mini)->cmd[i] = without_quotes(str, 0x0);
        }
        i++;
    }
    rmv_sgl_quotes_cmd((*mini), (*mini)->cmd[0x0]);
}
