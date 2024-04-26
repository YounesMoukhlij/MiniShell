/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:25 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/25 18:04:03 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_env(t_minishell *mini, t_env *envir, int size)
{
	t_env	*tmp;

	(void) mini;
	tmp = envir;
	if (!envir)
		return (-1);
	while (tmp)
	{
		if (tmp->value != NULL)
		{
			ft_putstr_fd_executor(tmp->key, 1, 0);
			ft_putstr_fd("=", 1);
			ft_putstr_fd_executor(tmp->value, 1, 1);
		}
		tmp = tmp->next;
	}
	if (size > 1)
		exit (0x0);
	return (0x1);
}
