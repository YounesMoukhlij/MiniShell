/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:53:30 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/10 16:25:24 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	file_first_check(t_minishell *m)
{
	int	i;
	int	fd;

	i = 0x1;
	fd = 0x0;
	while (m->files[i])
	{
		if (m->tab[i - 1] == 0x3)
		{
			fd = open(m->files[i], O_RDONLY);
			if (fd == -0x1)
			{
				// ex_st_f(0x0, 0x1);
				return (func_err(m->files[i]), 0x1);
			}
		}
		i++;
	}
	return (0x0);
}

int	advanced(t_minishell *m)
{
	if (!strcmp_f(m->cmd[0x0], "cat", 0x0, 0x0) && file_first_check(m) == 1 &&
		!strcmp_f(m->next->cmd[0x0], "cat", 0x0, 0x0))
		return (0x1);
	return (0x0);
}

int	check_fd(t_minishell *mini, t_env *env)
{
	int	flag;

	flag = 0x1;
	if (!mini->files[0x1])
		return (0x0);
	if (!check_files(mini, env, -0x1))
		expand_files(&mini, env, 0x0);
	else
		return (0x1);
	// if (advanced(mini))
	// 	return (0x1);
	// if (file_first_check(mini))
	// 	return (0x1);
	if (ft_fd_files(mini, env))
		flag = 0x0;
	if (ft_open_others(mini))
		flag = 0x2;
	if (!flag || flag == 0x2)
		return (0x1);
	return (0x0);
}
