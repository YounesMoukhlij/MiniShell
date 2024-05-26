/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:49:58 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/24 15:38:25 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*no_space(char *s, int i, int j, int flag)
{
	char	*r;

	r = ft_calloc(ft_strlen(s) + 1, 0x1);
	if (!r)
		return (r);
	while (s[i])
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
			i++;
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		{
			flag = 1;
			i++;
		}
		if (j > 1 && s[i - 1] == ' ' && ft_isalpha(s[i]) && flag == 1)
		{
			i--;
			flag = 0;
		}
		r[j++] = s[i++];
	}
	return (r);
}

void	print_func(t_env *env, char *s, int i, int j)
{
	t_env	*tmp;
	t_env	*tmp_1;
	char	*t;

	if (!ft_strlen(s))
		return ;
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
		return (s);
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

int	check_1999(char *s)
{
	if (check_again(s))
		return (0x0);
	if (strcmp_f(s, "-n", 0x0, 0x0))
		return (0x1);
	return (0x1);
}

int	help_echo(t_minishell *mini)
{
	if (mini->cmd[0x0] && !mini->cmd[0x1])
	{
		if (mini->size > 1)
			return (ft_putstr_fd_executor("\n", 0x1, 0x0), exit(0x0), 0x1);
		return (ft_putstr_fd_executor("\n", 0x1, 0x0), 0x1);
	}
	mini->cmd = get_echo_splited(mini->cmd, cmd_length(mini), 0x2, 0x0);
	return (0x0);
}

int	check_sf(char **s, t_minishell *m)
{
	int	i;
	int	j;

	i = 0x0;
	j = 0x0;
	while (s[i])
	{
		if (!strcmp_f(s[i], "-n", 0, 0) || check_again(s[i]))
			j++;
		i++;
	}
	if (j == cmd_length(m) - 1)
	{
		if (m->size > 1)
			exit(0x0);
		return (0x1);
	}
	return (0x0);
}


int	check(char *s, int f, int flag_0)
{
	int	j;

	j = 0x0;
	if (f != flag_0)
		return (0x0);
	if (!strcmp_f(s, "-n", 0x0, 0x0))
		return (0x1);
	while (s[j])
	{
		if (!(s[0] == '-' && s[j] == 'n'))
			return (j);
		j++;
	}
	return (0x0);
}

int	ft_echo(t_minishell *mini, t_env *env, int i, int f)
{
	if (help_echo(mini))
		return (0x1);
	// if (check_sf(mini->cmd, mini))
	// 	return (0x1);
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
