/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:51 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/17 10:22:12 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exit_1(char *s)
{
	if (is_digit(s) || is_negative(s) || ft_atoi(s))
	{
		if (ft_atoi(s) > 0x0 && ft_atoi(s) < 255)
		{
			ex_st_f(ft_atoi(s), 0x1);
			exit(ft_atoi(s));
		}
		else if (ft_atoi(s) < 0x0 )
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
		error_exit(NULL , " numeric argument required");
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
		puts("exit");
	if (cmd_length(mini) == 1)
	{
		ex_st_f(0x0, 0x1);
		exit(0x0);
	}
	else if (cmd_length(mini) == 0x2)
		exit_1(mini->cmd[0x1]);
	else if (cmd_length(mini) == 0x3)
		exit_2(mini->cmd[0x1], mini->cmd[0x2]);
	return (-1);
}
