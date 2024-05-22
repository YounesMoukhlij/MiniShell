/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:25 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/22 16:05:28 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_helper(t_env *tmp)
{
	ft_putstr_fd_executor(tmp->key, 0x1, 0x0);
	ft_putstr_fd("=", 0x1);
	ft_putstr_fd_executor(tmp->value, 0x1, 0x1);
}

int	print_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (lst_size_executor(&tmp) < 6)
	{
		while (tmp)
		{
			if (strcmp_f("PATH", tmp->key, 0x0, 0x0)
				&& strcmp_f("TERM", tmp->key, 0x0, 0x0) && tmp->flag != 5)
				print_helper(tmp);
			tmp = tmp->next;
		}
		return (0x1);
	}
	return (0x0);
}

int	ft_env(t_minishell *mini, t_env *envir)
{
	t_env	*tmp;

	tmp = envir;
	if (!envir)
		return (-1);
	if (print_env(tmp))
		return (0x1);
	while (tmp)
	{
		if (tmp->value != NULL)
		{
			ft_putstr_fd_executor(tmp->key, 0x1, 0x0);
			ft_putstr_fd("=", 0x1);
			ft_putstr_fd_executor(tmp->value, 0x1, 0x1);
		}
		tmp = tmp->next;
	}
	if (mini->size > 1)
		exit (0x0);
	return (0x1);
}
