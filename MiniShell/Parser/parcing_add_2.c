/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_add_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:22:36 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/21 15:06:18 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	lstaddfront(t_minishell **head, t_minishell *node)
{
	node->next = (*head);
	(*head) = node;
}

void	add_back(t_minishell **head, t_minishell *node)
{
	if (!head || !node)
		return ;
	if (*head == NULL)
		lstaddfront(head, node);
	last_cmd(*head)->next = node;
	node->next = NULL;
}

void	add_size(t_minishell *m, int full_size)
{
	t_minishell	*tmp;

	tmp = m;
	while (tmp)
	{
		tmp->size = full_size;
		tmp = tmp->next;
	}
}
