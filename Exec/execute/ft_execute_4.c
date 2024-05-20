/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:50:55 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/20 17:51:15 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	i_b_n(char *s, t_env *envir)
{
	if (!ft_strlen(s))
		exit(0x0);
	if (env_check(&envir, s))
		exit(0x1);
}

void	i_b_n_1(int f, char *s)
{
	int	e_s;
	
	e_s = 0;
	if (f == 0x0)
	{
		e_s = ex_st_f(exve_err(s), 0x1);
		exit(e_s);
	}
}

void	i_b_n_2(t_minishell *m, char ***res)
{
	if (!check_cmd(m->cmd[0x0]))
		*res = get_cmd_splited(m->cmd, cmd_length(m), 0x0, 0x1);
	else
		*res = m->cmd;
}
