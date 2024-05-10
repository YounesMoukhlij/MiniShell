/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:04:52 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/10 18:02:42 by ynassibi         ###   ########.fr       */
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
		current = tmp->next;
		free(tmp);
		tmp = current;
	}
	head = NULL;
}

t_env	*full_fill_print(t_env **env)
{
	return (sortlist(env));
}

void	print_export_helper(t_env *tmp)
{
	int	sum;

	sum = 0x1;
	if (!strcmp_f(tmp->key, "SHLVL", 0x0, 0x0))
	{
		sum = ft_atoi(tmp->value) + 1;
		ft_putstr_fd("=\"", 0x1);
		ft_putstr_fd_executor(ft_itoa(sum), 0x1, 0x0);
		ft_putchar_fd('"', 0x1);
		return ;
	}
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
	// clear_envir(tmp);
}
