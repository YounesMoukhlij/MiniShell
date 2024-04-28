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

int	check_path(t_env **env, char *s)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!strcmp_f("PATH", tmp->key, 0x0, 0x0))
			return (0x0);
		tmp = tmp->next;
	}
	ft_putstr_fd(s, 0x2);
	ft_putendl_fd(": no such file or directory", 0x2);
	return (0x1);
}

int	env_check(t_env	**eenv, char *s)
{
	if (!eenv || check_path(eenv, s))
		return (0x1);
	return (0x0);
}

int	check_s(char *s)
{
	if (s[0x0] == '.' && s[0x1] == '/')
		return (0x1);
	return (0x0);
}

int	exve_err(char *s)
{
	struct stat		buf;

	if (stat(s, &buf) == 0)
	{
		if (buf.st_mode & S_IFDIR)
			return (ft_put_err(s, ": Is a directory"), 126);
		else if ((buf.st_mode & S_IXUSR) == 0)
			return (ft_put_err(s, ": Permission denied"), 127);
	}
	else if (check_s(s))
		return (ft_put_err(s, ": No such file or directory"), 127);
	return (ft_put_err(s, ": Command not found"), 127);
}

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


int	is_cmd(t_minishell *mini, t_env *envir)
{
	if (!strcmp_f(mini->cmd[0], "cd", 0, 0))
		return (ft_cd(mini, envir));
	else if (!strcmp_f(mini->cmd[0], "env", 0, 0)
		|| !strcmp_f(mini->cmd[0], "ENV", 0, 0))
		return (ft_env(mini, envir));
	else if (!strcmp_f(mini->cmd[0], "pwd", 0, 0)
		|| !strcmp_f(mini->cmd[0], "PWD", 0, 0 ))
		return (ft_pwd(mini ,&envir));
	else if (!strcmp_f(mini->cmd[0], "export", 0, 0))
		return (ft_export(mini, envir, 0x1));
	else if (!strcmp_f(mini->cmd[0], "exit", 0, 0))
		return (ft_exit(mini), 1);
	else if (!strcmp_f(mini->cmd[0], "unset", 0, 0))
		return (ft_unset(mini, envir));
	else if (!strcmp_f(mini->cmd[0], "echo", 0, 0)
		|| !strcmp_f(mini->cmd[0], "ECHO", 0, 0))
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
	// handle_fd(m);
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


void	ft_execute(t_minishell **head, t_env *envir, char **env)
{
	t_minishell	*tmp;
	(void) env;
	int			old_stdin;
	int			flag;

	old_stdin = 0x0;
	flag = 0x0;
	old_stdin = dup((*head)->fd_in);
	tmp = *head;
	// puts("123");
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
		else if (flag == 11)
			return ;
	}
	// puts("44444");
	while (tmp->next)
	{
		big_execution(tmp, envir, 0x1, old_stdin);
		tmp = tmp->next;
	}
	if (tmp)
		big_execution(tmp, envir, 0x0, old_stdin);
	while (wait(0) != -1);
}
