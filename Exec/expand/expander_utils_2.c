/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:07:43 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/05 18:10:11 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_existed(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (s[i] == '$' && s[i + 1] == '?')
			return (0x1);
		i++;
	}
	return (0x0);
}

char	*ft_exit_status(char *s, t_env *envir)
{
	int		i;
	int		j;
	char	*r;
	int		c;

	r = ft_calloc(200, 1);
	i = 0x0;
	j = 0x0;
	while (s[i])
	{
		while (s[i] == '$' && dollar_position(s, i) && s[i])
		{
			c = 0x0;
			while (s[i] == '$' && s[i])
			{
				i++;
				c++;
			}
			if (c % 2 == 0x0)
				break ;
			if (s[i] == '?')
			{
				r = add_t(r, ft_itoa(ex_st_f(0x0, 0x0)), envir);
				if (ft_strlen(r))
					i += 1;
				j = ft_strlen(r);
			}
			else
			{
				i--;
				break ;
			}
		}
		if (!s[i] || i > ft_strlen(s))
			break ;
		r[j] = s[i];
		i++;
		j++;
	}
	return (r);
}

int	extra_check(char *s)
{
	if (s[0] == '$' &&
		(s[1] == DBL ||
			s[1] == SGL))
		return (0x1);
	return (0x0);
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
	s = ft_exit_status(r, envir);
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
			res = grep_from_env(envir, grep_value(&s[i]));
			p = add_t(p, res, envir);
			if (ft_strlen(p) || !ft_strlen(res))
				i += grep(&s[i]);
			j = ft_strlen(p);
		}
		if (!s[i] || i > ft_strlen(s))
			break ;
		p[j] = s[i];
		i++;
		j++;
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
