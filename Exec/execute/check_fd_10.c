/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:42:47 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/24 15:37:38 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_open_3(t_minishell *m, char *s, int *f_in, int *i)
{
	*f_in = open(s, O_RDONLY, 0664);
	if (*f_in == -0x1)
		return (func_err(s), 0x1);
	close_fd(m, f_in, 0x3, *i);
	return (0x0);
}

int	ft_open_2(t_minishell *m, char *s, int *f_out, int *i)
{
	*f_out = open(s, O_CREAT | O_RDWR | O_APPEND, 0664);
	if (*f_out == -0x1)
		return (func_err(s), 0x1);
	close_fd(m, f_out, 0x2, *i);
	return (0x0);
}

int	ft_open_1(t_minishell *m, char *s, int *f_out, int *i)
{
	*f_out = open(s, O_CREAT | O_RDWR, 0777);
	if (*f_out == -0x1)
		return (func_err(s), 0x1);
	close_fd(m, f_out, 0x1, *i);
	return (0x0);
}

int	big_built_in(t_minishell *mini, t_env *envir, int flag)
{
	if (mini->size == 0x1 && is_builtin(mini))
	{
		flag = is_builtin_cmd(mini, envir);
		if (return_cmd(flag))
		{
			return (0x1);
		}
	}
	return (0x0);
}

void	ft_close_fd(t_minishell **head)
{
	if ((*head)->fd_out != 0x1)
		close ((*head)->fd_out);
	if ((*head)->fd_in != 0x0)
		close ((*head)->fd_in);
}
