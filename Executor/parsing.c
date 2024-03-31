/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:07:33 by youmoukh          #+#    #+#             */
/*   Updated: 2024/03/30 23:48:42 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_minishell	*return_data(void)
{
	t_minishell	*mini;

	mini = malloc(sizeof(t_minishell));
	if (!mini)
	{
		printf("error malloc\n");
		exit(0);
	}
	mini->cmd = NULL;
	mini->files = NULL;
	mini->fd_in = -1;
	mini->fd_out = -1;
	mini->len_tab = 0;
	mini->tab = NULL;
	mini->envir = NULL;
	mini->next = NULL;
	return (mini);
}
t_minishell	*return_data_1(void)
{
	t_minishell	*mini;

	mini = malloc(sizeof(t_minishell));
	if (!mini)
	{
		printf("error malloc\n");
		exit(0);
	}
	mini->cmd = NULL;
	mini->files = NULL;
	mini->fd_in = -1;
	mini->fd_out = -1;
	mini->len_tab = 0;
	mini->tab = NULL;
	mini->envir = NULL;
	mini->next = NULL;
	return (mini);
}
