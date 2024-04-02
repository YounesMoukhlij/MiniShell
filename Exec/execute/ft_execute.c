/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:00:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/02 03:04:44 by youmoukh         ###   ########.fr       */
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

int	is_bin_cmd(t_minishell *mini, t_env *envir, char **env)
{
	int		i;
	char	*s;
	// char	**str;
	(void) envir;
	// t_env	*tmp;

	// tmp = envir;
	// str = malloc(sizeof(char *) * lst_size_executor(&tmp) + 1);
	// if (!str)
	// 	return (0);
	// i = 0;
	// while ((tmp))
	// {
	// 	str[i] = ft_strdup(ft_strjoin_executor((tmp)->key, (tmp)->value));
	// 	i++;
	// 	(tmp) = (tmp)->next;
	// }
	// str[i] = 0;
	// while (str[i])
	i = 0;
	while (mini->pipex.path_d[i])
	{
		s = ft_strjoin_space_executor(mini->pipex.path_d[i], mini->cmd[0], '/');
		if (access(s, X_OK) != -1)
		{
			execve(s, mini->cmd, env);
		}
		free (s);
		i++;
	}
	return (1);
}

void	big_execution(t_minishell *mini, t_env *envir, int stdin, int f, char **env)
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
		if (f == 1)
		{
			close (t_pipe[0]);
			dup2(t_pipe[1], 1);
			close (t_pipe[1]);
		}
		if (is_builtins(mini, envir))
			flag = 1;
		else if (is_bin_cmd(mini, envir, env))
			flag = 1;
		if (!flag)
			printf("not executed\n");
	}
	else
	{
		if (f == 0)
		{
			dup2(stdin, 0);
			close(stdin);
		}
		else
		{
			close(t_pipe[1]);
			dup2(t_pipe[0], 0);
		}
	}	
}

void	ft_execute(t_minishell **head, t_env *envir, char **env)
{
	t_minishell	*tmp;
	int			old_stdin;

	tmp = *head;
	old_stdin = dup(tmp->fd_in);
	while (tmp->next)
	{
		puts("11111\n");
		// printf("%s\n", tmp->cmd[0]);
		big_execution(tmp, envir, old_stdin, 1, env);
		tmp = tmp->next;
	}
	if (tmp)
	{
		// printf("%s\n", tmp->cmd[0]);
		puts("mmmmmmm");
		big_execution(tmp, envir, old_stdin, 0, env);
	}
	while (wait(0) != -1);
}
