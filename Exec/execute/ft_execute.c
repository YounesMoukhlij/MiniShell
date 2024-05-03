/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:00:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/25 18:27:48 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_bin_cmd(t_minishell *mini, t_env *envir, int flag)
{
	int		i;
	char	*s;
	char	**res;
	int		sum;

	i = 0x0;
	sum = 0x0;
	if (env_check(&envir, mini->cmd[0x0]))
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
					break ;
		}
		free (s);
		i++;
	}
	if (flag == 0x0)
	{
		sum = exve_err(mini->cmd[0x0]);
		exit_status = sum;
		exit(sum);
	}
	return (0x1);
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

void	big_execution(t_minishell *mini, t_env *envir, int f, int old_stdin)
{
	int	t_pipe[2];
	int	pid;
	int	return_exve;

	full_fill_path(mini, envir);
	if (check_fd(mini, envir))
		return ;
	expander(&mini, envir);
	mini->export = full_fill_print(&envir);
	if (pipe(t_pipe) == -1)
		return ;
		// childs_pipes(t_pipe[0], t_pipe[1], mini, f);
		// parent_pipes(t_pipe[0], t_pipe[1], mini, f);
	if (mini->fd_in != 0)
	{
		dup2(mini->fd_in, 0);
		close(mini->fd_in);
	}
	pid = fork();
	if (pid == 0)
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
		is_cmd(mini, envir);
	}
	else
	{
		if (waitpid(-1, &return_exve, 0x0) == -1)
			return ;
		return_exve >>= 0x8;
		if (return_exve != 0x0)
			exit_status = return_exve;
		else
			exit_status = 0x0;
		if (f == 0)
		{
			dup2(old_stdin, 0);
			close(old_stdin);
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
}

void	handle_fd(t_minishell *mini)
{
	puts("here");
	if (mini->fd_out != 0x1)
	{
		puts("aaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbYOUNES");
		dup2(mini->fd_out, 1);
		puts("aaaaaaaa");
		// close(mini->fd_out);
		// if (dup2(mini->fd_out, 0x1) == -1)
		// 	return (ft_putstr_fd("dup failed", 0x2));
	}
	if (mini->fd_in != 0x0)
	{
		dup2(mini->fd_in, 0x0);
		// close(mini->fd_in);
		// if (dup2(mini->fd_in, 0x0) == -0x1)
		// 	return (ft_putstr_fd("dup failed", 0x2));
	}
}

int	is_builtin_cmd(t_minishell *m, t_env *envir)
{
	if (m->size > 0x1)
		return (0x0);
	full_fill_path(m, envir);
	if (check_fd(m, envir))
		return (0x1);
    expander(&m, envir);
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

void	ft_execute(t_minishell **head, t_env *envir, int flag)
{
	t_minishell	*tmp;
	int			old_stdin;

	tmp = *head;
	old_stdin = 0x0;
	old_stdin = dup((*head)->fd_in);
	if ((*head)->size == 0x1 && is_builtin(*head))
	{
		flag = is_builtin_cmd(*head, envir);
		if (flag != -1)
		{
			if (flag == 0x1)
				exit_status = 0x0;
			else if (flag != -1)
				exit_status = 0x1;
			return ;
		}
	}
	while (tmp->next)
	{
		big_execution(tmp, envir, 0x1, old_stdin);
		tmp = tmp->next;
	}
	if (tmp)
		big_execution(tmp, envir, 0x0, old_stdin);
	while (wait(0) != -1);
}
