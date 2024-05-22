/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:49:58 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/22 19:12:30 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_func(t_env *env, char *s, int i, int j)
{
	t_env	*tmp;
	t_env	*tmp_1;
	char	*t;

	t = ft_malloc(ft_strlen(s) + 3, 0x1);
	t[0] = SGL;
	t[ft_strlen(s) + 1] = SGL;
	t[ft_strlen(s) + 2] = '\0';
	while (s[i])
		t[j++] = s[i++];
	tmp = env_node_value(&env, t);
	tmp_1 = env_node_value(&env, s);
	if (tmp)
	{
		if (tmp->flag == 1)
			ft_putstr_fd_executor(t, 0x1, 0x0);
	}
	if (tmp_1 && tmp_1->flag == 0x5)
		ft_putstr_fd_executor("", 0x1, 0x0);
	else
		ft_putstr_fd_executor(s, 0x1, 0x0);
}

int	check_n(char *s)
{
	int	j;

	j = 0x0;
	while (s[j])
	{
		if (s[0] == '-' && s[j] == 'n')
		{
			if (s[j + 1] == ' ')
				return (1);
		}
		j++;
	}
	return (0x0);
}

char	**get_echo_splited(char **s, int len, int p, int j)
{
	char	**r;
	char	**res;
	int		l_n;

	if (!check_n(s[1]))
	{
		res = s;
		return (res);
	}
	r = ft_split_executor(s[0x1], ' ');
	l_n = get_double_arr_len(r);
	res = ft_malloc(sizeof(char *) * (l_n + len + 1), 0x1);
	if (!res)
		return (NULL);
	res[0] = ft_strdup(s[0]);
	while (j < l_n + 1)
	{
		res[j + 1] = ft_strdup(r[j]);
		j++;
	}
	while (j < l_n + len)
		res[j++] = ft_strdup(s[p++]);
	res[j] = 0;
	return (res);
}

int	ft_echo(t_minishell *mini, t_env *env, int i, int f)
{
	if (mini->cmd[0x0] && !mini->cmd[0x1])
	{
		if (mini->size > 1)
			return (ft_putstr_fd_executor("\n", 0x1, 0x0), exit(0x0), 0x1);
		return (ft_putstr_fd_executor("\n", 0x1, 0x0), 0x1);
	}
	mini->cmd = get_echo_splited(mini->cmd, cmd_length(mini), 0x2, 0x0);
	f = big_check(mini);
	if (f != 0x0)
		i = f;
	while (mini->cmd[i])
	{
		if (!check(mini->cmd[i], i, f))
			print_func(env, mini->cmd[i], 0x0, 0x1);
		if (mini->cmd[i + 0x1] != NULL)
			write(0x1, " ", 0x1);
		if (!(mini->cmd[i + 0x1]) && (f <= 0x1) && !check(mini->cmd[i], i, f))
			write(0x1, "\n", 0x1);
		i++;
	}
	if (mini->size > 1)
		exit (0x0);
	return (0x1);
}
