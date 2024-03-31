/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:49:58 by youmoukh          #+#    #+#             */
/*   Updated: 2024/03/30 18:21:48 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check(t_minishell *mini)
{
	int	i;

	i = 1;
	while (mini->cmd[i])
	{
		if (!ft_strcmp_flag(mini->cmd[i], "-n", 0))
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
	return (0);
}

void	ft_echo(t_minishell *mini)
{
	int	flag_0;
	int	i;

	i = 1;
	flag_0 = 0;
	if (mini->cmd[0] && !mini->cmd[1])
	{
		write(1, "\n", 1);
		return ;
	}
	flag_0 = big_check(mini);
	if (flag_0 != 0)
		i = flag_0;
	while (mini->cmd[i])
	{
		ft_putstr_fd_executor(mini->cmd[i], 1, 0);
		if (mini->cmd[i + 1] != NULL)
			write(1, " ", 1);
		if (!(mini->cmd[i + 1]) && (flag_0 <= 1))
			write(1, "\n", 1);
		i++;
	}
}
