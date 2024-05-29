/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:50:55 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/29 11:19:02 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_path_before(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!strcmp_f("PATH", tmp->key, 0x0, 0x0))
			return (0x0);
		tmp = tmp->next;
	}
	return (0x1);
}

int	i_b_n(char *s, t_env *envir, t_minishell *m)
{
	if (!ft_strlen(s))
		exit(0x0);
	if (check_path_before(envir))
	{
		if (access(s, F_OK) == 0x0)
		{
			execve(s, cmd(m), execv_env(envir));
		}
	}
	if (env_check(&envir, s))
		exit(ex_st_f(0x0, 0x0));
	return (0x0);
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
		*res = get_cmd_splited(cmd(m), cm_len(m), 0x0, 0x1);
	else
		*res = cmd(m);
}
