/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:16:10 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/18 14:20:08 by youmoukh         ###   ########.fr       */
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
