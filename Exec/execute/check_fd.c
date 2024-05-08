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

int	check_fd(t_minishell *mini, t_env *env)
{
	int	flag;
	int	check;

	flag = 0x1;
	check = 5;
	if (!mini->files[0x1])
		return (0x0);
	check = check_files(mini, env, -0x1);
	if (!check)
		expand_files(&mini, env, 0x0);
	else
		return (0x1);
	if (ft_fd_files(mini, env))
		flag = 0;
	ft_open_others(mini);
	if (!flag)
		return (0x1);
	return (0x0);
}
