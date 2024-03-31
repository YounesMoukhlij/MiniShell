/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:25 by youmoukh          #+#    #+#             */
/*   Updated: 2024/03/16 16:56:01 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_env(t_minishell *mini)
{
	t_env	*tmp;

	(tmp) = mini->envir;
	while ((tmp))
	{
		ft_putstr_fd_executor((tmp)->key, 1 ,0);
		write(1, "=", 1);
		ft_putstr_fd_executor((tmp)->value, 1 ,1);
		(tmp) = (tmp)->next;
	}
}