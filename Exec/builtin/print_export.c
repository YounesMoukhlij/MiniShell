/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:04:52 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/07 23:35:40 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_swap_nodes(t_env	*tmp)
{
	char	*str;

	if (strcmp(tmp->key, tmp->next->key) > 0)
	{
		str = ft_strdup(tmp->next->key);
		// free(tmp->next->key);
		tmp->next->key = ft_strdup(tmp->key);
		// free(tmp->key);
		tmp->key = str;
		str = ft_strdup(tmp->next->value);
		// free(tmp->next->value);
		tmp->next->value = ft_strdup(tmp->value);
		// free(tmp->value);
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

void	clear_envir(t_env *head)
{
	t_env	*tmp;
	t_env	*current;

	tmp = head;
	if (!head)
		return ;
	while (tmp != NULL)
	{
		free(tmp->key);
		free(tmp->value);
		current = tmp->next;
		free(tmp);
		tmp = current;
	}
}

t_env	*full_fill_print(t_env **env)
{
	return (sortlist(env));
}

void	print_export(t_env **head)
{
	t_env	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp->key, 1);
		if (tmp->value != NULL)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(tmp->value, 1);
			ft_putchar_fd('"', 1);
		}
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
	// clear_envir(tmp);
}
