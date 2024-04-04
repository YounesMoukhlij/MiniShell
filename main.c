/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/04 00:39:33 by youmoukh         ###   ########.fr       */
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
	t_minishell	*mini;
	t_env		*envir;

	(void) av;
	if (ac != 1)
		return (1);
		(void) mini;
	envir = full_fill_env(env);
	// int i;
	while (1)
	{
		str = readline("\033[31mಠ__ಠ\033[0m_$> ");
		if (!str)
			break ;
		if (is_empty(str))
			continue ;
		add_history(str);
		mini = parcing(str);
		// while (mini)
		// // {
		// 	i = 0;
		// 	puts("__________________________\n");
		// 	while (mini->cmd[i])
		// 	{
		// 		printf("------>[%s]\n", mini->cmd[i]);
		// 		i++;
		// 	}
		// 	puts("__________________________\n");
		// 	mini = mini->next;
		// }
    	// expander(&mini, envir);
    	ft_execute(&mini, envir, env);
	}
	return (0);
}
