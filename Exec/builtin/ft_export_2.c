/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:28:05 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/12 17:34:42 by youmoukh         ###   ########.fr       */
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

int	is_exportable(t_minishell *m, char *s, t_env *envir)
{
	int	i;

	i = 0x0;
	if (ft_isdigit(s[0x0]))
		return (export_error(m, 0x0, s, 0x0), 0x0);
	while (s[i])
	{
		if (s[0x0] && s[0x1] == ' ')
			return (0x1);
		if (s[i] == '+' && s[i + 1] == '=')
			return (0x1);
		if (s[i] == '=' && s[i + 0x1] == ' ' && is_num(&s[i + 0x2]))
			return (0x0);
		if (s[i] == '=')
			return (0x1);
		i++;
	}
	if (!strcmp_f(grep_from_env(envir, s), ft_strdup("(null)"), 0x0, 0x0))
		return (0x0);
	return (0x1);
}

int	is_exportable_1(t_minishell *m, char *s, t_env *envir)
{
	int	i;

	i = 0x0;
	(void)m;
	if (ft_isdigit(s[0x0]))
		return (0x0);
	while (s[i])
	{
		if (s[0x0] && s[0x1] == ' ')
			return (0x1);
		if (s[i] == '+' && s[i + 1] == '=')
			return (0x1);
		if (s[i] == '=' && s[i + 0x1] == ' ' && is_num(&s[i + 0x2]))
			return (0x0);
		if (s[i] == '=')
			return (0x1);
		i++;
	}
	if (!strcmp_f(grep_from_env(envir, s), "(null)", 0x0, 0x0))
		return (0x0);
	return (0x1);
}

int	already_exist(char *s, t_env *envir)
{
	t_env	*head;
	int		i;

	i = 0x0;
	head = envir;
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] == '=' && s[i - 1] == '+')
		return (0x0);
	while (head)
	{
		if (!strcmp_f(head->key, ft_substr_executor(s, 0x0, i), 0x0, 0x0))
		{
			head->value = &s[++i];
			return (0x1);
		}
		head = head->next;
	}
	return (0x0);
}

char	*special_case(char *s, t_env *envir)
{
	int		i;
	char	*str;
	char	*you;

	i = 0x0;
	you = NULL;
	while (s[i])
	{
		if (s[i] == '+' && s[i + 1] == '=')
		{
			str = ft_substr_executor(s, 0x0, i);
			you = ft_strjoin_executor(grep_from_env(envir, str), &s[i + 2]);
			unset_node(str, envir);
			break ;
		}
		i++;
	}
	return (you);
}
