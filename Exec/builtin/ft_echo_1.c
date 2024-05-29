/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:43:43 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/29 16:59:00 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_again(char *s)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (s[0] == '-')
	{
		while (i < ft_strlen(s) - 1)
		{
			if (s[i] == 'n')
				j++;
			i++;
		}
		if (j == ft_strlen(s) - 1)
			return (0x1);
	}
	return (0x0);
}

int	check_sf(char **s, t_minishell *m)
{
	int	i;
	int	j;

	i = 0x1;
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

int	check_fs(char **s, t_minishell *m)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if (!strcmp_f(s[i], "-n", 0, 0) || check_again(s[i]))
			i++;
		else
		{
			if (!ft_strlen(s[i]) && cmd_length(m) - 1 == i)
			{
				if (m->size > 1)
					exit(0x0);
				return (0x1);
			}
			break ;
		}
	}
	return (0x0);
}

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
