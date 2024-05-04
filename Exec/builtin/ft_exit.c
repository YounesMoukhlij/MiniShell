/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:51 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/04 15:42:19 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exit_1(char *s)
{
	if (is_digit(s) || is_negative(s))
	{
		if (ft_atoi(s) > 0x0)
		{
			exit_status = ft_atoi(s);
			exit(ft_atoi(s));
		}
		else
		{
			exit_status = 126;
			exit(156);
		}
	}
	else if (!is_digit(s))
	{
		error_exit(s, " numeric argument required");
		exit_status = 255;
		exit(255);
	}
}

void	exit_2(char *s, char *r)
{
	if (is_digit(s) && is_digit(r))
	{
		error_exit(NULL, " too many arguments");
		exit (0x1);
	}
	else if (!is_digit(s) && is_digit(r))
	{
		error_exit(s, " numeric argument required");
		exit_status = 255;
		exit(255);
	}
	else
	{
		error_exit(NULL, " too many arguments");
		exit_status = 0x1;
		exit (0x1);
	}
}

int	ft_exit(t_minishell *mini)
{
	if (mini->size == 1)
		puts("exit");
	if (cmd_length(mini) == 1)
	{
		exit_status = 0x0;
		exit(0x0);
	}
	else if (cmd_length(mini) == 0x2)
		exit_1(mini->cmd[0x1]);
	else if (cmd_length(mini) == 0x3)
		exit_2(mini->cmd[0x1], mini->cmd[0x2]);
	return (0x0);
}
