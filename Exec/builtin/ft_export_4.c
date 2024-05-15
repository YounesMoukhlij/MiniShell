/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:28:10 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/15 15:11:58 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_arg_ex(t_minishell *m, int i, int j)
{
	while (m->cmd[i])
	{
		j = 0x0;
		while (m->cmd[i][j])
		{
			if (ft_isalnum(m->cmd[i][j]))
				return (0x0);
			j++;
		}
		i++;
	}
	return (0x1);
}

int	err_check(t_minishell *m)
{
	if (m->cmd[0x1] &&
		!strcmp_f("=", m->cmd[0x2], 0x0, 0x0) && m->cmd[0x3])
		return (export_error(m, 0x0, m->cmd[0x1], m->cmd[0x3]), 0x1);
	return (0x0);
}

int	ft_is_equal_1(char *s)
{
	int	i;

	i = 0x0;
	if (!strcmp_f("=", s, 0x0, 0x0))
		return (0x1);
	while (s[i])
	{
		if (ft_strlen(s) > 2)
		{
			if (s[i] == '=' && !ft_isalnum(s[i - 1]) && s[i - 1] != '+')
				return (0x1);
		}
		i++;
	}
	return (0x0);
}

int	before_check(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (s[i] == '=')
			break ;
		i++;
	}
	return (0x0);
}


int	ft_is_equal(char *s)
{
	int	i;

	i = 0x0;
	if (!strcmp_f("=", s, 0x0, 0x0) || before_check(s))
		return (export_error(NULL, 0x0, s, 0x0), 0x1);
	while (s[i])
	{
		if (ft_strlen(s) > 2)
		{
			if (s[i] == '=' && !ft_isalnum(s[i - 1]) && s[i - 1] != '+')
				return (export_error(NULL, 0x0, s, 0x0), 0x1);
		}
		i++;
	}
	return (0x0);
}

int	is_eq_exist(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (s[i] == '=')
			return (i);
		i++;
	}
	return (0);
}
