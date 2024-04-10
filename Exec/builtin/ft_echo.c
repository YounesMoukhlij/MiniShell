/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:49:58 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/09 01:54:13 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check(t_minishell *mini)
{
	int	i;

	i = 1;
	while (mini->cmd[i])
	{
		if (!ft_strcmp_flag(mini->cmd[i], "-n", 0x0, 0x0))
			return (i);
		i++;
	}
	return (-1);
}

int	big_check(t_minishell *mini)
{
	int	i;
	int	j;
	int	a;

	i = 1;
	j = 1;
	a = ft_check(mini);
	if (a != -1)
		i = a;
	while (mini->cmd[i])
	{
		j = 1;
		while (mini->cmd[i][j])
		{
			if (!(mini->cmd[i][0] == '-' && mini->cmd[i][j] == 'n'))
				return (i);
			j++;
		}
		i++;
	}
	return (0x1);
}

int	check(char *s)
{
	int	j;

	j = 0x0;
	if (!ft_strcmp_flag(s, "-n", 0x0, 0x0))
		return (0x1);
	while (s[j])
	{
		if (!(s[0] == '-' && s[j] == 'n'))
			return (j);
		j++;
	}
	return (0x0);
}

int	ft_echo(t_minishell *mini)
{
	int	i;
	int	flag_0;

	i = 0x1;
	flag_0 = 0x0;
	if (!mini->cmd[0x0])
		return (0x0);
	if (mini->cmd[0x0] && !mini->cmd[0x1])
		return (ft_putstr_fd_executor("\n", 0x1, 0x0), 0x1);
	flag_0 = big_check(mini);
	if (flag_0 != 0x0)
		i = flag_0;
	while (mini->cmd[i])
	{
		if (!check(mini->cmd[i]))
			ft_putstr_fd_executor(mini->cmd[i], 0x1, 0x0);
		if (mini->cmd[i + 0x1] != NULL)
			write(0x1, " ", 0x1);
		if (!(mini->cmd[i + 0x1]) && (flag_0 <= 0x1) && !check(mini->cmd[i]))
			write(0x1, "\n", 0x1);
		i++;
	}
	return (exit(0x0), 0x1);
}
