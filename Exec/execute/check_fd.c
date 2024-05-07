/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:53:30 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/07 18:25:42 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_fd(t_minishell *mini, t_env *env)
{
	int	flag;

	flag = 0x1;
	if (!mini->files[0x1])
		return (0x0);
	if (expand_files(&mini, env, 0x0))
	{
		func_err("file");
		return (0x1);
	}
	if (ft_fd_files(mini, env))
		flag = 0;
	ft_open_others(mini);
	if (!flag)
		return (0x1);
	return (0x0);
}
