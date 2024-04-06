/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:53:30 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/05 23:28:35 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	function_error(char *s)
{
	ft_putstr_fd_executor("no such file or directory : ", 2, 0);
	ft_putstr_fd_executor(s, 2, 1);
	exit(1);
}

int	ft_open_others(t_minishell *mini)
{
	int	i;
	int	fd;

	i = -1;
	fd = 1;
	while (++i < mini->len_tab + 1)
	{
		if (mini->tab[i] == 1 || mini->tab[i] == 2)
		{
			fd = open(mini->files[i + 1], O_CREAT | O_RDWR, 0777);
			if (fd == -1)
			{
				function_error(mini->files[i + 1]);
				return (1);
			}
			// if (i < mini-> len_tab - 1)
			// 	close(fd);
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
void	heredoc_check(t_minishell *mini, t_env *env, char *delimiter)
{
	char	*s;
	char	*hdd_f;

	(void) env;
	hdd_f = hidden_name();
	mini->fd_in = open(hdd_f, O_CREAT | O_RDWR, 0644);
	if (mini->fd_in == -1)
		return ;
	printf("delimiter [%s]\n", delimiter);
	while (1999)
	{
		s = readline("heredoc> ");
		if (!s || !ft_strcmp_flag(s, delimiter, 0, 0))
			break;
		ft_putstr_fd_executor(s, mini->fd_in, 1);
		free (s);
	}
	// unlink (hdd_f);
}

int	ft_fd_files(t_minishell *mini, t_env *env)
{
	int	i;
	int	fd;

	(void) env;
	i = -1;
	fd = 0;
	while (++i < mini->len_tab + 1)
	{
		if (mini->tab[i] == 4)
			heredoc_check(mini, env, mini->files[i + 1]);
		if (mini->tab[i] == 3)
		{
			fd = open(mini->files[i + 1], O_RDONLY);
			if (fd == -1)
			{
				function_error(mini->files[i + 1]);
				return (1);
			}
		}
		// if (i < mini->len_tab - 1)
		// 		close(fd);
	}
	mini->fd_in = fd;
	return (0);
}

void	check_fd(t_minishell *mini, t_env *env)
{
	int	flag;

	flag = 1;
	if (ft_fd_files(mini, env))
		flag = 0;		
	ft_open_others(mini);
	if (!flag)
		return ;
}
