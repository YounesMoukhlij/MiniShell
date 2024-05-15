/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:47:49 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/15 16:09:30 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_node(t_env *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	unset_node(char *s, t_env *envir)
{
	t_env	*tmp;
	t_env	*pre;
	t_env	**head;

	head = &envir;
	tmp = (*head);
	while (tmp)
	{
		if (!strcmp_f(tmp->key, s, 0x0, 0x0))
		{
			pre->next = tmp->next;
			pre = tmp->next;
			// free_node(tmp);
			break ;
		}
		pre = tmp;
		tmp = tmp->next;
	}
}

void	unset_error(t_minishell *m, int option, char *s, char *o)
{
	(void) o;
	ft_putstr_fd("export: ", 0x2);
	if (option == 0x0)
		ft_put_err(s, " : not an identifier");
	if (option == 0x1)
		ft_put_err(s, ": bad pattern");
	if (option == 0x2)
		ft_put_err(s, " : not valid in this context");
	ex_st_f(0x1, 0x1);
	if (m->size > 1)
		exit(0x1);
}

int	check_unset(char *s)
{
	int		i;
	char	*t;
	
	i = 0x0;
	t = ft_substr_executor(s, 0x0, is_eq_exist(s));
	while (t[i])
	{
		if (!ft_isalpha(t[0]))
			return (0x1);
		if (!ft_isalnum(t[i]) && t[i] != '_')
			return (0x1);
		i++;
	}
	return (0x0);
}

int	err_unset(t_minishell *m, char *s)
{
	if (check_unset(s))
		return (unset_error(m, 0, s, 0x0), 0x0);
	return (0x1);
}

int	is_unsetable(t_minishell *m, t_env *envir, char *s)
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

int	ft_unset(t_minishell *mini, t_env *envir)
{
	int	i;

	i = 0x1;
	if (!mini->cmd[0x0])
		return (0x0);
	while (mini->cmd[i])
	{	
		if (check_first(mini->cmd[i]))
			unset_error(mini, 0, mini->cmd[i], 0x0);
		else
			unset_node(mini->cmd[i], envir);
			
		// if (err_unset(mini, mini->cmd[i]))
		i++;
	}
	if (mini->size > 1)
		exit (0x0);
	return (0x1);
}
