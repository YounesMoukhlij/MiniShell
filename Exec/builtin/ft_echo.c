/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:49:58 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/08 17:40:17 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check(t_minishell *mini)
{
	int	i;

	i = 1;
	while (mini->cmd[i])
	{
		if (!strcmp_f(mini->cmd[i], "-n", 0x0, 0x0))
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
	if (!ft_strlen(mini->cmd[i]))
		return (0x0);
	while (mini->cmd[i])
	{
		j = 1;
		while (mini->cmd[i][j] || ft_strlen(mini->cmd[i]) == 1)
		{
			if (!(mini->cmd[i][0] == '-' && mini->cmd[i][j] == 'n'))
				return (i);
			j++;
		}
		i++;
	}
	return (0x1);
}

int	check(char *s, int f, int flag_0)
{
	int	j;

	j = 0x0;
	if (f != flag_0)
		return (0x0);
	if (!strcmp_f(s, "-n", 0x0, 0x0))
		return (0x1);
	while (s[j])
	{
		if (!(s[0] == '-' && s[j] == 'n'))
			return (j);
		j++;
	}
	return (0x0);
}

int	ft_echo(t_minishell *mini, int i, int f)
{
	if (!mini->cmd[0x0])
		return (0x0);
	if (mini->cmd[0x0] && !mini->cmd[0x1])
	{
		if (mini->size > 1)
			return (ft_putstr_fd_executor("\n", 0x1, 0x0), exit(0x0), 0x1);
		return (ft_putstr_fd_executor("\n", 0x1, 0x0), 0x1);
	}
	f = big_check(mini);
	if (f != 0x0)
		i = f;
	while (mini->cmd[i])
	{
		if (!check(mini->cmd[i], i, f))
			ft_putstr_fd_executor(mini->cmd[i], 0x1, 0x0);
		if (mini->cmd[i + 0x1] != NULL)
			write(0x1, " ", 0x1);
		if (!(mini->cmd[i + 0x1]) && (f <= 0x1) && !check(mini->cmd[i], i, f))
			write(0x1, "\n", 0x1);
		i++;
	}
	if (mini->size > 1)
		exit (0x0);
	return (0x1);
}
