/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:53:30 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/02 01:04:34 by youmoukh         ###   ########.fr       */
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
	while (++i < mini->len_tab)
	{
		if (mini->tab[i] == 1 || mini->tab[i] == 2)
		{
			fd = open(mini->files[i], O_CREAT | O_RDWR, 0777);
			if (fd == -1)
			{
				function_error(mini->files[i]);
				return (1);
			}	
		}
	}
	mini->fd_out = fd;
	return (0);
}

int	ft_fd_files(t_minishell *mini)
{
	int	i;
	int	fd;

	i = -1;
	while (++i < mini->len_tab)
	{
		if (mini->tab[i] == 3)
		{
			fd = open(mini->files[i], O_RDONLY);
			if (fd == -1)
			{
				function_error(mini->files[i]);
				return (1);
			}
		}
	}
	mini->fd_in = fd;
	return (0);
}

void	heredoc_check(t_minishell *mini, t_env *env)
{
	(void) mini;
	(void) env;
}

void	check_fd(t_minishell *mini, t_env *env)
{
	int	flag;

	flag = 1;
	heredoc_check(mini, env);
	if (ft_fd_files(mini))
		flag = 0;		
	ft_open_others(mini);
	if (!flag)
		return ;
}
