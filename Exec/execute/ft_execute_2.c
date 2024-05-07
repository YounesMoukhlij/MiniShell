/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:18:43 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/07 18:36:34 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	env_check(t_env	**eenv, char *s)
{
	if (!eenv || check_path(eenv, s))
		return (0x1);
	return (0x0);
}

int	check_s(char *s)
{
	if (s[0x0] == '.' && s[0x1] == '/')
		return (0x1);
	return (0x0);
}

int	is_cmd(t_minishell *mini, t_env *envir)
{
	if (!strcmp_f(mini->cmd[0], "cd", 0, 0))
		return (ft_cd(mini, envir));
	else if (!strcmp_f(mini->cmd[0], "env", 0, 0)
		|| !strcmp_f(mini->cmd[0], "ENV", 0, 0))
		return (ft_env(mini, envir));
	else if (!strcmp_f(mini->cmd[0], "pwd", 0, 0)
		|| !strcmp_f(mini->cmd[0], "PWD", 0, 0 ))
		return (ft_pwd(mini ,&envir));
	else if (!strcmp_f(mini->cmd[0], "export", 0, 0))
		return (ft_export(mini, envir, 0x1));
	else if (!strcmp_f(mini->cmd[0], "exit", 0, 0))
		return (ft_exit(mini), 1);
	else if (!strcmp_f(mini->cmd[0], "unset", 0, 0))
		return (ft_unset(mini, envir));
	else if (!strcmp_f(mini->cmd[0], "echo", 0, 0)
		|| !strcmp_f(mini->cmd[0], "ECHO", 0, 0))
		return (ft_echo(mini));
	else
		return (is_bin_cmd(mini, envir, 0x0));
}

int	exve_err(char *s)
{
	struct stat		buf;

	if (stat(s, &buf) == 0 && strcmp_f(s, "..", 0x0, 0x0))
	{
		if (!strcmp_f(s, ".", 0x0, 0x0))
			return (0x2);
		if (buf.st_mode & S_IFDIR)
			return (ft_put_err(s, ": Is a directory"), 126);
		else if ((buf.st_mode & S_IXUSR) == 0)
			return (ft_put_err(s, ": Permission denied"), 127);
	}
	else if (is_empty(s))
		return (0x0);
	else if (check_s(s))
		return (ft_put_err(s, ": No such file or directory"), 127);
	return (ft_put_err(s, ": Command not found"), 127);
}
