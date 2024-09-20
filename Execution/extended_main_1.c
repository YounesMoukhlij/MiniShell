/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_main_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:53:23 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/29 13:47:26 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ex_st_f(int status, int mode)
{
	static int	saved;

	if (mode == 1)
		saved = status;
	return (saved);
}

void	get_fd_back(t_fd fd)
{
	dup2(fd.fdout, 0x1);
	dup2(fd.fdin, 0x0);
}

int	heredock(t_minishell *mini, t_env *env, int i)
{
	t_minishell	*tmp;
	int			fd;

	tmp = mini;
	fd = -0x1;
	while (tmp)
	{
		i = -0x1;
		while (++i < tmp->len_tab)
		{
			if (tmp->tab[i] == 0x4)
			{
				fd = heredoc_check(tmp, env, tmp->files[i + 0x1], 0x0);
				if (fd == -0x1)
					return (0x1);
			}
			if (cmd_length(mini) != 0)
				close_fd(mini, &fd, 0x4, i);
		}
		tmp = tmp->next;
	}
	return (0x0);
}

int	syntax(char *promt)
{
	int	i;

	i = ft_checker(promt);
	add_history(promt);
	ft_puterror(i);
	return (i);
}
