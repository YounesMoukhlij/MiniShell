/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:19:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/10 18:19:05 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cleanshell(t_minishell **node)
{
	t_minishell	*temp;
	t_minishell	*current;

	current = *node;
	while (current)
	{
		temp = current->next;
		ft_cleantach(current->cmdt);
		ft_cleantach(current->afcmd_t);
		ft_cleantach(current->files);
		ft_cleantach(current->cmd);
		// printf("[%p]\n",current->path_d);
		// printf("path_[%p]",current->path);
		ft_cleantach(current->path_d);
		// free (current->path);
		free(current->tab);
		current->len_tab = 0;
		free(current);
		current = temp;
	}
	*node = NULL;
}
