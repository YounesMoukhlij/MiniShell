/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:51:36 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/20 17:53:28 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	setup_pipes(int t_pipe[2])
{
	if (pipe(t_pipe) == -1)
		return (0);
	return (1);
}

void	check_env(t_minishell *mini, t_env *envir)
{
	if (!envir || !(mini)->cmd || !(mini)->cmd[0])
		return ;
	full_fill_path(mini, envir);
	if (check_fd(mini, envir))
		mini->check_err = 0x1;
	expander(&mini, envir);
}

void	handle_child_output(t_minishell *mini, int t_pipe[2])
{
	if (mini->fd_out != 1)
	{
		if (dup2(mini->fd_out, 1) == -1)
			exit(1);
		close(mini->fd_out);
	}
	else
	{
		close(t_pipe[0]);
		if (dup2(t_pipe[1], 1) == -1)
			exit(1);
		close(t_pipe[1]);
	}
}

void	h_cp(t_minishell *mini, t_env *envir, int t_pipe[2], int f)
{
	if (mini->check_err == 0x1)
	{
		ex_st_f(0x0, 0x1);
		exit(0x1);
	}
	if (mini->fd_in != 0)
	{
		if (dup2(mini->fd_in, 0) == -1)
			exit(1);
		close(mini->fd_in);
	}
	if (f == 1)
	{
		handle_child_output(mini, t_pipe);
	}
	else
	{
		if (dup2(mini->fd_out, 1) == -1)
			exit(1);
	}
	is_cmd(mini, envir);
}

void	h_pp(t_minishell *mini, int t_pipe[2], int f, int old_stdin)
{
	close(t_pipe[1]);
	if (mini->fd_in != 0)
		dup2(t_pipe[0], mini->fd_in);
	else
		dup2(t_pipe[0], 0);
	close(t_pipe[0]);
	if (f == 0)
	{
		dup2(old_stdin, 0x0);
		close(old_stdin);
	}
	else
	{
		if (mini->fd_in != 0)
		{
			dup2(mini->fd_in, 0);
			close(mini->fd_in);
		}
	}
}
