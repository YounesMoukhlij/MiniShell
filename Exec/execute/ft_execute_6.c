/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:04:24 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/29 11:19:06 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	msg_error_fork(void)
{
	static int	error_printed;

	error_printed = 0;
	if (!error_printed)
	{
		perror("fork");
		error_printed = 1;
	}
	else
		return ;
}

int	safe_fork(void)
{
	int	id;

	id = fork();
	if (id == -1)
		msg_error_fork();
	return (id);
}

int	cm_len(t_minishell *m)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (m->cmd[i])
	{
		if (ft_strlen(m->cmd[i]))
			l++;
		i++;
	}
	return (l);
}

char	**cmd(t_minishell *m)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = ft_malloc(8 * (cm_len(m) + 0x1), 0x1);
	if (!res)
		return (NULL);
	while (i < cmd_length(m))
	{
		if (ft_strlen(m->cmd[i]))
			res[j++] = ft_strdup(m->cmd[i]);
		i++;
	}
	res[j] = 0;
	return (res);
}
