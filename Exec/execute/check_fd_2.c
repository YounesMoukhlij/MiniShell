/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:08:07 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/20 13:53:22 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	*init_func(t_env *env, char **p, char **s, char *r)
{
	*p = allocate_max_1(env);
	if (!(*p))
		return (NULL);
	*s = herdoc_helper(r, env, 0x0, 0x0);
	if (!(*s))
		return (NULL);
	return ("");
}

void	func_1(char **r, char **p, char *s, t_env *env)
{
	*r = grep_from_env_1(env, grep_value(s));
	*p = add_t(*p, *r, env);
}

int	func_2(int c, char *s, int *i)
{
	if (c == 0x1 && s[*i - 0x1] == '$' && !ft_isalnum(s[*i]))
	{
		(*i)--;
		return (0x1);
	}
	return (0x0);
}

int	func_3(char *s, int *i)
{
	if (!ft_isalpha(s[*i]))
	{
		(*i)++;
		return (0x1);
	}
	return (0x0);
}

char	*expand_heredoc(t_env *envir, char *r, int i, int j)
{
	t_expand	tmp;

	if (!init_func(envir, &tmp.p, &tmp.s, r))
		return (0x0);
	while (tmp.s[i])
	{
		while (tmp.s[i] == '$')
		{
			tmp.c = 0x0;
			while (tmp.s[i] == '$')
				(1) && (i++, tmp.c++);
			if (tmp.c % 2 == 0x0)
				break ;
			if (func_2(tmp.c, tmp.s, &i))
				break ;
			if (func_3(tmp.s, &i))
				break ;
			func_1(&tmp.res, &tmp.p, &tmp.s[i], envir);
			j = func(tmp.p, tmp.res, &i, tmp.s);
		}
		if (!tmp.s[i] || i > ft_strlen(tmp.s))
			break ;
		tmp.p[j++] = tmp.s[i++];
	}
	return (tmp.p);
}
