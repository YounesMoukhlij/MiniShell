/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:50:34 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/24 16:56:30 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	c_d(t_env *env, char *s)
{
	char	*r;
	t_env	*tmp;

	if (!s)
		return (0x0);
	r = ft_substr_executor(s, 0x0, is_eq_exist(s));
	tmp = env_node(&env, r);
	if (tmp)
	{
		if (tmp->value)
		{
			free(tmp->value);
			tmp->value = ft_substr_executor_1(s, is_eq_exist(s) + 1,
					ft_strlen(s));
			return (0x0);
		}
	}
	return (0x1);
}

char	*full(char *s)
{
	if (!s)
		return (ft_strdup_1(""));
	return (s);
}

void	check_final(char *s, t_env *env, t_env *tmp)
{
	static int i = 0;

	tmp = env;
	while (tmp)
	{
		if (!strcmp_f(s, tmp->key, 0, 0))
			i++;
		tmp = tmp->next;
	}
	tmp = env;
	if (i > 1)
	{
		while (tmp)
		{
			if (!strcmp_f(s, tmp->key, 0, 0))
			{
				if (!tmp->value)
				{
					unset_node(s, env);
					break ;
				}
			}
			tmp = tmp->next;
		}
	}
}
t_env	*huge_export(t_minishell *m, int flag, t_env *env, int i)
{
	char	*p;
	char	*s;
	t_env	*lst;

	lst = 0x0;
	if (check_special_case(m->cmd[i]))
		lst = lstnew_executor(ft_key(m->cmd[i]),
				special_case(m->cmd[i], env), 0);
	else if (no_equal(m->cmd[i]))
		lst = lstnew_executor(ft_strdup_1(m->cmd[i]), NULL, 0);
	else if (if_equal(m->cmd[i]))
	{
		s = ft_substr_executor_1(m->cmd[i], 0, is_eq_exist(m->cmd[i]));
		p = ft_substr_executor_1(m->cmd[i],
				is_eq_exist(m->cmd[i]) + 1,
				ft_strlen(m->cmd[i]));
		check_export(m, s);
		if (p[0] == SGL && p[ft_strlen(p) - 1] == SGL)
			flag = 1;
		lst = lstnew_executor(s, full(p), flag);
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
		{
			ex_st_f(0x1, 0x1);
			return (0x1);
		}
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
				if (is_exist(mini->cmd[i], env, 0x0))
				{
					if (c_d(env, mini->cmd[i]))
						add_back_executor(head,
							huge_export(mini, flag, env, i));
					check_final(ft_key(mini->cmd[i]), env, 0x0);
				}
			}
			i++;
		}
	}
	error_onapaghat(mini);
	if (mini->size > 1)
		exit(0x0);
	return (-0x1);
}
