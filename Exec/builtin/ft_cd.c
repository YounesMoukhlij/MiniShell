/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:53:32 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/29 15:29:05 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	change_dir_1(t_env *e, char *path, int f)
{
	t_env	*tmp;
	char	*buff;
	char	*new;

	buff = NULL;
	new = 0x0;
	if (f == 0x1)
	{
		tmp = env_node(&e, "PWD");
		if (tmp)
			(1) && (free (tmp->value), tmp->value = ft_strdup_1(path));
	}
	else
	{
		new = getcwd(buff, 100);
		if (new)
		{
			tmp = env_node(&e, "OLDPWD");
			if (tmp)
				(1) && (free (tmp->value), tmp->value = ft_strdup_1(new));
		}
	}
	free (new);
}

int	cd_1(t_env *envir, int i, t_env *tmp)
{
	tmp = env_node(&envir, "HOME");
	if (tmp)
	{
		change_dir(envir, 0x1, 0x0);
		i = chdir(tmp->value);
		if (i == -1)
			return (ft_put_err(tmp->value, "No such file or directory"), 0x0);
		change_dir(envir, 0x0, 0x0);
	}
	else if (!tmp)
	{
		change_dir(envir, 0x1, 0x0);
		i = chdir("/Users/youmoukh");
		if (i == -1)
			return (ft_put_err("/Users/youmoukh",
					"No such file or directory"), 0x0);
		change_dir(envir, 0x0, 0x0);
	}
	else
		return (ft_put_err(NULL, "HOME not set"), 0x0);
	return (0x1);
}

int	cd_2(t_env *envir, int i, char *p)
{
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
	int		i;
	char	*r;
	char	*str;

	i = 0x0;
	r = 0x0;
	str = ft_strdup("/Users/youmoukh/");
	change_dir(envir, 0x1, 0x0);
	if (mini->cmd[0x1][0x0] == '~')
		r = ft_strjoin_executor(str, &mini->cmd[0x1][0x2]);
	else
		r = mini->cmd[0x1];
	i = chdir(r);
	if (i == -1)
		return (ft_put_err(r, " : No such file or directory"), 0x0);
	change_dir(envir, 0x0, 0x0);
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
		if (!cd_1(envir, 0x0, 0x0))
			return (0x0);
	}
	else if (!strcmp_f(mini->cmd[0x1], "-", 0x0, 0x0))
	{
		if (!cd_2(envir, 0x0, 0x0))
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
