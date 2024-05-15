/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:47:49 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/14 14:33:00 by youmoukh         ###   ########.fr       */
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
	// if (m)
	// {
		if (m->size > 1)
			exit(0x1);
	// }
}
// void	unset_error(int option, char *s)
// {
// 	printf("unset: ");
// 	if (option == 0x0)
// 		printf("%s: invalid parameter name");
// 	if (option == 0x1)
// 		printf("bad pattern: ");
// 	if (option == 0x2)
// 		printf("not valid in this context: ");
// 	ft_putstr_fd_executor(s, 0x2, 0x1);
// 	ex_st_f(0x1, 0x1);
// }

int	err_unset(char *s)
{
	if (ft_is_equal(s) || is_correct(s))
		return (0x0);
	return (0x1);
}

int	check_unset(char *s, t_env *envir)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=' && ft_isalnum(s[i + 1]))
		{
			printf("unset: %s : invalid parameter name", s);
			return (1);
		}
		if (s[i] == '=')
		{
			i += 2;
			printf("unset: %s : not a valid identifier",
				grep_from_env(envir, &s[i]));
			return (1);
		}
		i++;
	}
	return (0);
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
		if (err_unset(mini->cmd[i]) && is_unsetable(mini, envir, mini->cmd[i]))
			unset_node(mini->cmd[i], envir);
		i++;
	}
	if (mini->size > 1)
		exit (0x0);
	return (0x1);
}
