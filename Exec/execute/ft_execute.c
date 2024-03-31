/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:00:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/03/31 18:37:37 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_builtins(t_minishell *mini, t_env *envir)
{
	if (ft_strcmp_flag(mini->cmd[0], "cd", 0) == 0)
		return (ft_cd(mini), 1);
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

void	ft_execute(t_minishell **head, t_env *envir)
{
	int			flag;
	t_minishell	*tmp;

	flag = 0;
	tmp = *head;
	while (tmp)
	{
		puts("ok");
		// puts("1111\n");
		// if (tmp->next == NULL)
		// {
			if (is_builtins(tmp, envir))
				flag = 1;
			// else if (is_bin_cmd(tmp))
			// 	flag = 1;
			if (!flag)
				printf("not executed\n");
		// }
		// if (tmp->next != NULL)
		// {
		// 	if (pipe(tmp->pipex.pipe_fd))
		// 		return ;
		// 	tmp->pipex.pid = fork();
		// 	if (tmp->pipex.pid == 0)
		// 	{
		// 		dup2(tmp->pipex.pipe_fd[0], 0);
		// 		if (is_builtins(tmp))
		// 			flag = 1;
		// 		else if (is_bin_cmd(tmp))
		// 			flag = 1;
		// 		if (!flag)
		// 			printf("not executed\n");
		// 	}
		// }
		tmp = tmp->next;
	}
}

