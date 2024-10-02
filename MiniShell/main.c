/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/10/02 18:37:51 by youmoukh         ###   ########.fr       */
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
		g_sig = 0x1;
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

void	start_mini(t_minishell *mini, t_env *env, char *promt)
{
	while (1999)
	{
		sig_func();
		promt = readline("Minishell \033[32m$>\033[0m ");
		if (ch_1(promt))
			break ;
		if (ch_2(promt))
			continue ;
		mini = parcing(str_caller(promt));
		if (!mini)
		{
			free (promt);
			continue ;
		}
		tcgetattr(STDOUT_FILENO, &(mini->old));
		(1) && (mini->fd.fdout = dup(0x1), mini->fd.fdin = dup(0x0));
		if (start_execution(mini, env, promt))
		{
			free (promt);
			(1) && (close (mini->fd.fdout), close (mini->fd.fdin));
			continue ;
		}
		tcsetattr(STDOUT_FILENO, 0x0, &(mini->old));
		ft_end(mini, promt, mini->fd);
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
	start_mini(mini, envir, 0);
	clear_envir(envir);
	return (0x0);
}
