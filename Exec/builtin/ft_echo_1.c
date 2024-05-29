/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:43:43 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/29 11:23:55 by youmoukh         ###   ########.fr       */
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
	a = ft_check(mini);
	if (a != -1)
		i = a;
	if (!ft_strlen(mini->cmd[i]))
		return (0x0);
	while (mini->cmd[i] && ft_strlen(mini->cmd[i]))
	{
		j = 1;
		while (mini->cmd[i][j] && ft_strlen(mini->cmd[i]) > 1)
		{
			if (!(mini->cmd[i][0] == '-' && mini->cmd[i][j] == 'n'))
				return (i);
			j++;
		}
		i++;
	}
	return (0x1);
}

int	check_again(char *s)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (s[0] == '-')
	{
		while (i < ft_strlen(s) - 1)
		{
			if (s[i] == 'n')
				j++;
			i++;
		}
		if (j == ft_strlen(s) - 1)
			return (0x1);
	}
	return (0x0);
}

int	check_sf(char **s, t_minishell *m)
{
	int	i;
	int	j;

	i = 0x1;
	j = 0x0;
	while (s[i])
	{
		if (!strcmp_f(s[i], "-n", 0, 0) || check_again(s[i]))
			j++;
		i++;
	}
	if (j == cmd_length(m) - 1)
	{
		if (m->size > 1)
			exit(0x0);
		return (0x1);
	}
	return (0x0);
}

int	check_fs(char **s, t_minishell *m)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if (!strcmp_f(s[i], "-n", 0, 0) || check_again(s[i]))
			i++;
		else
		{
			if (!ft_strlen(s[i]) && cmd_length(m) - 1 == i)
			{
				if (m->size > 1)
					exit(0x0);
				return (0x1);
			}
			break ;
		}
	}
	return (0x0);
}
