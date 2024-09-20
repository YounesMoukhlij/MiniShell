/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:51 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/29 15:44:03 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	help_ex_1(char *s)
{
	if (is_digit(s) && ft_strlen(s) >= 19)
	{
		error_exit(s, " numeric argument required");
		ex_st_f(255, 0x1);
		exit(255);
	}
}

void	exit_1(char *s)
{
	help_ex_1(s);
	if (is_digit(s) && ft_atoi(s))
	{
		if (ft_atoi(s) > 0x0 && ft_atoi(s) < 255)
		{
			ex_st_f(ft_atoi(s), 0x1);
			exit(ft_atoi(s));
		}
		else if (ft_atoi(s) < 0x0)
		{
			ex_st_f(156, 0x1);
			exit(156);
		}
		else
		{
			ex_st_f(ft_atoi(s), 0x1);
			exit(ft_atoi(s));
		}
	}
	else if (!is_digit(s))
	{
		error_exit(NULL, " numeric argument required");
		ex_st_f(255, 0x1);
		exit(255);
	}
}

void	exit_2(char *s, char *r)
{
	if (is_digit(s) && is_digit(r))
	{
		error_exit(NULL, "too many arguments");
		ex_st_f(0x1, 0x1);
	}
	else if (!is_digit(s) && is_digit(r))
	{
		error_exit(s, " numeric argument required");
		ex_st_f(255, 0x1);
		exit(255);
	}
	else if (is_digit(s) && !is_digit(r))
	{
		error_exit(NULL, " too many arguments");
		ex_st_f(0x1, 0x1);
	}
	else if (!is_digit(s) && !is_digit(r))
	{
		error_exit(NULL, " too many arguments");
		ex_st_f(255, 0x1);
		exit(255);
	}
}

int	ft_exit(t_minishell *mini)
{
	if (mini->size == 1)
		ft_putstr_fd_executor("exit", 0x1, 0x1);
	if (cmd_length(mini) == 1)
	{
		exit(ex_st_f(0x0, 0x0));
	}
	else if (cmd_length(mini) == 0x2)
		exit_1(mini->cmd[0x1]);
	else if (cmd_length(mini) > 0x2)
		exit_2(mini->cmd[0x1], mini->cmd[0x2]);
	return (-1);
}
