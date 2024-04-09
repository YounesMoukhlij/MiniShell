/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/09 16:49:32 by youmoukh         ###   ########.fr       */
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
		ft_putendl_fd("\033[31m ಠ__ಠ!\033[0m: syntax error near unexpected token `|'", 2);
	if (p == 1)
		ft_putendl_fd("\033[31m ಠ__ಠ!\033[0m: syntax error near unexpected token `>'", 2);
	if (p == 3 || p == 5)
		ft_putendl_fd("\033[31m ಠ__ಠ!\033[0m: syntax error near unexpected token `<'", 2);
	if (p == 6)
		ft_putendl_fd("\033[31m ಠ__ಠ!\033[0m: syntax error near unexpected token `newline'", 2);
	if (p == 7)
		ft_putendl_fd("\033[31m ಠ__ಠ!\033[0m: syntax error near unexpected token `? '", 2);
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
	// int i;
	// atexit(show);
	signal(SIGINT, signal_handler_one);
	// signal(SIGQUIT, signal_handler_one);
	while (1)
	{
		str = readline("\033[1;32m ಠ__ಠ $\033[0m> ");
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
		usleep(100);
		free (str);
		// ft_free_env(&envir);
	}
	ft_cleanshell(&mini);
	// clear_envir(envir);
	return (0);
}
