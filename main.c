/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/23 20:25:42 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ch_1(char *promt)
{
	if (!promt || !isatty(0))
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
		ft_execute(&mini, envir, 0x0, 0x0);
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

	while (1999)
	{
		sig_func();
		promt = readline("Minishell \033[32m$>\033[0m ");
		if (ch_1(promt))
			break ;
		if (ch_2(promt))
			continue ;
		mini = parcing(str_caller(promt));
		tcgetattr(STDOUT_FILENO, &old);
		(1) && (fd.fdout = dup(0x1), fd.fdin = dup(0x0));
		tcsetattr(STDOUT_FILENO, 0x0, &old);
		if (start_execution(mini, envir, promt))
		{
			(1) && (close (fd.fdout), close (fd.fdin));
			continue ;
		}
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
