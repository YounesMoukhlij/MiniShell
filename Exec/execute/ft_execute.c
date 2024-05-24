/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:00:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/23 20:28:45 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	msg_error_fork(void)
{
	static int	error_printed;

	error_printed = 0;
	if (!error_printed)
	{
		perror("fork");
		error_printed = 1;
	}
	else
		return ;
}

int	safe_fork(void)
{
	int	id;

	id = fork();
	if (id == -1)
		msg_error_fork();
	return (id);
}

int	big_execution(t_minishell *mini, t_env *envir, int f, int old_stdin)
{
	int	t_pipe[2];

	check_env(mini, envir);
	if (!envir || !(mini)->cmd || !(mini)->cmd[0])
	{
		check_fd(mini, envir);
		return (0);
	}
	if (!setup_pipes(t_pipe))
		return (0);
	signal(SIGQUIT, signal_handler_child);
	mini->pid_fork = safe_fork();
	if (mini->pid_fork == -0x1)
		return (0);
	if (mini->pid_fork == 0x0)
		h_cp(mini, envir, t_pipe, f);
	else
		h_pp(mini, t_pipe, f, old_stdin);
	return (1);
}

void	handle_fd(t_minishell *mini)
{
	if ((mini)->fd_out != 0x1)
	{
		if (dup2((mini)->fd_out, 0x1) == -1)
			return (perror("dup2"));
	}
	if ((mini)->fd_in != 0x0)
	{
		if (dup2((mini)->fd_in, 0x0) == -1)
			return (perror("dup2"));
	}
}

void	status(void)
{
	int	return_exve;

	while (wait(&return_exve) > 0)
		;
	if (WIFSIGNALED(return_exve))
		ex_st_f(WTERMSIG(return_exve) + 128, 0x1);
	else
		ex_st_f(WEXITSTATUS(return_exve), 0x1);
	if (ex_st_f(0x0, 0x0) == 141)
		ex_st_f(0x0, 0x1);
}

int	return_cmd(int f)
{
	if (f != -1)
	{
		if (f == 0x1)
			ex_st_f(0x0, 0x1);
		else if (f != -1)
			ex_st_f(0x1, 0x1);
		return (0x1);
	}
	else
		return (0x1);
	return (0x0);
}

void	ft_execute(t_minishell **head, t_env *envir, int flag, int f)
{
	t_minishell	*tmp;
	int			old_stdin;

	(1) && (tmp = *head, old_stdin = dup(0));
	if ((*head)->size == 0x1 && is_builtin(*head))
	{
		flag = is_builtin_cmd(*head, envir);
		if (return_cmd(flag))
		{
			close(old_stdin);
			return ;
		}
	}
	while (tmp->next)
	{
		f = big_execution(tmp, envir, 0x1, old_stdin);
		if (f == 0x1)
			break ;
		tmp = tmp->next;
	}
	if (tmp)
		f = big_execution(tmp, envir, 0x0, old_stdin);
	if (f == 0x1)
		status();
	close(old_stdin);
}
