/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:39:31 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/29 11:26:15 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_put_err(char *input, char *message)
{
	ft_putstr_fd("minishell: ", 0x2);
	if (input)
		ft_putstr_fd(input, 0x2);
	ft_putendl_fd(message, 0x2);
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
		if (s[i] == '+')
			i++;
		if (!ft_isdigit(s[i]))
			return (0x0);
		i++;
	}
	return (0x1);
}

int	is_negative(char *s)
{
	if (s[0x0] == '-' && is_digit(&s[0x1]))
		return (0x1);
	return (0x0);
}

int	help_echo(t_minishell *mini)
{
	if (mini->cmd[0x0] && !mini->cmd[0x1])
	{
		if (mini->size > 1)
			return (ft_putstr_fd_executor("\n", 0x1, 0x0), exit(0x0), 0x1);
		return (ft_putstr_fd_executor("\n", 0x1, 0x0), 0x1);
	}
	mini->cmd = get_echo_splited(mini->cmd, cmd_length(mini), 0x2, 0x0);
	return (0x0);
}
