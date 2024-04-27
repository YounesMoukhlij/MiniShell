/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:53:30 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/25 15:18:09 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	func_err(char *s)
{
	ft_putstr_fd_executor("no such file or directory : ", 2, 0);
	ft_putstr_fd_executor(s, 0x2, 0x1);
}

int	ft_open_others(t_minishell *mini)
{
	int	i;
	int	fd;

	i = -0x1;
	fd = 0x1;
	while (++i < mini->len_tab + 0x1)
	{
		if (mini->tab[i] == 0x1 || mini->tab[i] == 0x2)
		{
			fd = open(mini->files[i + 0x1], O_CREAT | O_RDWR, 0777);
			if (fd == -0x1)
				return (func_err(mini->files[i + 0x1]), 0x1);
		}
	}
	mini->fd_out = fd;
	return (0);
}

char	*hidden_name()
{
	static int	i;
	char		*s1;

	s1 = ft_strjoin_executor(".", ft_itoa(i));
	i++;
	return (s1);
}

int	expanded_content(char *s)
{
	if ((s[0x0] == sgl && s[0x2] == sgl)
		|| (s[0x0] == dbl && s[0x2] == dbl))
		return (0x1);
	return (0x0);
}

void	signal_handler_two(int sig_va)
{
	(void) sig_va;
	// if (sig_va == SIGINT)
	// {
	// 	// puts("aa");
	// 	// FLAG = 1;
	// }
}

// void	sig_herdoc()
// {
// 	signal(SIGINT, signal_handler_two);
// 	signal(SIGQUIT, signal_handler_two);
// }

// int	sig(void)
// {
// 	if (sig)
// 	return (0x0);
// }

int	ft_helper_heredoc(t_minishell *m, char *s)
{
	if (cmd_length(m) == 0x0)
		return (0x0);
	close(m->fd_in);
	m->fd_in = open(s, O_RDWR, 0644);
	if (m->fd_in == -0x1)
		return (0x0);
	unlink (s);
	return (m->fd_in);
}

int	heredoc_check(t_minishell *mini, t_env *env, char *delim, int flag)
{
	char	*s;
	char	*p;
	char	*hdd_f;

	hdd_f = hidden_name();
	mini->fd_in = open(hdd_f, O_CREAT | O_RDWR, 0644);
	if (mini->fd_in == -0x1)
		return (-0x1);
	if (expanded_content(delim))
		flag = 0x1;
	p = without_quotes(delim, 0x0);
		// sig_herdoc();
	// signal(SIGINT, signal_handler_two);
	while (1999)
	{
		s = readline("heredoc> ");
		if (!s || !ft_strcmp_flag(s, p, 0x0, 0x0))
			break;
		if (flag == 0x0)
			s = big_work(env, s, 0x0, 0x1);
		ft_putstr_fd_executor(s, mini->fd_in, 0x1);
		free (s);
	}
	return (ft_helper_heredoc(mini, hdd_f));
}

int	ft_fd_files(t_minishell *mini, t_env *env)
{
	int	i;
	int	fd;

	i = -0x1;
	fd = 0x0;
	while (++i < mini->len_tab + 0x1)
	{
		if (mini->tab[i] == 0x4)
			fd = heredoc_check(mini, env, mini->files[i + 0x1], 0x0);
		if (mini->tab[i] == 0x3)
		{
			fd = open(mini->files[i + 0x1], O_RDONLY);
			if (fd == -0x1)
			{
				func_err(mini->files[i + 0x1]);
				return (0x1);
			}
		}
	}
	if (fd != 0x0)
		mini->fd_in = fd;
	return (0x0);
}

int	check_files(t_minishell *m)
{
	int	i;

	i = 0x0;
	while (i < m->len_tab)
	{
		if (m->files[i + 0x1][0x0] == '$')
		{
			ft_putstr_fd("Minishell: ", 0x2);
			ft_putstr_fd(m->files[i + 0x1], 0x2);
			ft_putendl_fd(": ambiguous redirect", 0x2);
			return (0x1);
		}
		i++;
	}
	return (0x0);
}

int	check_fd(t_minishell *mini, t_env *env)
{
	int	flag;

	flag = 0x1;
	if (check_files(mini))
		return (0x1);
	if (ft_fd_files(mini, env))
		flag = 0;
	ft_open_others(mini);
	if (!flag)
		return (0x1);
	return (0x0);
}
