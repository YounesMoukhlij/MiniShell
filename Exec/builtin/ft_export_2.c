/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:28:05 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/24 16:57:02 by youmoukh         ###   ########.fr       */
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

char	*extra(char *s)
{
	char	*r;

	r = 0x0;
	if (is_eq_exist(s))
	{
		if (s[is_eq_exist(s) - 1] == '+')
			r = ft_substr_executor(s, 0x0, is_eq_exist(s) - 1);
		else
			r = ft_substr_executor(s, 0x0, is_eq_exist(s));
	}
	else if (!is_eq_exist(s))
		r = ft_substr_executor(s, 0x0, ft_strlen(s));
	return (r);
}

int	is_exist(char *s, t_env *envir, char *r)
{
	t_env	*head;

	head = envir;
	if (is_eq_exist(s) == 0x1 && s[is_eq_exist(s) - 1] == '+')
		return (0x1);
	r = extra(s);
	while (head)
	{
		if (!strcmp_f(head->key, r, 0x0, 0x0))
		{
			if (head->value)
			{
				if (is_eq_exist(s) == 0
					|| (is_eq_exist(s) == 0
						&& s[is_eq_exist(s) + 1] == '+'))
					return (0x0);
				free (head->value);
				head->value = ft_substr_executor_1(s,
						is_eq_exist(s) + 1, ft_strlen(s));
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
			res = ft_strjoin_executor_1(grep_from_env_1(envir, str),
					ft_strdup(&s[i + 2]));
			unset_node(str, envir);
			free (str);
			break ;
		}
		i++;
	}
	return (res);
}
