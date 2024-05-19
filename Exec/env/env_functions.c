/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:05:36 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/19 12:52:10 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_substr_env(char *s, int start, int len)
{
	char	*r;
	int		i;
	int		l;

	i = 0;
	if (!s)
		return (NULL);
	if (!len || start >= ft_strlen(s))
		return (ft_strdup_1(""));
	l = ft_strlen(s) - start;
	if (l > len)
		l = len;
	r = malloc(sizeof(char) * (l + 1));
	if (!r)
		return (NULL);
	while (s[start] && l)
	{
		r[i] = s[start];
		start++;
		i++;
		l--;
	}
	r[i] = '\0';
	return (r);
}

t_env	*full_fill_env(char **env, int i, int j)
{
	t_env	*lst_env;
	t_env	*head;
	char	*s1;
	char	*s2;

	head = NULL;
	if (!*env)
		back_up(&head, -0x1, 0x0, 0x0);
	else
	{
		while (env[i])
		{
			j = 0x0;
			while (env[i][j] != '=')
				j++;
			s1 = ft_substr_env(env[i], 0x0, j);
			s2 = ft_substr_env(env[i], j + 0x1, ft_strlen(env[i]));
			lst_env = lstnew_executor(s1, s2, 0);
			add_back_executor(&head, lst_env);
			i++;
		}
	}
	return (head);
}

void	full_fill_path(t_minishell *mini, t_env *envir)
{
	mini->path = ft_malloc(ft_strlen(ft_get_path(envir)) + 0x1, 0x1);
	if (!mini->path)
		return ;
	mini->path = ft_get_path(envir);
	mini->path_d = ft_split_executor(ft_get_path(envir), ':');
}
