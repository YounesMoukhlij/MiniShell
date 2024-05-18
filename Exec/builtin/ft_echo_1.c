/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:55:39 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/18 14:02:16 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

void	print_func(t_env *env, char *s)
{
	int		i;
	int		j;
	t_env	*tmp;
	char	*t;

	i = 0x0;
	j = 0x1;
	t = ft_malloc(ft_strlen(s) + 3, 0x1);
	t[0] = SGL;
	t[ft_strlen(s) + 1] = SGL;
	t[ft_strlen(s) + 2] = '\0';
	while (s[i])
		t[j++] = s[i++];
	tmp = env_node_value(&env, t);
	if (tmp)
	{
		if (tmp->flag == 1)
			ft_putstr_fd_executor(t, 0x1, 0x0);
	}
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
