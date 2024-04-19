/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/18 14:46:27 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show()
{
	system("leaks minishell");
}

void	ft_puterror(int p)
{
	if (p == 0)
		ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `|'", 2);
	if (p == 1)
		ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `>'", 2);
	if (p == 3 || p == 5)
		ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `<'", 2);
	if (p == 6)
		ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `newline'", 2);
	if (p == 7)
		ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `? '", 2);
}

int	is_empty(char *s)
{
	int	i;

	i = 0;
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

void	display_prompt_msg(void)
{
	char	*cwd;
	char	buff[4096 + 1];

	cwd = getcwd(buff, 4096);
	ft_putstr_fd_executor(cwd, 1, 0);
	ft_putstr_fd_executor(" \033[32m$>\033[0m", 1, 0);
}

int	main(int ac, char **av, char **env)
{
	char		*str;
	t_minishell	*mini;
	t_env		*envir;
	int		p;

	(void) av;
	if (ac != 1)
		return (1);
		(void) mini;
	envir = full_fill_env(env);
	exit_status = 0;
	// int i;
	// atexit(show);
	signal(SIGINT, signal_handler_one);
	// signal(SIGQUIT, signal_handler_one);
	while (1)
	{
		display_prompt_msg();
		str = readline(" ");
		if (!str)
			break ;
		if (is_empty(str))
			continue ;
		p = ft_checker(str);
		add_history(str);
		ft_puterror(p);
		if (p != -1)
		{
			free(str);
			continue;
		}
		mini = parcing(str);
    	ft_execute(&mini, envir);
		free (str);
		// printf("exit____>[%d]\n\n", exit_status);
		// ft_free_env(&envir);
	}
	// ft_cleanshell(&mini);
	// clear_envir(envir);
	return (0);
}
