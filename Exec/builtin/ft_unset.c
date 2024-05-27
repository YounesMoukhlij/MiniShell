/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:47:49 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/23 16:08:57 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	unset_node(char *s, t_env *envir)
{
	t_env	*t;
	t_env	*pre;
	t_env	**head;

	head = &envir;
	t = (*head);
	while (t)
	{
		if (!strcmp_f(s, t->key, 0x0, 0x0) && t->flag == -0x1)
			t->flag = 0x5;
		else if (!strcmp_f(t->key, s, 0x0, 0x0)
			&& t->flag != -0x1 && t->flag != 5)
		{
			pre->next = t->next;
			pre = t->next;
			free(t->key);
			free(t->value);
			free(t);
			break ;
		}
		pre = t;
		t = t->next;
	}
}

void	unset_error(t_minishell *m, int option, char *s, char *o)
{
	(void) o;
	ft_putstr_fd("export: ", 0x2);
	if (option == 0x0)
		ft_put_err(s, " : not an identifier");
	ex_st_f(0x1, 0x1);
	if (m->size > 1)
		exit(0x1);
}

int	check_unset(char *s, int i, char *t)
{
	if (s[ft_strlen(s) - 1] == '=' || (s[ft_strlen(s) - 1] == '=' && s[ft_strlen(s) - 2] == '+'))
		return (0x1);
	if (is_eq_exist(s) != 0)
		t = ft_substr_executor(s, 0x0, is_eq_exist(s) + 1);
	else
		t = s;
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

int	ft_unset(t_minishell *mini, t_env *envir)
{
	int	i;

	i = 0x1;
	if (!mini->cmd[0x0])
		return (0x0);
	while (mini->cmd[i])
	{
		if (check_unset(mini->cmd[i], 0, 0))
			unset_error(mini, 0, mini->cmd[i], 0x0);
		else
			unset_node(mini->cmd[i], envir);
		i++;
	}
	if (mini->size > 1)
		exit (0x0);
	return (-0x1);
}
