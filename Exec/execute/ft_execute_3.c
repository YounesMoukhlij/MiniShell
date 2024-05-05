/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:18:49 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/05 14:03:52 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_builtin_cmd(t_minishell *m, t_env *envir)
{
	if (m->size > 0x1)
		return (0x0);
	full_fill_path(m, envir);
	if (check_fd(m, envir))
		return (0x1);
    expander(&m, envir);
	// handle_fd(m);
	m->export = full_fill_print(&envir);
	if (!strcmp_f(m->cmd[0], "cd", 0, 0))
		return (ft_cd(m, envir));
	else if (!strcmp_f(m->cmd[0], "env", 0, 0) || !strcmp_f(m->cmd[0], "ENV", 0, 0))
		return (ft_env(m, envir));
	else if (!strcmp_f(m->cmd[0], "pwd", 0, 0) || !strcmp_f(m->cmd[0], "PWD", 0, 0 ))
		return (ft_pwd(m, &envir));
	else if (!strcmp_f(m->cmd[0], "export", 0, 0))
		return (ft_export(m, envir, 0x1));
	else if (!strcmp_f(m->cmd[0], "exit", 0, 0))
		return (ft_exit(m), 1);
	else if (!strcmp_f(m->cmd[0], "unset", 0, 0))
		return (ft_unset(m, envir));
	else if (!strcmp_f(m->cmd[0], "echo", 0, 0) || !strcmp_f(m->cmd[0], "ECHO", 0, 0))
		return (ft_echo(m));
	else
		return (-1);
}

int	is_builtin(t_minishell *m)
{
	if (!strcmp_f(m->cmd[0], "cd", 0, 0))
		return (0x1);
	else if (!strcmp_f(m->cmd[0], "env", 0, 0) || !strcmp_f(m->cmd[0], "ENV", 0, 0))
		return (0x1);
	else if (!strcmp_f(m->cmd[0], "pwd", 0, 0) || !strcmp_f(m->cmd[0], "PWD", 0, 0 ))
		return (0x1);
	else if (!strcmp_f(m->cmd[0], "export", 0, 0))
		return (0x1);
	else if (!strcmp_f(m->cmd[0], "exit", 0, 0))
		return (0x1);
	else if (!strcmp_f(m->cmd[0], "unset", 0, 0))
		return (0x1);
	else if (!strcmp_f(m->cmd[0], "echo", 0, 0) || !strcmp_f(m->cmd[0], "ECHO", 0, 0))
		return (0x1);
	else
		return (0x0);
}

int	is_bin_cmd(t_minishell *mini, t_env *envir, int flag)
{
	int		i;
	char	*s;
	char	**res;

	i = 0x0;
	if (env_check(&envir, mini->cmd[0x0]))
		return (exit(0x1), 0x0);
	if (check_cmd(mini->cmd[0x0]))
		res = ft_split_executor(mini->cmd[0x0], ' ');
	else
		res = mini->cmd;
	while (mini->path_d[i])
	{
		if (!(res[0x0][0x0] == '.' ||  res[0x0][0x0] == '/'))
			s = ft_strjoin_space_executor(mini->path_d[i], res[0x0], '/');
		else
			s = res[0x0];
		if (access(s, X_OK) == 0x0)
		{
			flag = 0x1;
			if (execve(s, res, execv_env(envir)) == -1)
					break ;
		}
		free (s);
		i++;
	}
	if (flag == 0x0)
	{
		ex_st_f(exve_err(mini->cmd[0x0]), 0x1);
		exit(ex_st_f(exve_err(mini->cmd[0x0]), 0x0));
	}
	return (0x1);
}
