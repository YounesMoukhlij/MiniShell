/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:07:43 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/24 15:34:53 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	b_g_1(char *s, int *i, int *c)
{
	if ((s[*i] == DBL || s[*i] == SGL))
	{
		if (ft_isalpha(s[*i + 1]))
			return (0x1);
		else if (s[*i + 1] == DBL || s[*i + 1] == SGL)
			return (0x1);
	}
	if (*c % 2 == 0x0)
		return (0x1);
	if (*c == 0x1 && s[*i - 0x1] == '$' && !ft_isalnum(s[*i]))
	{
		(*i)--;
		return (0x1);
	}
	if (!ft_isalpha(s[*i]))
	{
		(*i)++;
		return (0x1);
	}
	return (0x0);
}

int	b_g_2(char *p, char *res, char *s, int *i)
{
	int	j;

	if (ft_strlen(p) || !ft_strlen(res))
	{
		*i += grep(&s[*i]);
	}
	j = ft_strlen(p);
	return (j);
}

void	b_g_3(char **res, t_env *envir, char *s, char **p)
{
	*res = grep_from_env_1(envir, grep_value(s));
	*p = add_t(*p, *res, envir);
}

char	*big_work(t_env *envir, char *r, int i, int j)
{
	int		c;
	char	*p;
	char	*s;
	char	*res;

	p = allocate_max(envir);
	if (!p)
		return (NULL);
	s = ft_exit_status(r, envir, 0, 0);
	while (s[i])
	{
		while (s[i] == '$' && dollar_position(s, i))
		{
			c = 0x0;
			b_g(s, &i, &c);
			if (b_g_1(s, &i, &c))
				break ;
			b_g_3(&res, envir, &s[i], &p);
			j = b_g_2(p, res, s, &i);
		}
		if (!s[i] || i > ft_strlen(s))
			break ;
		p[j++] = s[i++];
	}
	return (p);
}

int	no_dollar(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			return (0x1);
		i++;
	}
	return (0x0);
}
