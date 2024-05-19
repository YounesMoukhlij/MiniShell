/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:08:07 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/19 17:06:04 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*expand_heredoc(t_env *envir, char *r, int i, int j)
{
	int		c;
	char	*p;
	char	*s;
	char	*res;

	p = allocate_max_1(envir);
	if (!p)
		return (NULL);
	s = herdoc_helper(r, envir, 0x0, 0x0);
	if (!s)
		return (NULL);
	while (s[i])
	{
		while (s[i] == '$')
		{
			c = 0x0;
			while (s[i] == '$')
				(1) && (i++, c++);
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
			res = grep_from_env_1(envir,  grep_value(&s[i]));
			p = add_t(p, res, envir);
			if (!p)
				return (0x0);
			if (ft_strlen(p) || !ft_strlen(res))
				i += grep(&s[i]);
			j = ft_strlen(p);
		}
		if (!s[i] || i > ft_strlen(s))
			break ;
		p[j++] = s[i++];
	}
	return (p);
}

