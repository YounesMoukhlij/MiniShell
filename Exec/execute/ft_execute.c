/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:00:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/24 18:18:00 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**execv_env(t_env *envir)
{
	char	**str;
	char	*string;
	t_env 	*tmp;
	int		i;

	i = 0;
	tmp = envir;
	str = malloc(sizeof(char *) * lst_size_executor(&tmp) + 1);
	if (!str)
		return (NULL);
	while (tmp)
	{
		string = ft_strjoin_space_executor(tmp->key, tmp->value, '=');
		if (tmp->next)
		 	str[i++] = strdup(string);
		free (string);
		tmp = tmp->next;
	}
	str[i] = 0;
	return (str);
}

int	check_cmd(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0x0);
	while (s[i])
	{
		if (s[i] == ' ')
			return (0x1);
		i++;
	}
	return (0x0);
}

int	env_check(t_env	**eenv)
{
	if (!eenv)
		return (0x1);
	(void) eenv;
	return (0x0);
}

int	is_bin_cmd(t_minishell *mini, t_env *envir, int flag)
{
	int		i;
	char	*s;
	char	**res;

	i = 0x0;
	if (env_check(&envir))
		return (exit(0x1), 0x0);
	if (check_cmd(mini->cmd[0x0]))
		res = ft_split_executor(mini->cmd[0x0], ' ');
	else
		res = mini->cmd;
	while (mini->path_d[i])
	{
		s = ft_strjoin_space_executor(mini->path_d[i], res[0x0], '/');
		if (access(s, X_OK) == 0x0)
		{
			flag = 0x1;
			if (execve(s, res, execv_env(envir)) == -1)
			{
				free (s);
				break;
			}
		}
		free (s);
		i++;
	}
	if (flag == 0x0)
	{
		exit_status = 127;
		printf("MiniShell: command not found: %s\n", mini->cmd[0x0]);
		exit(127);
	}
	return (0x1);
}


int	is_cmd(t_minishell *mini, t_env *envir)
{
	if (!ft_strcmp_flag(mini->cmd[0], "cd", 0, 0))
		return (ft_cd(mini, envir));
	else if (!ft_strcmp_flag(mini->cmd[0], "env", 0, 0) || !ft_strcmp_flag(mini->cmd[0], "ENV", 0, 0))
		return (ft_env(envir));
	else if (!ft_strcmp_flag(mini->cmd[0], "pwd", 0, 0) || !ft_strcmp_flag(mini->cmd[0], "PWD", 0, 0 ))
		return (ft_pwd(&envir));
	else if (!ft_strcmp_flag(mini->cmd[0], "export", 0, 0))
		return (ft_export(mini, envir, 0x1));
	else if (!ft_strcmp_flag(mini->cmd[0], "exit", 0, 0))
		return (ft_exit(mini), 1);
	else if (!ft_strcmp_flag(mini->cmd[0], "unset", 0, 0))
		return (ft_unset(mini, envir));
	else if (!ft_strcmp_flag(mini->cmd[0], "echo", 0, 0) || !ft_strcmp_flag(mini->cmd[0], "ECHO", 0, 0))
		return (ft_echo(mini));
	else
		return (is_bin_cmd(mini, envir, 0x0));
}

// void	childs_pipes(int zero, int one, t_minishell *m, int f)
// {
// 	if (f == 1)
// 	{
// 		close (zero);
// 		if (m->fd_out != 1)
// 			dup2(one, m->fd_out);
// 		else
// 			dup2(one, 1);
// 		close (one);
// 	}
// }

// void	parent_pipes(int zero, int one, t_minishell *m, int f)
// {
// }

void	big_execution(t_minishell *mini, t_env *envir, int std_in, int f)
{
	int	t_pipe[2];
	int	pid;
	int	flag;

    full_fill_path(mini, envir);
	check_fd(mini, envir);
    expander(&mini, envir);
	mini->export = full_fill_print(&envir);
	flag = -1;
	// printf("cmd[0] = %s\n", mini->cmd[0]);
	// printf("cmd[1] = %s\n", mini->cmd[1]);
	// signal(SIGINT, signal_handler_two);
	if (pipe(t_pipe) == -1)
		return ;
		// childs_pipes(t_pipe[0], t_pipe[1], mini, f);
		// parent_pipes(t_pipe[0], t_pipe[1], mini, f);
	if (mini->fd_in != 0)
	{
		dup2(mini->fd_in, 0);
		close(mini->fd_in);
	}
	if (fork())
	{
		if (f == 1)
		{
			close (t_pipe[0]);
			if (mini->fd_out != 1)
				dup2(mini->fd_out, 1);
			else
				dup2(t_pipe[1], 1);
		}
		else
			dup2(mini->fd_out, 1);
		flag = is_cmd(mini, envir);
	}
	else
	{
		pid = waitpid(-1, &exit_status, 0);
		exit_status >>= 8;
		if (pid == -1)
			return ;
		printf("exit ->[%d]\n", exit_status);
		if (f == 0)
		{
			dup2(std_in, 0);
			close(std_in);
		}
		else
		{
			if (mini->fd_in != 0)
			{
				dup2(mini->fd_in, 0);
				close(mini->fd_in);
			}
			else
			{
				close(t_pipe[1]);
				if (mini->fd_in != 0)
					dup2(t_pipe[0], mini->fd_in);
				else
					dup2(t_pipe[0], 0);
				close(t_pipe[0]);
			}
		}
	}
	if (flag == 0x1)
	{
		puts(">1<");
		exit_status = 0x0;
	}
	else
	{
		puts(">2<");
		exit_status = 127;
	}
}

int	lst_size(t_minishell **head)
{
	int			i;
	t_minishell	*tmp;

	i = 0;
	tmp = *head;
	while ((tmp))
	{
		(tmp) = (tmp)->next;
		i++;
	}
	return (i);
}

int	is_builtin_cmd(t_minishell *m, t_env *envir)
{
	if (lst_size(&m) != 1)
		return (0x0);
	full_fill_path(m, envir);
	check_fd(m, envir);
    expander(&m, envir);
	m->export = full_fill_print(&envir);
	if (!ft_strcmp_flag(m->cmd[0], "cd", 0, 0))
		return (ft_cd(m, envir));
	else if (!ft_strcmp_flag(m->cmd[0], "env", 0, 0) || !ft_strcmp_flag(m->cmd[0], "ENV", 0, 0))
		return (ft_env(envir));
	else if (!ft_strcmp_flag(m->cmd[0], "pwd", 0, 0) || !ft_strcmp_flag(m->cmd[0], "PWD", 0, 0 ))
		return (ft_pwd(&envir));
	else if (!ft_strcmp_flag(m->cmd[0], "export", 0, 0))
		return (ft_export(m, envir, 0x1));
	else if (!ft_strcmp_flag(m->cmd[0], "exit", 0, 0))
		return (ft_exit(m), 1);
	else if (!ft_strcmp_flag(m->cmd[0], "unset", 0, 0))
		return (ft_unset(m, envir));
	else if (!ft_strcmp_flag(m->cmd[0], "echo", 0, 0) || !ft_strcmp_flag(m->cmd[0], "ECHO", 0, 0))
		return (ft_echo(m));
	else
		return (0x0);
}

void	ft_execute(t_minishell **head, t_env *envir, char **env)
{
	t_minishell	*tmp;
	int			old_stdin;

	tmp = *head;
	old_stdin = 0;
	old_stdin = dup(tmp->fd_in);
	(void) env;
	if (is_builtin_cmd(*head, envir))
		return ;
	while (tmp->next)
	{
		big_execution(tmp, envir, old_stdin, 1);
		tmp = tmp->next;
	}
	if (tmp)
		big_execution(tmp, envir, old_stdin, 0);
	while (wait(0) != -1);
}
