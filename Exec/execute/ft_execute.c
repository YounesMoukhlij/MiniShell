/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:00:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/03 18:41:57 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	is_bin_cmd(t_minishell *mini, t_env *envir, char **env)
{
	int		i;
	char	*string;
	char	**str;
	char	*s;

	(void) env;
	(void) mini;
	(void) string;
	str = malloc(sizeof(char *) * lst_size_executor(&envir) + 1);
	if (!str)
		return ;
	i = 0;
	// while (env[i])
	// {
	// 	// printf("%s\n", env[i]);
	// 	i++;
	// }
	// printf("%d && %d\n", i, lst_size_executor(envir) + 1);
	// while ((*envir))
	// {
	// 	// if (!((*envir)->key) || !((*envir)->value))
	// 	// {
	// 	printf("key[%s]=value[%s]\n", (*envir)->key, (*envir)->value);
	// 	// 	break ;
	// 	// }
	// 	// puts("asdasd");
	// 	// string = ft_strjoin_space_executor((*envir)->key, (*envir)->value, '=');
	// 	// if (!string)
	// 	// 	break ;
	// 	// // printf("%s\n", string);
	// 	// str[i] = ft_strdup(string);
	// 	// i++;
	// 	// // free (string);
	// 	(*envir) = (*envir)->next;
	// }
	// str[i] = 0;
	// i = 0;
	// while (str[i])
	// {
	// 	printf("%s\n", str[i]);
	// 	i++;
	// }
	i = 0;
	while (mini->path_d[i])
	{
		s = ft_strjoin_space_executor(mini->path_d[i], mini->cmd[0], '/');
		if (access(s, X_OK) == 0)
			execve(s, mini->cmd, env);
		free (s);
		i++;
	}
	printf("MiniShell: command not found: %s\n", mini->cmd[0]);
	exit(1);
}

int	is_cmd(t_minishell *mini, t_env *envir, char **env)
{
	if (!ft_strcmp_flag(mini->cmd[0], "cd", 0))
		return (ft_cd(mini, envir));
	else if (!ft_strcmp_flag(mini->cmd[0], "env", 0) || !ft_strcmp_flag(mini->cmd[0], "ENV", 0))
		return (ft_env(envir));
	else if (!ft_strcmp_flag(mini->cmd[0], "pwd", 0) || !ft_strcmp_flag(mini->cmd[0], "PWD", 0) )
		return (ft_pwd(mini));
	else if (!ft_strcmp_flag(mini->cmd[0], "export", 0))
		return (ft_export(mini, envir));
	else if (!ft_strcmp_flag(mini->cmd[0], "exit", 0))
		return (ft_exit(), 1);
	else if (!ft_strcmp_flag(mini->cmd[0], "unset", 0))
		return (ft_unset(mini, envir));
	else if (!ft_strcmp_flag(mini->cmd[0], "echo", 0) || !ft_strcmp_flag(mini->cmd[0], "ECHO", 0))
		return (ft_echo(mini));
	else
		is_bin_cmd(mini, envir, env);
	return (0x0);
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

void	big_execution(t_minishell *mini, t_env *envir, int std_in, int f, char **env)
{
	int	t_pipe[2];
	int	pid;
	
    full_fill_path(mini, envir);
	check_fd(mini, envir);
    expander(&mini, envir);
	if (pipe(t_pipe) == -1)
		return ;
	pid = fork();
		// childs_pipes(t_pipe[0], t_pipe[1], mini, f);
		// parent_pipes(t_pipe[0], t_pipe[1], mini, f);
	if (pid == 0)
	{
		if (f == 1)
		{
			close (t_pipe[0]);
			// if (mini->fd_out != 1)
				dup2(t_pipe[1], mini->fd_out);
			// else
				// dup2(t_pipe[1], 1);
			close (t_pipe[1]);
		}	
		is_cmd(mini, envir, env);
	}
	else
	{
		if (f == 0)
		{
			if (mini->fd_in != 0)
				dup2(std_in, mini->fd_in);
			else
				dup2(std_in, 0);
			close(std_in);
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
	// dsfdsfdsfdsdsfsdsf
	// if (pid == 0)
	// {
	// 	if (f == 1)
	// 	{
	// 		// if (mini->fd_out == 1)
	// 		close (t_pipe[0]);
	// 		dup2(t_pipe[1], mini->fd_out);
	// 		close (t_pipe[1]);
	// 	}
	// 	is_cmd(mini, envir, env);
	// }
	// else
	// {
	// 	if (f == 0)
	// 	{
	// 		dup2(std_in, mini->fd_in);
	// 		close(std_in);
	// 	}
	// 	else
	// 	{
	// 		close(t_pipe[1]);
	// 		dup2(t_pipe[0], mini->fd_in);
	// 		close(t_pipe[0]);
	// 	}
	// }	
}

void	ft_execute(t_minishell **head, t_env *envir, char **env)
{
	(void) head;
	(void) envir;
	(void) env;
	t_minishell	*tmp;
	int			old_stdin = 0;

	tmp = *head;
	old_stdin = dup(tmp->fd_in);

	while (tmp->next)
	{
		big_execution(tmp, envir, old_stdin, 1, env);
		tmp = tmp->next;
	}
	if (tmp)
		big_execution(tmp, envir, old_stdin, 0, env);
	while (wait(0) != -1);
}
