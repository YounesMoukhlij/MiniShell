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
	if (option == 0x1)
		ft_put_err(s, ": bad pattern");
	if (option == 0x2)
		ft_put_err(s, " : not valid in this context");
	ex_st_f(0x1, 0x1);
	if (m->size > 1)
		exit(0x1);
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
		i++;
	}
	if (mini->size > 1)
		exit (0x0);
	return (-0x1);
}
