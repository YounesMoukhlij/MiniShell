/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:44:50 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/21 14:45:16 by ynassibi         ###   ########.fr       */
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
		free (current->path);
		free(current->tab);
		current->len_tab = 0;
		free(current);
		current = temp;
	}
	*node = NULL;
}
