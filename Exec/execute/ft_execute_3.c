/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:18:49 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/08 17:36:49 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_builtin_cmd(t_minishell *m, t_env *envir)
{
	full_fill_path(m, envir);
	if (check_fd(m, envir))
		return (0x1);
	m->export = full_fill_print(&envir);
    expander(&m, envir);
	handle_fd(m);
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
		return (ft_echo(m, 0x1 , 0x0));
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

char	**get_cmd_splited(char **s, int len, int j, int p)
{
	char	**r;
	char	**res;
	int		l_n;

	l_n = 0x0;
	r = ft_split_executor(s[0x0], ' ');
	while (r[l_n])
		l_n++;
	res = malloc(sizeof(char *) * (l_n + len + 1));
	if (!res)
		return (NULL);
	res[l_n + len] = NULL;
	while (j < l_n)
	{
		res[j] = ft_strdup(r[j]);
		j++;
	}
	while (j < l_n + len)
	{
		res[j] = ft_strdup(s[p]);
		p++;
		j++;
	}
	return (res);
}

int	is_bin_cmd(t_minishell *mini, t_env *envir, int flag)
{
	int		i;
	char	*s;
	char	**res;
	int		e_s;

	i = 0x0;
	if (env_check(&envir, mini->cmd[0x0]))
		return (exit(0x1), 0x0);
	if (check_cmd(mini->cmd[0x0]))
		res = get_cmd_splited(mini->cmd, cmd_length(mini), 0x0, 0x1);
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
			{
				flag = 0x0;
				break;
			}
		}
		i++;
	}
	if (flag == 0x0)
	{
		e_s = ex_st_f(exve_err(mini->cmd[0x0]), 0x1);
		exit(e_s);
	}
	return (0x1);
}
