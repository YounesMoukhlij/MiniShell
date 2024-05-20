/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:14:53 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/20 17:40:25 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_expanded(t_minishell *mini, char *s)
{
	int	i;

	(void)mini;
	i = 0x0;
	if (no_dollar(s))
		return (0x1);
	while (s[i])
	{
		if (s[i] == '~')
		{
			if (s[i] == DBL && s[i + 0x2] == DBL && s[i + 0x1] == '~'
				&& ft_strlen(s) > 2)
				return (0x0);
		}
		i++;
	}
	return (0x1);
}

void	rmv_sgl_quotes_cmd(t_minishell *mini, char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0x0;
	j = 0x0;
	if (!str)
		return ;
	s = ft_calloc(ft_strlen(str) + 0x1, 0x1);
	if (!s)
		return ;
	while (str[i])
	{
		if (str[i] == SGL)
			i++;
		s[j] = str[i];
		j++;
		i++;
	}
	mini->cmd[0x0] = s;
}

void	check_arg(t_minishell *mini, t_env *env)
{
	char	*s;
	t_env	*tmp;

	s = mini->cmd[0x1];
	if (!s)
		return ;
	if (s[0x0] == '$')
	{
		tmp = env_node(&env, &s[0x1]);
		if (!tmp)
			mini->cmd[0x1] = NULL;
	}
}

char	*no_qts(char *s, int flag, int i, int j)
{
	char	*res;

	if (check_single(s))
		return (do_single(s, 0x0, 0x0));
	if (!s)
		return (ft_strdup(""));
	res = ft_malloc(ft_strlen(s) + 0x1, 0x1);
	if (!res)
		return (NULL);
	while (s[i])
	{
		if (s[i] == DBL && s[i] && flag == 0x0)
			(1) && (flag = 0x1, i++);
		if (s[i] == DBL && flag == 0x1)
			(1) && (i++, flag = 0x0);
		while (s[i] == SGL && flag == 0x0)
			i++;
		if (!s[i])
			break ;
		if (s[i] != DBL && s[i])
			res[j++] = s[i++];
	}
	res[j] = '\0';
	return (res);
}

void	b_g(char *s, int *i, int *c)
{
	while (s[*i] == '$')
	{
		(*i)++;
		(*c)++;
	}
}
