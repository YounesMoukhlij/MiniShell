/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:28:14 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/29 11:48:58 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_first(char *s)
{
	int		i;
	int		j;
	char	*t;

	j = is_eq_exist(s);
	if (j != 0)
		t = ft_substr_executor(s, 0x0, is_eq_exist(s) + 1);
	else
		t = s;
	i = 0x0;
	while (t[i])
	{
		if (!ft_isalpha(t[0]) && t[0] != '_')
			return (0x1);
		if (!ft_isalnum(t[i]) && t[i] != '_' && t[i] != '=')
		{
			if (t[i + 1] && t[i] == '+' && t[i + 1] == '=')
				return (0x0);
			return (0x1);
		}
		i++;
	}
	return (0x0);
}

int	err_export(char *s)
{
	if (!s)
		return (0x0);
	if (ft_strlen(s) == 0)
		return (export_error(NULL, 0x0, s, 0x0), 0x0);
	if (check_first(s))
		return (export_error(NULL, 0x0, s, 0x0), 0x0);
	return (0x1);
}

int	err_export_1(char *s)
{
	if (!s)
		return (0x0);
	if (ft_strlen(s) == 0)
		return (0x0);
	if (check_first(s))
		return (0x0);
	return (0x1);
}

int	my_check(t_minishell *mini)
{
	if (!ft_strlen(mini->cmd[0x1]))
		return (0x1);
	if (!mini->cmd[1] || (mini->cmd[1][0] == '$' && !mini->cmd[1 + 1]))
		return (0x1);
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
