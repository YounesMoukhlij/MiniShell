/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:04:52 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/17 18:01:50 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
		free(tmp);
		current = tmp->next;
		tmp = current;
	}
	head = NULL;
}

void	print_export_helper(t_env *tmp)
{
	ft_putstr_fd("=\"", 0x1);
	ft_putstr_fd(tmp->value, 0x1);
	ft_putchar_fd('"', 0x1);
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
			print_export_helper(tmp);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
}
