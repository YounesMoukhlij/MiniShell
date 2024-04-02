/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:53:30 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/02 14:14:59 by youmoukh         ###   ########.fr       */
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
	while (++i < mini->len_tab + 1)
	{
		if (mini->tab[i] == 1 || mini->tab[i] == 2)
		{
			puts("ABC\n");
			fd = open(mini->files[i + 1], O_CREAT | O_RDWR, 0777);
			if (fd == -1)
			{
				function_error(mini->files[i + 1]);
				return (1);
			}	
		}
	}
	if (fd != -1)
		mini->fd_out = fd;
	return (0);
}

void	heredoc_check(t_minishell *mini, t_env *env, char *delimiter)
{
	char	*s;

	(void) mini;
	(void) env;
	while (1999)
	{
		s = readline("heredoc> ");
		if (!s)
			break;
		if (!ft_strcmp_flag(s, delimiter, 0))
			break;
	}
}

int	ft_fd_files(t_minishell *mini, t_env *env)
{
	int	i;
	int	fd;

	(void) env;
	i = -1;
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
	}
	if (fd != -1)
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
