/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:00:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/05 23:34:50 by youmoukh         ###   ########.fr       */
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

int	check______(char *s)
{
	if (s[0] == '.' && s[1] == '/')
		return (0x1);
	return (0x0);
}

int	is_bin_cmd(t_minishell *mini, t_env *envir)
{
	int		i;
	int		err;
	char	*s;

	i = 0;
	while (mini->path_d[i])
	{
		s = ft_strjoin_space_executor(mini->path_d[i], mini->cmd[0], '/');
		if (access(s, X_OK) == 0)
		{
			err = execve(s, mini->cmd, execv_env(envir));
			if (err == -1)
				printf("MiniShell: command not found: %s\n", mini->cmd[0]);
		}
		free (s);
		i++;
	}
	return (err);
}


// int	ft_file_check(t_minishell *mini, t_env **head)
// {
// 	struct stat		buf;

// 	if (stat(mini->cmd, &buf) == -1)
// 		return (ft_put_err(mini->cmd, ": No such file or directory", 127));
// 	else if (buf.st_mode & S_IFDIR)
// 		return (ft_put_err(mini->cmd, ": Is a directory", 126));
// 	else if ((buf.st_mode & S_IXUSR) == 0)
// 		return (ft_put_err(mini->cmd, ": Permission denied", 126));
// 	return (ft_exec(mini, head));
// }


int	is_cmd(t_minishell *mini, t_env *envir)
{
	if (!ft_strcmp_flag(mini->cmd[0], "cd", 0, 0))
		return (ft_cd(mini, envir));
	else if (!ft_strcmp_flag(mini->cmd[0], "env", 0, 0) || !ft_strcmp_flag(mini->cmd[0], "ENV", 0, 0))
		return (ft_env(envir));
	else if (!ft_strcmp_flag(mini->cmd[0], "pwd", 0, 0) || !ft_strcmp_flag(mini->cmd[0], "PWD", 0, 0 ))
		return (ft_pwd(mini));
	else if (!ft_strcmp_flag(mini->cmd[0], "export", 0, 0))
		return (ft_export(mini, envir));
	else if (!ft_strcmp_flag(mini->cmd[0], "exit", 0, 0))
		return (ft_exit(mini), 1);
	else if (!ft_strcmp_flag(mini->cmd[0], "unset", 0, 0))
		return (ft_unset(mini, envir));
	else if (!ft_strcmp_flag(mini->cmd[0], "echo", 0, 0) || !ft_strcmp_flag(mini->cmd[0], "ECHO", 0, 0))
		return (ft_echo(mini));
	else
		return (is_bin_cmd(mini, envir));
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

    full_fill_path(mini, envir);
	check_fd(mini, envir);
    expander(&mini, envir);
	// signal(SIGINT, signal_handler_two);
	if (pipe(t_pipe) == -1)
		return ;
		// childs_pipes(t_pipe[0], t_pipe[1], mini, f);
		// parent_pipes(t_pipe[0], t_pipe[1], mini, f);
	if (fork() == 0)
	{
		mini->forked = YES;
		if (f == 1)
		{
			close (t_pipe[0]);
			if (mini->fd_out != 1)
			{
				dup2(mini->fd_out, 1);
				close(mini->fd_out);
			}
			else
				dup2(t_pipe[1], 1);
		}
		else
			dup2(mini->fd_out, 1);
		is_cmd(mini, envir);
	}
	else
	{
		if (f == 0)
		{
				dup2(std_in, 0);
				close(std_in);
		}
		else
		{
			if (mini->fd_in != 0)
				dup2(mini->fd_in, 0);
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

void	ft_execute(t_minishell **head, t_env *envir)
{
	t_minishell	*tmp;
	int			old_stdin = 0;

	tmp = *head;
	old_stdin = dup(tmp->fd_in);
	while (tmp->next)
	{
		big_execution(tmp, envir, old_stdin, 1);
		tmp = tmp->next;
	}
	if (tmp)
		big_execution(tmp, envir, old_stdin, 0);
	while (wait(0) != -1);
}
