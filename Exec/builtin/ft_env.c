/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:25 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/07 21:19:15 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_helper(t_env *tmp)
{
	int	sum;

	sum = 0x1;
	if (!strcmp_f(tmp->key, "SHLVL", 0x0, 0x0))
	{
		sum = ft_atoi(tmp->value) + 1;
		ft_putstr_fd_executor(tmp->key, 0x1, 0x0);
		ft_putstr_fd("=", 0x1);
		ft_putstr_fd_executor(ft_itoa(sum), 0x1, 0x1);
		return ;
	}
	ft_putstr_fd_executor(tmp->key, 0x1, 0x0);
	ft_putstr_fd("=", 0x1);
	ft_putstr_fd_executor(tmp->value, 0x1, 0x1);
}

int	print_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (lst_size_executor(&tmp) == 3)
	{
		while (tmp)
		{
			if (strcmp_f("PATH", tmp->key, 0x0, 0x0))
				print_helper(tmp);
			tmp = tmp->next;
		}
		return (0x1);
	}
	return (0x0);
}

void	helper_env(t_env *tmp)
{
	int			sum;
	
	sum = 0x0;
	if (!strcmp_f(tmp->key, "SHLVL", 0x0, 0x0))
	{
		sum = ft_atoi(tmp->value) + 1;
		ft_putstr_fd_executor(tmp->key, 0x1, 0x0);
		ft_putstr_fd("=", 0x1);
		ft_putstr_fd_executor(ft_itoa(sum), 0x1, 0x1);
	}
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
			// if (strcmp_f(tmp->key, "SHLVL", 0x0, 0x0))
			// {
				ft_putstr_fd_executor(tmp->key, 0x1, 0x0);
				ft_putstr_fd("=", 0x1);
				ft_putstr_fd_executor(tmp->value, 0x1, 0x1);
			// }
			// else
			// 	helper_env(tmp);
		}
		tmp = tmp->next;
	}
	if (mini->size > 1)
		exit (0x0);
	return (0x1);
}
