/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/02 03:04:53 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	t_minishell	*mini = NULL;
	t_env		*envir;

	(void) env;
	(void) av;
	if (ac != 1)
		return (1);
	envir = full_fill_env(env);
	while (1)
	{
		str = readline("\033[31mಠ__ಠ\033[0m_$> ");
		if (!str)
			break ;
		if (is_empty(str))
			continue ;
		// if (parcing(str) == NULL)
		// 	continue ;
		add_history(str);
		mini = parcing(str);
		// int i =0;
		// ft_env(mini);
		// ft_env(mini);
		// while (mini)
		// {
		// 	i = 0;
		// 	while (mini->cmd[i])
		// 	{
		// 		printf("%s\n", mini->cmd[i]);
		// 		i++;
		// 	}
		// 	mini = mini->next;
		// }
    	full_fill_path(mini, envir);
    	expander(&mini, envir);
    	check_fd(mini, envir);
    	ft_execute(&mini, envir, env);
	}
	return (0);
}
