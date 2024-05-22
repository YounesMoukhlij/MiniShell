/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/22 17:40:33 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_puterror(int p)
{
	if (p != -1)
	{
		if (p == 0)
			ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `|'",
							2);
		if (p == 1)
			ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `>'",
							2);
		if (p == 3 || p == 5)
			ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `<'",
							2);
		if (p == 6)
			ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `newline'",
							2);
		if (p == 7)
			ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `? '",
							2);
		ex_st_f(258, 0x1);
	}
}

int	is_empty(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0x1);
	if (!s[i])
		return (0x1);
	while (s[i])
	{
		if (!((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
			return (0x0);
		i++;
	}
	return (0x1);
}

char	*display_prompt_msg(t_env *env)
{
	char	*cwd;
	char	*str;
	t_env	*tmp;
	char	buff[4096 + 1];

	cwd = getcwd(buff, 4096);
	if (cwd)
		str = ft_strjoin_executor(cwd, " \033[32m$>\033[0m ");
	else
	{
		tmp = env_node_value(&env, "OLDPWD");
		if (tmp)
			str = ft_strdup(tmp->value);
		else
			str = ft_strdup("-->");
	}
	return (str);
}

void	sig_func(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	rl_catch_signals = 0;
}

t_minishell	*last_node(t_minishell *lst)
{
	t_minishell	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	ex_st_f(int status, int mode)
{
	static int	saved;

	if (mode == 1)
		saved = status;
	return (saved);
}

void	get_fd_back(t_fd fd)
{
	dup2(fd.fdout, 0x1);
	dup2(fd.fdin, 0x0);
}

int	heredock(t_minishell *mini, t_env *env, int i)
{
	t_minishell	*tmp;
	int			fd;

	tmp = mini;
	while (tmp)
	{
		i = -0x1;
		while (++i < tmp->len_tab)
		{
			if (tmp->tab[i] == 0x4)
			{
				fd = heredoc_check(tmp, env, tmp->files[i + 0x1], 0x0);
				if (fd == -0x1)
					return (0x1);
			}
		}
		tmp = tmp->next;
	}
	return (0x0);
}

int	syntax(char *promt)
{
	int	i;

	i = ft_checker(promt);
	add_history(promt);
	ft_puterror(i);
	return (i);
}

void	ft_close_fd(t_minishell *m)
{
	t_minishell	*tmp;

	tmp = m;
	while (tmp)
	{
		if (tmp->fd_in != 0)
			close(tmp->fd_in);
		if (tmp->fd_out != 1)
			close(tmp->fd_out);
		tmp = tmp->next;
	}
}
void	ft_end(t_minishell *m, char *s, t_fd fd)
{
	get_fd_back(fd);
	ft_close_fd(m);
	close(fd.fdin);
	close(fd.fdout);
	free(s);
	ft_malloc(0x0, 0x0);
}

void	clean_1(char *s)
{
	ft_malloc(0x0, 0x0);
	free(s);
}

void	clean_2(char *s, t_minishell *mini)
{
	free(s);
	ft_cleanshell(&mini);
}

int	check_promt(char *promt)
{
	if (!promt)
	{
		clean_1(promt);
		return (0x0);
	}
	if (is_empty(promt) == 1 || syntax(promt) != -0x1)
	{
		free(promt);
		return (0x1);
	}
	return (0x2);
}

int	ch_1(char *promt)
{
	if (!promt)
	{
		ft_malloc(0x0, 0x0);
		free(promt);
		return (0x1);
	}
	return (0x0);
}

int	ch_2(char *promt)
{
	if (is_empty(promt) == 1 || syntax(promt) != -0x1)
	{
		free(promt);
		return (0x1);
	}
	return (0x0);
}

int	start_execution(t_minishell *mini, t_env *envir, char *promt)
{
	if (heredock(mini, envir, -0x1))
		return (0x1);
	if (mini)
	{
		g_sig = 1;
		ft_execute(&mini, envir, 0x0);
		g_sig = 0x0;
	}
	else
	{
		clean_2(promt, mini);
		return (0x1);
	}
	return (0x0);
}

void	start_mini(t_minishell *mini, t_env *envir, char *promt)
{
	t_fd			fd;
	struct termios	old;
	char			*tmp;

	while (1999)
	{
		sig_func();
		tmp = display_prompt_msg(envir);
		promt = readline(tmp);
		if (ch_1(promt))
			break ;
		if (ch_2(promt))
			continue ;
		mini = parcing(str_caller(promt));
		tcgetattr(STDOUT_FILENO, &old);
		(1) && (fd.fdout = dup(0x1), fd.fdin = dup(0x0));
		tcsetattr(STDOUT_FILENO, 0x0, &old);
		if (start_execution(mini, envir, promt))
			continue ;
		ft_end(mini, promt, fd);
	}
}

int	main(int ac, char **av, char **env)
{
	t_minishell	*mini;
	t_env		*envir;

	mini = 0x0;
	if (ac > 0x1 || !strcmp_f(av[0x1], "./minishell", 0x0, 0x0))
		return (0x1);
	g_sig = 0x0;
	envir = full_fill_env(env, 0x0, 0x0);
	start_mini(mini, envir, 0x0);
	clear_envir(envir);
	return (0x0);
}
