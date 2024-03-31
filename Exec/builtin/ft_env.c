/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:25 by youmoukh          #+#    #+#             */
/*   Updated: 2024/03/31 18:26:04 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_env(t_env *envir)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		ft_putstr_fd_executor(tmp->key, 1 ,0);
		write(1, "=", 1);
		ft_putstr_fd_executor(tmp->value, 1 ,1);
		tmp = tmp->next;
	}
}
