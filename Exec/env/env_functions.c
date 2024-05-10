/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:05:36 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/10 18:22:18 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*grep_from_env(t_env *envir, char *string)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!strcmp_f(tmp->key, string, 0x0, 0x0))
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
		if (!strcmp_f(tmp->key, "PATH", 0x0, 0x0))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	back_up(t_env **ennv, int i)
{
	t_env	*lst;
	char	*pwd;
	char	*buff;

	buff = NULL;
	pwd = getcwd(buff, sizeof(pwd));
	if (!pwd)
		return ;
	while (i++ < 0x4)
	{
		if (i == 0x0)
			lst = lstnew_executor("PWD", pwd);
		if (i == 0x1)
			lst = lstnew_executor("SHLVL", "1");
		if (i == 0x2)
			lst = lstnew_executor("_", "/usr/bin/env");
		if (i == 0x3)
			lst = lstnew_executor("PATH",
					"/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
		add_back_executor(ennv, lst);
	}
}

t_env	*full_fill_env(char **env, int i, int j)
{
	t_env	*lst_env;
	t_env	*head;
	char	*s1;
	char	*s2;
	// char	*tmp;

	head = NULL;
	if (!*env)
		back_up(&head, 0x0);
	else
	{
		while (env[i])
		{
			j = 0x0;
			while (env[i][j] != '=')
				j++;
			s1 = ft_substr_executor(env[i], 0x0, j);
			s2 = ft_substr_executor(env[i], j + 0x1, ft_strlen(env[i]));
			// if (!strcmp_f(s1, "SHLVL", 0x0, 0x0))
			// {
			// 	tmp = ft_itoa(ft_atoi(s2) + 1);
			// 	s2 = ft_strdup(tmp);
			// 	free (tmp);
			// }
			lst_env = lstnew_executor(s1, s2);
			// free(s2);
			add_back_executor(&head, lst_env);
			i++;
		}
	}
	return (head);
}

void	full_fill_path(t_minishell *mini, t_env *envir)
{
	char	*r;

	r = ft_get_path(envir);
	mini->path = malloc(sizeof(char) * ft_strlen(r) + 0x1);
	if (!mini->path)
		return ;
	mini->path = r;
	mini->path_d = ft_split_executor(r, ':');
}
