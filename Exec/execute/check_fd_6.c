/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:32:30 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/23 16:25:21 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*grep_from_env_1(t_env *envir, char *string)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!strcmp_f(tmp->key, string, 0x0, 0x0))
		{
			if (!tmp->value)
			{
				return (ft_strdup(""));
			}
			return (tmp->value);
		}
		tmp = tmp->next;
	}
	return (ft_strdup(""));
}

char	*allocate_max_1(t_env *envir)
{
	char	*r;

	(void) envir;
	r = ft_calloc_1(300 * 10, 1);
	return (r);
}

char	*grep_value_1(char *s)
{
	int		len;
	int		i;
	char	*r;

	len = 0x0;
	if (!s)
		return (NULL);
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
