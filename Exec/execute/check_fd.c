/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:53:30 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/05 17:24:31 by youmoukh         ###   ########.fr       */
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

char	*hidden_name(char *s)
{
	static int	i;
	char		*s1;
	char		*s2;

	s1 = ft_strjoin_executor(".", ft_itoa(i));
	
	i++;
	s2 = ft_strjoin_executor(s1, s);
	printf("%s\n", s2);
	printf("%i\n", i);
	return (s2);
}
void	heredoc_check(t_minishell *mini, t_env *env, char *delimiter)
{
	char	*s;
	char	*hdd_f;

	(void) env;
	(void) mini;
	hdd_f = hidden_name(delimiter);
	mini->heredoc = open(hdd_f, O_CREAT | O_RDONLY, 0777);
	if (mini->heredoc == -1)
		return ;
	printf("delimiter [%s]\n", delimiter);
	printf("hidden_file [%s]\n", hdd_f);
	while (1999)
	{
		s = readline("heredoc> ");
		if (!s || !ft_strcmp_flag(s, delimiter, 0))
			break;
		free (s);
	}
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
