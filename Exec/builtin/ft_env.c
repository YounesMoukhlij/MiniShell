/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:25 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/25 16:28:15 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_env(t_minishell *mini, t_env *envir, int size)
{
	t_env	*tmp;

	(void) mini;
	(void) size;
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
	printf("lst > %d\n", lst_size(&mini));
	printf("size > %d\n", size);
	if (size > 1)
	{
		puts("BIG BIG EXIT\n");
		exit (0x1);
	}
	return (0x1);
}
