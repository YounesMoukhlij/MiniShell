/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:53:30 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/18 12:35:23 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_here(t_minishell *m)
{
	int	i;

	i = -0x1;
	while (++i < m->len_tab)
	{
		if (m->tab[i] == 0x4)
			return (0x0);
	}
	return (0x1);
}

int	check_files_1(t_minishell *m, t_env *env, int i)
{
	t_env	*tmp;
	
	if (!m->files)
		return (0x0);
	while (++i < m->len_tab)
	{
		tmp = env_node(&env,  get_str(m->files[i + 1]));
		if (tmp)
		{
			if (check_f(tmp->value))
			{
				if (m->files[i + 1][0x0] == '$')
					return (0x0);
			}
		}
		else if (!tmp)
		{
			if (m->files[i + 1][0x0] == '$')
				return (0x0);
		}
	}
	return (0x1);
}

int	check_fd(t_minishell *mini, t_env *env)
{
	int	flag;
	// int	l;

	flag = 0x1;
	// l = 0;
	if (!mini->files[0x1])
		return (0x0);
	// if (check_here(mini) == 0)
	// 	l = 1;
	// if (l == 0)
	// {
	// 	printf("2");
	// 	if (check_files(mini, env, -0x1))
	// 	{
	// 		printf("3333");
			expand_files(&mini, env, 0x0);
	// 	}
	// 	if (!check_files_1(mini, env, -0x1))
	// 		return (0x1);
	// }
	if (ft_fd_files(mini))
		flag = 0x0;
	if (ft_open_others(mini))
		flag = 0x2;
	if (!flag || flag == 0x2)
		return (0x1);
	return (0x0);
}
