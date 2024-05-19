/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:51:48 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/19 12:52:14 by youmoukh         ###   ########.fr       */
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
	return (ft_strdup_1(""));
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

void	back_up(t_env **ennv, int i, char *pwd, char *buff)
{
	t_env	*lst;
	char	*str;

	str = "/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.";
	pwd = getcwd(buff, sizeof(pwd));
	if (!pwd)
		return ;
	while (++i <= 0x4)
	{
		if (i == 0x0)
			lst = lstnew_executor(ft_strdup_1("PWD"), ft_strdup_1(pwd), 0);
		if (i == 0x1)
			lst = lstnew_executor(ft_strdup_1("SHLVL"), ft_strdup_1("1"), 0);
		if (i == 0x2)
			lst = lstnew_executor(ft_strdup_1("_"),
					ft_strdup_1("/usr/bin/env"), 0);
		if (i == 0x3)
			lst = lstnew_executor(ft_strdup_1("PATH"), ft_strdup_1(str), 0);
		if (i == 0x4)
			lst = lstnew_executor(ft_strdup_1("TERM"),
					ft_strdup_1("xterm-256color"), 0);
		add_back_executor(ennv, lst);
	}
	free (pwd);
}
