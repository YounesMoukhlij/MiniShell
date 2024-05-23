/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:24:31 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/23 19:51:43 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*env_node_value(t_env **envi, char *value)
{
	t_env	*tmp;

	tmp = (*envi);
	while (tmp)
	{
		if (!strcmp_f(tmp->value, value, 0x0, 0x0))
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	func_err(char *s)
{
	struct stat	buf;

	if (!strcmp_f(s, "..", 0x0, 0x0) || !strcmp_f(s, ".", 0x0, 0x0))
		return ;
	if (stat(s, &buf) == 0)
	{
		if (buf.st_mode & S_IFDIR)
		{
			ex_st_f(126, 0x1);
			return (ft_put_err(s, ": is a directory"));
		}
		else if ((buf.st_mode & S_IXUSR) == 0)
		{
			ex_st_f(126, 0x1);
			return (ft_put_err(s, ": Permission denied"));
		}
	}
	ex_st_f(0x1, 0x1);
	return (ft_put_err(s, ": No such file or directory"));
}

int	close_fd(t_minishell *mini, int *fd, int flag, int pos)
{
	while (++pos < mini->len_tab)
	{
		if (flag == 0x2 || flag == 0x1)
		{
			if (mini->tab[pos] == flag
				|| mini->tab[pos] == 0x1
				|| mini->tab[pos] == 0x2)
				return (close (*fd));
		}
		else if (mini->tab[pos] == flag)
			return (close (*fd));
	}
	return (1);
}
