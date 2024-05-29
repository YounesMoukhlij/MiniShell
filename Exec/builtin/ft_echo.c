/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:49:58 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/29 17:30:49 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_newline(char *s)
{
	int	i;
	int	c;

	c = 0;
	i = 1;
	if (!s || !ft_strlen(s))
		return (1);
	if (!strcmp_f(s, "-n", 0, 0))
		return (0);
	if (s[0] == '-')
	{
		while (s[i])
		{
			if (s[i] == 'n')
				c++;
			i++;
		}
		if (c == ft_strlen(s) - 1)
			return (0);
	}
	return (1);
}

int if_else(char **s)
{
	int	i;
	int	j;

	i = 0x0;
	j = 0x0;
	if (check_newline(s[1]) == 0)
		return (0);
	if (!ft_strlen(s[1]) && !check_newline(s[2]))
		return (0);
	while (s[i])
	{
		if (ft_strlen(s[i]) == 0)
			j++;
		i++;
	}
	if (check_newline(s[j + 1]) == 0)
		return (0);
	return (1);
}

int	ft_echo(t_minishell *mini, t_env *env, int i, int f)
{
	(void) f;
	if (help_echo(mini))
		return (0x1);
	while (mini->cmd[i])
	{
		if (check_newline(mini->cmd[i]))
			print_func(env, mini->cmd[i], 0x0, 0x1);
		if (mini->cmd[i + 0x1] && ft_strlen(mini->cmd[i]) != 0
			&& check_newline(mini->cmd[i]))
			write(0x1, " ", 0x1);
		if (!(mini->cmd[i + 0x1]) && if_else(mini->cmd))
			write(0x1, "\n", 0x1);
		i++;
	}
	if (mini->size > 1)
		exit (0x0);
	return (0x1);
}
