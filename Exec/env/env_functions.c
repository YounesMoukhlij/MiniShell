/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:05:36 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/05 23:29:12 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*grep_from_env(t_env *envir, char *string)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!ft_strcmp_flag(tmp->key, string, 0, 0))
			return (tmp->value);
		tmp = tmp->next;
	}
	return ("");
}

char	*ft_get_path(t_env *envir)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!ft_strcmp_flag(tmp->key, "PATH", 0, 0))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

t_env	*full_fill_env(char **env)
{
	int		i;
	int		j;
	t_env	*lst_env;
	t_env	*head;
	char	*s1;
	char	*s2;

	i = 0;
	head = NULL;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		s1 = ft_substr_executor(env[i], 0, j);
		s2 = ft_substr_executor(env[i], j + 1, ft_strlen(env[i]));
		lst_env = lstnew_executor(s1, s2);
		add_back_executor(&head, lst_env);
		i++;
	}
	return (head);
}

void    full_fill_path(t_minishell *mini, t_env *envir)
{
    mini->path = malloc(sizeof(char) * ft_strlen(ft_get_path(envir)) + 1);
    if (!mini->path)
        return (free (mini->path));
    mini->path = ft_get_path(envir);
    mini->path_d = ft_split_executor(ft_get_path(envir), ':');
}
