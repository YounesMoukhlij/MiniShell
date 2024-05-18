/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:50:34 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/18 15:11:59 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	my_check(t_minishell *mini)
{
	if (!mini->cmd[1] || (mini->cmd[1][0] == '$' && !mini->cmd[1 + 1]))
		return (0x1);
	if (!ft_strlen(mini->cmd[0x1]))
		return (0x0);
	return (0x0);
}

char	*grep_value_export(t_env *envir, char *string)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!strcmp_f(tmp->value, string, 0x0, 0x0))
		{
			return (tmp->key);
		}
		tmp = tmp->next;
	}
	return (ft_strdup_1(""));
}

int	c_d(t_env *env, char *s)
{
	int		i;
	int		len;
	char	*r;
	t_env	*tmp;

	i = 0x0;
	len = 0x0;
	while (s[len] && s[len] != '=')
		len++;
	r = ft_substr_executor(s, 0x0, len);
	tmp = env_node(&env, r);
	if (tmp)
	{
		free (tmp->value);
		tmp->value = ft_strdup_1(&s[++len]);
		return (0x0);
	}
	return (0x1);
}

t_env	*huge_export(t_minishell *m, int flag, t_env *env, int i)
{
	char	**p;
	t_env	*lst;

	lst = 0x0;
	if (check_special_case(m->cmd[i]))
		lst = lstnew_executor(ft_key(m->cmd[i]),
				special_case(m->cmd[i], env), 0);
	else if (no_equal(m->cmd[i]))
		lst = lstnew_executor(ft_strdup_1(m->cmd[i]), NULL, 0);
	else if (if_equal(m->cmd[i]))
	{
		p = ft_split_export(m->cmd[i]);
		check_export(m, p[0x0]);
		if (p[0x1][0] == SGL && p[0x1][ft_strlen(p[0x1]) - 1] == SGL)
			flag = 1;
		lst = lstnew_executor(p[0x0], p[0x1], flag);
	}
	else if (no_value(m->cmd[i]))
		lst = lstnew_executor(ft_strdup_1(m->cmd[i]), ft_strdup_1(""), 0);
	return (lst);
}

int	error_onapaghat(t_minishell *mini)
{
	int	i;

	i = 0x1;
	while (mini->cmd[i])
	{
		if (!err_export_1(mini->cmd[i]))
			return (0x1);
		i++;
	}
	return (0x0);
}

int	ft_export(t_minishell *mini, t_env *env, int i, int flag)
{
	t_env	**head;

	head = &env;
	if (my_check(mini))
		print_export(&env);
	else
	{
		while (mini->cmd[i])
		{
			if (err_export(mini->cmd[i]))
			{
				if (already_exist(mini->cmd[i], env, 0x0, 0x0) && c_d(env, mini->cmd[i]))
						add_back_executor(head, huge_export(mini, flag, env, i));
			}
			i++;
		}
	}
	if (error_onapaghat(mini))
	{
		if (mini->size > 1)
			exit(0x0);
		return (0x0);
	}
	return (0x1);
}
