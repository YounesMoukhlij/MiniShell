/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:05:36 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/02 01:05:08 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*grep_from_env(t_env *envir, char *string)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!ft_strcmp_flag(tmp->key, string, 0))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*ft_get_path(t_env *envir)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!ft_strcmp_flag(tmp->key, "PATH", 0))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

t_env	*full_fill_env(char **env)
{
	int		i;
	char	**key_value;
	t_env	*lst_env;
	t_env	*head;

	i = 0;
	head = NULL;
	while (env[i])
	{
		key_value = ft_split_executor(env[i], '=');
		if (!key_value)
			return (NULL);
		lst_env = lstnew_executor(key_value[0], key_value[1]);
		add_back_executor(&head, lst_env);
		i++;
	}
	return (head);
}

void    full_fill_path(t_minishell *mini, t_env *envir)
{
    mini->pipex.path = malloc(sizeof(char) * ft_strlen(ft_get_path(envir)) + 1);
    if (!mini->pipex.path)
        return (free (mini->pipex.path));
    mini->pipex.path = ft_get_path(envir);
    mini->pipex.path_d = ft_split_executor(ft_get_path(envir), ':');
}
