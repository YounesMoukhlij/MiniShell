/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:58:45 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/20 17:44:46 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_str(char *s)
{
	int	i;
	int	count;

	i = 0x0;
	count = 0x0;
	while (s[i])
	{
		if (s[i] == '$')
			count++;
		i++;
	}
	return (&s[count]);
}

int	check_f(char *s)
{
	char	**r;
	int		i;

	i = 0x0;
	if (!s)
		return (0x0);
	r = ft_split_executor(s, ' ');
	while (r[i])
		i++;
	if (i > 0x1)
		return (0x1);
	return (0x0);
}

void	helper_files(char *s)
{
	ft_putstr_fd("Minishell: ", 0x2);
	ft_putstr_fd(s, 0x2);
	ft_putendl_fd(": ambiguous redirect", 0x2);
	ex_st_f(0x1, 0x1);
}

int	check_files(t_minishell *m, t_env *env, int i)
{
	t_env	*tmp;
	
	if (!m->files)
		return (0x0);
	while (++i < m->len_tab)
	{
		tmp = env_node(&env,  get_str(m->files[i + 1]));
		if (tmp)
		{
			if (check_f(tmp->value))
			{
				if (m->files[i + 1][0x0] == '$')
					return (helper_files(m->files[i + 1]), 0x0);
			}
		}
		else if (!tmp)
		{
			if (m->files[i + 1][0x0] == '$')
					return (helper_files(m->files[i + 1]), 0x0);
		}
	}
	return (0x1);
}

int	already_here(t_env *env, char *s)
{
	t_env	*tmp;

	if (!s)
		return (0x1);
	tmp = env_node(&env, get_str(s));
	if (tmp)
		return (0x0);
	return (0x1);
}
