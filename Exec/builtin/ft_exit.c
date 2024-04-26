/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:51 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/25 18:41:04 by youmoukh         ###   ########.fr       */
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

	if (i == 1)
		ft_putstr_fd("exit\n", 2);
	exit(0);
}

void	error_exit(char *input, char *msg)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd("exit: ", 2);
	if (input != NULL)
		ft_putstr_fd(input, 2);
	ft_putendl_fd(msg, 2);
}

int	is_digit(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0x1);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0x0);
		i++;
	}
	return (0x1);
}

int	ft_exit(t_minishell *mini, int size)
{
	if (size == 1)
		puts("exit");
	if (cmd_length(mini) == 1)
	{
		exit_status = 0x0;
		exit(0x0);
	}
	else if (cmd_length(mini) == 2)
	{
		if (is_digit(mini->cmd[0x1]))
		{
			exit_status = ft_atoi(mini->cmd[0x1]);
			exit(ft_atoi(mini->cmd[0x1]));
		}
		else if (!is_digit(mini->cmd[0x1]))
		{
			error_exit(mini->cmd[0x1], " numeric argument required");
			exit_status = 255;
			exit(255);
		}
	}
	else if (cmd_length(mini) == 3)
	{
		if (is_digit(mini->cmd[0x1]) && is_digit(mini->cmd[0x2]))
		{
			error_exit(NULL, " too many arguments");
			exit (0x1);
		}
		else if (!is_digit(mini->cmd[0x1]) && is_digit(mini->cmd[0x2]))
		{
			error_exit(mini->cmd[0x1], " numeric argument required");
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
	return (0x0);
}
