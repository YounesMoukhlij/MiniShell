/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:08:07 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/08 14:20:55 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	glb_sig = 1;

void	sig_n(int sig_v)
{
	if (sig_v == SIGINT)
		glb_sig = 0;
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
	// signal(SIGINT, SIG_DFL);
	// signal(SIGQUIT, SIG_DFL);
	// rl_catch_signals = 0;
	while (1999)
	{
		// signal(SIGINT, sig_n);
		s = readline("heredoc> ");
		if (!s || !strcmp_f(s, p, 0x0, 0x0) || !glb_sig)
			break ;
		if (flag == 0x0)
			s = big_work(env, s, 0x0, 0x1);
		ft_putstr_fd_executor(s, mini->fd_in, 0x1);
		free(s);
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
				ex_st_f(0x1, 0x1);
				return (0x1);
			}
		}
	}
	if (fd != 0x0)
		mini->fd_in = fd;
	return (0x0);
}

char	*get_str(char *s)
{
	int	i;
	int	count;

	i = 0x0;
	count = 0x0;
	while (s[i])
	{
		if (s[i] == '$')
			count++;
		i++;
	}
	return (&s[count]);
}

int	check_f(char *s)
{
	char	**r;
	int		i;

	i = 0x0;
	if (!s)
		return (0x0);
	r = ft_split_executor(s, ' ');
	while (r[i])
		i++;
	if (i > 0x1)
		return (0x1);
	return (0x0);
}

void	helper_files(char *s)
{
	ft_putstr_fd("Minishell: ", 0x2);
	ft_putstr_fd(s, 0x2);
	ft_putendl_fd(": ambiguous redirect", 0x2);
	ex_st_f(0x1, 0x1);
}

int	check_files(t_minishell *m, t_env *env, int i)
{
	t_env	*tmp;

	if (!m->files)
		return (0x0);
	while (++i < m->len_tab)
	{
		tmp = env_node(&env, get_str(m->files[i + 0x1]));
		if (tmp)
		{
			if (check_f(tmp->value))
			{
				if (m->files[i + 0x1][0x0] == '$')
				{
					helper_files(m->files[i + 0x1]);
					return (0x1);
				}
			}
		}
		else if (!tmp)
		{
			helper_files(m->files[i + 0x1]);
			return (0x1);
		}
	}
	return (0x0);
}

int	already_here(t_env *env, char *s)
{
	t_env	*tmp;

	if (!s)
		return (0x1);
	tmp = env_node(&env, get_str(s));
	if (tmp)
		return (0x0);
	return (0x1);
}
