/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 17:19:29 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_empty(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0x1);
	while (s[i])
	{
		if ((s[i] >= '9' && s[i] <= 13) || s[i] == 32)
			return (0x1);
		i++;
	}
	return (0x0);
}

int	main(int ac, char **av, char **env)
{
	char		*str;
	t_minishell	*mini;

	(void) env;
	(void) av;
	if (ac != 1)
		return (1);
	while (1)
	{
		str = readline("\033[31mಠ__ಠ\033[0m $> ");
		if (is_empty(str))
			continue ;
		mini = parcing(str);
		mini->envir = full_fill_env(env);
    	// full_fill_path(mini);
    	// expander(mini);
    	// check_fd(mini);
    	ft_execute(&mini);
	}
	return (0);
}
