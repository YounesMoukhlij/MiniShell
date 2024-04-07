/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:04:52 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/07 22:13:51 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_swap_nodes(t_export	*tmp)
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

t_export	*copy_list(t_env *head)
{
	t_env	*tmp;
	t_export	*newnode;
	t_export	*copy;

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


t_export	*sortlist(t_env **head)
{
	t_export	*sorted_list;
	t_export	*tmp;
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

// void	clear_envir(t_export *head)
// {
// 	t_export	*tmp;
// 	t_export	*current;

// 	tmp = head;
// 	if (!head)
// 		return ;
// 	while (tmp != NULL)
// 	{
// 		free(tmp->key);
// 		free(tmp->value);
// 		current = tmp->next;
// 		free(tmp);
// 		tmp = current;
// 	}
// }


t_export	*full_fill_print(t_env **env)
{
	t_export	*head;

	head = sortlist(env);
	return (head);
}

void	print_export(t_export **head)
{
	t_export	*tmp;
	// t_export	*sorted_list;

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
	// clear_envir(sorted_list);
}
