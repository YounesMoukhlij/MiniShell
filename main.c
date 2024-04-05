/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/05 15:51:36 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show()
{
	system("leaks minishell");
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

	(void) av;
	if (ac != 1)
		return (1);
		(void) mini;
	envir = full_fill_env(env);
	// int i;
	// atexit(show);
	while (1)
	{
		str = readline("\033[31mಠ__ಠ\033[0m_$> ");
		if (!str)
			break ;
		if (is_empty(str))
			continue ;
		add_history(str);
		mini = parcing(str);
    	ft_execute(&mini, envir);
		// free (str);
		// ft_free_env(&envir);
		// ft_free_env(envir);
	}
	return (0);
}
