/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:28:10 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/15 16:04:26 by youmoukh         ###   ########.fr       */
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
