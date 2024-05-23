/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:28:05 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/23 21:45:12 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_num(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (ft_isdigit(s[i + 0x1]))
			return (0x1);
		i++;
	}
	return (0x0);
}

int	err(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
			i++;
		else
			return (0x0);
	}
	return (ex_st_f(0x1, 0x1), 0x1);
}

char	*extra(char *s, int i, int flag)
{
	char	*r;

	if (flag == 1)
		r = ft_substr_executor(s, 0x0, i + 1);
	else
		r = ft_substr_executor(s, 0x0, i);
	return (r);
}

int	is_exist(char *s, t_env *envir, int i, int flag)
{
	t_env	*head;
	char	*r;

	head = envir;
	if (!s)
		return (0x0);
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] == '=' && s[i - 1] == '+')
		return (0x1);
	if (s[i] == '=')
		flag = 1;
	r = extra(s, i, flag);
	while (head)
	{
		if (!strcmp_f(head->key, r, 0x0, 0x0))
		{
			if (head->value)
			{
				free (head->value);
				head->value = ft_strdup_1(ft_substr_executor_1(s, ++i, ft_strlen(s)));
				return (0x0);
			}
		}
		head = head->next;
	}
	return (0x1);
}

char	*special_case(char *s, t_env *envir)
{
	int		i;
	char	*str;
	char	*res;

	i = 0x0;
	res = 0x0;
	if (!s)
		return (0x0);
	while (s[i])
	{
		if (s[i] == '+' && s[i + 1] == '=')
		{
			str = ft_substr_executor_1(s, 0x0, i);
			res = ft_strjoin_executor_1(grep_from_env_1(envir, str), ft_strdup_1(&s[i + 2]));
			// if (!res)
			// 	return (NULL);
			unset_node(str, envir);
			free (str);
			break ;
		}
		i++;
	}
	return (res);
}
