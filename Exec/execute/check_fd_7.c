/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:58:45 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/19 17:51:54 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	help_1(char **delim, int *flag)
{
	if (expanded_content(*delim))
		*flag = 0x1;
	*delim = without_quotes(*delim, 0x0, 0x0, 0x0);
	if (!strcmp_f(*delim, "$", 0x0, 0x0))
		(*delim)++;
}


// int heredoc_check(t_minishell *mini, t_env *env, char *delim, int flag)
// {
// 	char *hdd_f;
	
// 	hdd_f = hidden_name();
// 	mini->fd_in = open(hdd_f, O_CREAT | O_RDWR | O_APPEND, 0777);
// 	if (mini->fd_in == -1)
// 		return -1;
// 	help_1(&delim, &flag);
// 	signal(SIGINT, sig_n);
// 	while (1)
// 	{
// 		char *s = readline("heredoc> ");
// 		if (!ttyname(0))
// 			return open(ttyname(2), O_RDWR);
// 		if (!s || !strcmp_f(s, delim, 0, 0))
// 			break;
// 		if (flag == 0 && no_dollar(s))
// 			ft_putstr_fd_executor(expand_heredoc(env, s, 0, 0), mini->fd_in, 1);
// 		else
// 			ft_putstr_fd_executor(s, mini->fd_in, 1);
// 		free(s);
// 	}
// 	return ft_helper_heredoc(mini, hdd_f);
// }

void	help_her(char *s, t_env *env, int *fd)
{
	char	*str;
	
	str = expand_heredoc(env, s, 0x0, 0x0);
	ft_putstr_fd_executor(s, *fd, 0x1);
	free (str);
}

int	heredoc_check(t_minishell *mini, t_env *env, char *delim, int flag)
{
	char	*s;
	char	*str;
	char	*hdd_f;

	hdd_f = hidden_name();
	mini->fd_in = open(hdd_f, O_CREAT | O_RDWR | O_APPEND, 0777);
	if (mini->fd_in == -0x1)
		return (-0x1);
	(1) && (help_1(&delim, &flag), signal(SIGINT, sig_n));
	while (1999)
	{
		s = readline("heredoc> ");
		if (!ttyname(0))
			return (open(ttyname(2), O_RDWR), -0x1);
		if (!s || !strcmp_f(s, delim, 0x0, 0x0))
		{
			free(s);
			break;
		}
		if (flag == 0x0 && no_dollar(s))
		{
			puts("1");
			str = expand_heredoc(env, s, 0x0, 0x0);
			ft_putstr_fd_executor(str, mini->fd_in, 0x1);
			free (str);
		}
			// help_her(s, env, &mini->fd_in);
		else
			ft_putstr_fd_executor(s, mini->fd_in, 0x1);
		free (s);
	}
	return (ft_helper_heredoc(mini, hdd_f));
}

int	ft_fd_files(t_minishell *mini, t_env *env)
{
	int	i;
	int	fd;

	(void) env;
	i = -0x1;
	fd = 0x0;
	while (++i < mini->len_tab)
	{
		if (mini->tab[i] == 0x3 || mini->tab[i] < 0)
		{
			fd = open(mini->files[i + 0x1], O_RDONLY);
			if (fd == -0x1)
			{
				ex_st_f(0x1, 0x1);
				func_err(mini->files[i + 0x1]);
				return (0x1);
			}
			// close_fd(mini, &fd, 0x3, i);
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
		tmp = env_node(&env,  get_str(m->files[i + 1]));
		if (tmp)
		{
			if (check_f(tmp->value))
			{
				if (m->files[i + 1][0x0] == '$')
					return (helper_files(m->files[i + 1]), 0x0);
			}
		}
		else if (!tmp)
		{
			if (m->files[i + 1][0x0] == '$')
					return (helper_files(m->files[i + 1]), 0x0);
		}
	}
	return (0x1);
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
