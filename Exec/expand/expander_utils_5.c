/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:27:31 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/30 17:32:12 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_rmv_sgl(char *s, int i, int j, int p)
{
	char	*r;

	while (s[i])
	{
		if (s[i] == SGL)
			p++;
		i++;
	}
	i = 0;
	r = ft_malloc(ft_strlen(s) + 1, 0x1);
	if (!r)
		return (NULL);
	while (s[i])
	{
		while (s[i] == SGL && s[i] && (p % 2 == 0))
			i++;
		if (!s[i])
			break ;
		r[j++] = s[i++];
	}
	r[j] = 0;
	return (r);
}

int	check_expand_1(t_minishell *m, char *s, t_env *env)
{
	if (!(m)->cmd)
		return (1);
	if (check_quotes(s)
		|| check_execute(s)
		|| check_dollar(env, s))
		return (1);
	return (0);
}

int	mini_check_11(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == SGL && s[ft_strlen(s) - 1] == SGL)
			return (0x1);
		i++;
	}
	return (0x0);
}
