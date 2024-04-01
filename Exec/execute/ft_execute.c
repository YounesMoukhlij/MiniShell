/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:00:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/01 01:48:19 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_builtins(t_minishell *mini, t_env *envir)
{
	if (ft_strcmp_flag(mini->cmd[0], "cd", 0) == 0)
		return (ft_cd(mini, envir), 1);
	else if (ft_strcmp_flag(mini->cmd[0], "env", 0) == 0)
		return (ft_env(envir), 1);
	else if (ft_strcmp_flag(mini->cmd[0], "pwd", 0) == 0)
		return (ft_pwd(mini), 1);
	else if (ft_strcmp_flag(mini->cmd[0], "export", 0) == 0)
		return (ft_export(mini, envir), 1);
	else if (ft_strcmp_flag(mini->cmd[0], "exit", 0) == 0)
		return (ft_exit(), 1);
	else if (ft_strcmp_flag(mini->cmd[0], "unset", 0) == 0)
		return (ft_unset(mini, envir), 1);
	else if (ft_strcmp_flag(mini->cmd[0], "echo", 0) == 0)
		return (ft_echo(mini), 1);
	else
		return (0);
}

int	is_bin_cmd(t_minishell *mini)
{
	(void ) mini;
	int		i;
	char	*s;

	i = 0;
	// // mini->pipex.pid = fork();
	// // pipe(mini->pipex.pipe_fd);
	// // if (mini->pipex.pid == 0)
	// // {
	// 	// printf("\nhere CHild\n");
		while (mini->pipex.path_d[i])
		{
			s = ft_strjoin_space_executor(mini->pipex.path_d[i], mini->cmd[0], '/');
			if (access(s, X_OK) != -1)
			{
				execve(s, mini->cmd, NULL);
			}
			free (s);
			i++;
		}
	return (1);
}

void	big_execution(t_minishell *mini, t_env *envir, int stdin)
{
	int	t_pipe[2];
	int	pid;
	int	flag;
	

	flag =  -1;
	if (pipe(t_pipe) == -1)
		return ;
	pid = fork();
	if (pid == 0)
	{
		dup2(t_pipe[1], 1);
		if (is_builtins(mini, envir))
			flag = 1;
		else if (is_bin_cmd(mini))
			flag = 1;
		if (!flag)
			printf("not executed\n");
	}
	else
	{
		dup2(t_pipe[0], stdin);
	}
}

void	ft_execute(t_minishell **head, t_env *envir)
{
	// int			flag;
	t_minishell	*tmp;
	int			old_stdin;

	old_stdin = 0;

	tmp = *head;
	dup2(old_stdin, 0);
	while (tmp->next)
	{
		printf("asd");
		big_execution(tmp, envir, old_stdin);
		tmp = tmp->next;
	}
	if (tmp)
	{
		big_execution(tmp, envir, old_stdin);
	}
}


	// puts("ok");
	// 	// puts("1111\n");
	// 		if (pipe(tmp->pipex.pipe_fd))
	// 			return ;
	// 		tmp->pipex.pid = fork();
	// 	if (tmp->next == NULL)
	// 	{
	// 		if (tmp->pipex.pid == 0)
	// 		{
	// 			dup2(tmp->pipex.pipe_fd[0], 0);
	// 			if (is_builtins(tmp, envir))
	// 				flag = 1;
	// 			else if (is_bin_cmd(tmp))
	// 				flag = 1;
	// 			if (!flag)
	// 				printf("not executed\n");
	// 		}
	// 	}
	// 	// if (tmp->next != NULL)
	// 	// {
	// 	// 	if (tmp->pipex.pid == 0)
	// 	// 	{
	// 	// 		if (is_builtins(tmp))
	// 	// 			flag = 1;
	// 	// 		else if (is_bin_cmd(tmp))
	// 	// 			flag = 1;
	// 	// 		if (!flag)
	// 	// 			printf("not executed\n");
	// 	// 	}
	// 	// }