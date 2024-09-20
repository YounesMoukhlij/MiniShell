/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_coll_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:48:25 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/22 12:48:27 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_delete	*lstnew_garbage(void *str)
{
	t_delete	*lst;

	lst = malloc(sizeof(t_delete));
	if (!lst)
		return (NULL);
	lst->ptr = str;
	lst->next = NULL;
	return (lst);
}

t_delete	*last_cmd_garbage(t_delete *lst)
{
	t_delete	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	lstaddfront_garbage(t_delete **head, t_delete *node)
{
	node->next = (*head);
	(*head) = node;
}
