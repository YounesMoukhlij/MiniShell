/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:00:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/04 18:34:02 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
			ex_st_f(return_exve, 0x1);
		else
			ex_st_f(0x0, 0x1);
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
	if (mini->fd_out != 0x1)
	{
		printf("%d\n", mini->fd_out);
		dup2(3, 1);
	}
	// if (mini->fd_in != 0x0)
	// {
	// 	dup2(mini->fd_in, 0x0);
	// 	// close(mini->fd_in);
	// 	// if (dup2(mini->fd_in, 0x0) == -0x1)
	// 	// 	return (ft_putstr_fd("dup failed", 0x2));
	// }
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
				ex_st_f(0x0, 0x1);
			else if (flag != -1)
				ex_st_f(0x0, 0x1);
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
