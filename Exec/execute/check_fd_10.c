/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:42:47 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/22 18:43:06 by youmoukh         ###   ########.fr       */
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
