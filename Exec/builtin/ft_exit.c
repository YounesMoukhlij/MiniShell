/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:51 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/07 17:13:29 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_put_err(char *input, char *message)
{
	ft_putstr_fd("minishell: ", 2);
	if (input != NULL)
		ft_putstr_fd(input, 2);
	ft_putendl_fd(message, 2);
}

void	ft_close(t_minishell *mini, t_env *head, int i)
{
	(void) head;
	(void) mini;
	// ft_free_strings(mini->cmd);
	// clear_envir(head);

	if (i == 1)
		ft_putstr_fd("exit\n", 2);
	exit(0);
}

int	ft_exit(t_minishell *mini, t_env *head)
{
	(void) mini;
	(void) head;
	exit(0);
// 	if (!mini->cmd[0x1])
// 		ft_close(mini, head, 1);
// 	while (mini->cmd[i])
// 		i++;
// 	if (i > 2)
// 		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
// 	return (ft_close(mini, head, 1), 0x0);
}
