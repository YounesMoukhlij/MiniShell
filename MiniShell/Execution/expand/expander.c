/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:24:21 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/30 17:33:58 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	extra_1111(t_minishell **mini, int i)
{
	i = 1;
	rmv_sgl_quotes_cmd((*mini),
		no_qts((*mini)->cmd[0x0], 0x0, 0x0, 0x0));
	while ((*mini)->cmd[i])
	{
		if (mini_check_11((*mini)->cmd[i]))
			(*mini)->cmd[i] = ft_rmv_sgl((*mini)->cmd[i], 0, 0, 0);
		i++;
	}
}

void	expand_cmd(t_minishell **mini, t_env *envir, t_env *tmp, int i)
{
	char	*str;

	if (check_expand_1((*mini), (*mini)->cmd[0x0], envir))
		return ;
	while ((*mini)->cmd[i])
	{
		if (is_expanded(*mini, (*mini)->cmd[i]))
		{
			str = big_work(envir, (*mini)->cmd[i], 0x0, 0x0);
			tmp = env_node_value(&envir, str);
			if (tmp)
			{
				if (tmp->flag != 1)
					(*mini)->cmd[i] = no_qts(str, 0x0, 0x0, 0x0);
				if (tmp->flag == 0x1)
				{
					(*mini)->cmd[i] = str;
					return ;
				}
			}
			(*mini)->cmd[i] = no_qts(str, 0x0, 0x0, 0x0);
		}
		i++;
	}
	extra_1111(mini, 0x1);
}

int	before_err(char *s)
{
	struct stat	buf;

	if (stat(s, &buf) == 0)
	{
		if (buf.st_mode & S_IFDIR)
			return (126);
		else if ((buf.st_mode & S_IXUSR) == 0)
			return (127);
	}
	else if (check_s(s))
		return (127);
	else if (!strcmp_f(s, "", 0x0, 0x0))
		return (0x0);
	return (0x0);
}

void	check_cmd_one(t_minishell *mini, t_env *env)
{
	int		i;
	char	**res;

	i = 0x0;
	if (!mini->cmd)
		return ;
	res = mini->cmd;
	if (!strcmp_f(res[0x0], "$", 0x0, 0x0) || !strcmp_f(res[0x0], "$?", 0x0,
			0x0))
	{
		ex_st_f(127, 0x1);
		return ;
	}
	if (mini->cmd[0x0][0x0] == '$' && !env_node(&env, &mini->cmd[0x0][0x1]))
	{
		while (mini->cmd[i])
		{
			mini->cmd[i] = mini->cmd[i + 1];
			i++;
		}
	}
}

void	expander(t_minishell **mini, t_env *envir)
{
	int	flag;

	if (!envir || !(*mini)->cmd || !(*mini)->cmd[0])
		return ;
	check_cmd_one(*mini, envir);
	expand_cmd(mini, envir, 0x0, 0x0);
	flag = before_err((*mini)->cmd[0x0]);
	if (flag != 0x0)
		ex_st_f(flag, 0x1);
}
