/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:42:47 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/20 17:43:09 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	uef_1(char *s, int *i)
{
	if (!ft_isalnum(s[*i]))
	{
		(*i)--;
		return (0x1);
	}
	return (0x0);
}

int	uef_2(char *s, int *i)
{
	if (!ft_isalpha(s[*i]))
	{
		(*i)++;
		return (0x1);
	}
	return (0x0);
}

int	uef_3(char *p, char *res, int *i, char *s)
{
	int	j;

	j = 0x0;
	if (ft_strlen(p) || !strcmp_f(res, "", 0x0, 0x0))
		*i += grep(&s[*i]);
	j = ft_strlen(p);
	return (j);
}

char	*u_e_f(t_env *envir, char *s, int i, int j)
{
	char	*p;
	char	*res;

	p = ft_calloc(100, 0x1);
	if (!p)
		return (0x0);
	while (s[i])
	{
		while (s[i] == '$')
		{
			while (s[i] == '$')
				i++;
			if (uef_1(s, &i))
				break ;
			if (uef_2(s, &i))
				break ;
			res = grep_from_env(envir, grep_value(&s[i]));
			p = add_t(p, res, envir);
			j = uef_3(p, res, &i, s);
		}
		if (!s[i] || i > ft_strlen(s))
			break ;
		p[j++] = s[i++];
	}
	return (p);
}
