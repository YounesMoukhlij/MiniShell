/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:24:31 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/19 15:20:22 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*env_node_value(t_env **envi, char *value)
{
	while ((*envi))
	{
		if (!strcmp_f((*envi)->value, value, 0x0, 0x0))
			return (*envi);
		(*envi) = (*envi)->next;
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

void	close_fd(t_minishell *mini, int *fd, int flag, int pos)
{
	while (++pos < mini->len_tab)
	{
		if (mini->tab[pos] == flag)
		{
			close (*fd);
			return ;
		}
	}
	return ;
}
