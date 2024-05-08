/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:40:33 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/08 18:47:10 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_swap_nodes(t_env *tmp)
{
	char	*str;

	if (strcmp_f(tmp->key, tmp->next->key, 0x0, 0x0) > 0)
	{
		str = ft_strdup(tmp->next->key);
		free(tmp->next->key);
		tmp->next->key = ft_strdup(tmp->key);
		free(tmp->key);
		tmp->key = str;
		str = ft_strdup(tmp->next->value);
		free(tmp->next->value);
		tmp->next->value = ft_strdup(tmp->value);
		free(tmp->value);
		tmp->value = str;
	}
}

t_env	*copy_list(t_env *head)
{
	t_env	*tmp;
	t_env	*newnode;
	t_env	*copy;

	tmp = head;
	copy = NULL;
	if (head == NULL)
		return (NULL);
	while (tmp != NULL)
	{
		newnode = lstnew_executor(tmp->key, tmp->value);
		add_back_executor(&copy, newnode);
		tmp = tmp->next;
	}
	return (copy);
}

t_env	*sortlist(t_env **head)
{
	t_env	*sorted_list;
	t_env	*tmp;
	int		i;

	sorted_list = copy_list(*head);
	i = lst_size_executor(&sorted_list);
	tmp = sorted_list;
	while (i > 0)
	{
		tmp = sorted_list;
		while (tmp->next != NULL)
		{
			ft_swap_nodes(tmp);
			tmp = tmp->next;
		}
		i--;
	}
	return (sorted_list);
}
