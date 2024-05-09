/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:53:30 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/08 22:19:13 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	file_first_check(t_minishell *m)
{
	int	i;
	int	fd;

	i = -0x1;
	fd = 0x0;
	while (++i < m->len_tab + 0x1)
	{
		if (m->tab[i] == 0x3)
		{
			fd = open(m->files[i + 0x1], O_RDONLY);
			if (fd == -0x1)
			{
				ex_st_f(0x1, 0x1);
				return (func_err(m->files[i + 0x1]), 0x1);
			}
		}
	}
	return (0x0);
}

int	advanced(t_minishell *mini)
{
	int	i;
	int	fd;

	i = -0x1;
	fd = 0x0;
	if (!strcmp_f(mini->cmd[0x0], "echo", 0x0, 0x0) && mini->cmd[0x1])
	{
		while (++i < mini->len_tab + 0x1)
		{
			if (mini->tab[i] == 0x3)
			{
				fd = open(mini->files[i + 0x1], O_RDONLY);
				if (fd == -0x1)
					return (0x1);
			}
		}
	}
	return (0x0);
}

int	check_fd(t_minishell *mini, t_env *env)
{
	int	flag;
	// int	check;

	flag = 0x1;
	// check = 5;
	if (!mini->files[0x1])
		return (0x0);
	// check = check_files(mini, env, -0x1);
	// if (!check)
	// 	expand_files(&mini, env, 0x0);
	// else
	// 	return (0x1);
	if (advanced(mini))
		return (0x0);
	if (file_first_check(mini))
		return (0x1);
	if (ft_fd_files(mini, env))
		flag = 0x0;
	if (ft_open_others(mini))
		flag = 0x2;
	if (!flag || flag == 0x2)
		return (0x1);
	return (0x0);
}
