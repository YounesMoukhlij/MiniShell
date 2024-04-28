/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:37:25 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/23 11:53:32 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*lstnew_executor(char *key, char *value)
{
	t_env	*lst;

	lst = malloc(sizeof(t_env));
	if (!lst)
		return (NULL);
	lst->key = key;
	lst->value = value;
	lst->next = NULL;
	return (lst);
}

int	lst_size_executor(t_env **head)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = *head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_env	*last_node_executor(t_env *lst)
{
	t_env	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	add_front_executor(t_env **head, t_env *node)
{
	node->next = (*head);
	(*head) = node;
}

void	add_back_executor(t_env **head, t_env *node)
{
	if (!head || !node)
		return ;
	if (*head == NULL)
		add_front_executor(head, node);
	if (last_node_executor(*head))
		last_node_executor(*head)->next = node;
	node->next = NULL;
}
