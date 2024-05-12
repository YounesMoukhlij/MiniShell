/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:53:32 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/12 18:21:13 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	change_dir_1(t_env *e, char *path, int f)
{
	t_env	*tmp;
	char	*new_pwd;
	char	*buff;

	buff = NULL;
	new_pwd = NULL;
	if (f == 0x1)
	{
		tmp = env_node(&e, "PWD");
		if (tmp)
			tmp->value = ft_strdup(path);
	}
	else
	{
		new_pwd = getcwd(buff, 100);
		if (new_pwd)
		{
			tmp = env_node(&e, "OLDPWD");
			if (tmp)
				tmp->value = ft_strdup(new_pwd);
		}
	}
	free (new_pwd);
}

int	cd_1(t_env *envir)
{
	t_env	*tmp;
	int		i;

	i = 0x0;
	tmp = env_node(&envir, "HOME");
	change_dir(envir, 0x1);
	i = chdir(tmp->value);
	if (i == -1)
		return (print_error(tmp->value, 0x1), 0x0);
	change_dir(envir, 0x0);
	return (0x1);
}

int	cd_2(t_env *envir)
{
	int		i;
	char	*p;

	i = 0x0;
	p = grep_from_env(envir, "OLDPWD");
	change_dir_1(envir, p, 0x0);
	i = chdir(p);
	if (i == -1)
		return (print_error(p, 0x1), 0x0);
	change_dir_1(envir, p, 0x1);
	return (0x1);
}

int	cd_3(t_minishell *mini, t_env *envir)
{
	int	i;

	i = 0x0;
	change_dir(envir, 0x1);
	i = chdir(mini->cmd[1]);
	if (i == -1)
		return (print_error(mini->cmd[1], 1), 0x0);
	change_dir(envir, 0x0);
	return (0x1);
}

int	ft_cd(t_minishell *mini, t_env *envir)
{
	if (error_case(mini, mini->cmd[1]) || !mini->cmd[0x0])
	{
		if (mini->size > 1)
			exit (0x0);
	}
	else if (cmd_length(mini) == 1 || !strcmp_f(mini->cmd[1], "~", 0x0, 0x0))
	{
		if (!cd_1(envir))
			return (0x0);
	}
	else if (!strcmp_f(mini->cmd[0x1], "-", 0x0, 0x0))
	{
		if (!cd_2(envir))
			return (0x0);
	}
	else if (mini->cmd[1])
	{
		if (!cd_3(mini, envir))
			return (0x0);
	}
	else
		print_error("zsh: bad pattern: ", 1);
	if (mini->size > 1)
		exit (0x0);
	return (0x1);
}
