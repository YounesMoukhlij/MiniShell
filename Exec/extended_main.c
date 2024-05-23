/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:52:15 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/23 19:15:06 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_close_fd(t_minishell *m)
{
	t_minishell	*tmp;

	tmp = m;
	while (tmp)
	{
		if (tmp->fd_in != 0)
		{
			if (close(tmp->fd_in) == -1)
				return ;
		}
		if (tmp->fd_out != 1)
			close(tmp->fd_out);
		tmp = tmp->next;
	}
}

void	ft_end(t_minishell *m, char *s, t_fd fd)
{
	get_fd_back(fd);
	ft_close_fd(m);
	close(fd.fdin);
	close(fd.fdout);
	free(s);
	ft_malloc(0x0, 0x0);
}

void	clean_1(char *s)
{
	ft_malloc(0x0, 0x0);
	free(s);
}

void	clean_2(char *s, t_minishell *mini)
{
	free(s);
	ft_cleanshell(&mini);
}

int	check_promt(char *promt)
{
	if (!promt)
	{
		clean_1(promt);
		return (0x0);
	}
	if (is_empty(promt) == 1 || syntax(promt) != -0x1)
	{
		free(promt);
		return (0x1);
	}
	return (0x2);
}
