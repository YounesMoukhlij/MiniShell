/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:44:59 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/22 13:32:43 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	help_1(char **delim, int *flag)
{
	if (expanded_content(*delim))
		*flag = 0x1;
	*delim = no_qts(*delim, 0x0, 0x0, 0x0);
	if (!strcmp_f(*delim, "$", 0x0, 0x0))
		(*delim)++;
}

void	help_her(char *s, t_env *env, int *fd)
{
	char	*str;

	str = expand_heredoc(env, s, 0x0, 0x0);
	ft_putstr_fd_executor(s, *fd, 0x1);
	free (str);
}

int	heredoc_1(char *s, char *delim)
{
	if (!s || !strcmp_f(s, delim, 0x0, 0x0))
	{
		free(s);
		return (0x1);
	}
	return (0x0);
}

int	heredoc_check(t_minishell *mini, t_env *env, char *delim, int flag)
{
	t_herdoc	tmp;

	tmp.hdd_f = hidden_name();
	mini->fd_in = open(tmp.hdd_f, O_CREAT | O_RDWR | O_APPEND, 0777);
	if (mini->fd_in == -0x1)
		return (-0x1);
	(1) && (help_1(&delim, &flag), signal(SIGINT, sig_n));
	while (1999)
	{
		tmp.s = readline("heredoc> ");
		if (!ttyname(0))
			return (open(ttyname(2), O_RDWR), -0x1);
		if (heredoc_1(tmp.s, delim))
			break ;
		if (flag == 0x0 && no_dollar(tmp.s))
		{
			tmp.str = expand_heredoc(env, tmp.s, 0x0, 0x0);
			ft_putstr_fd_executor(tmp.str, mini->fd_in, 0x1);
			free (tmp.str);
		}
		else
			ft_putstr_fd_executor(tmp.s, mini->fd_in, 0x1);
		free (tmp.s);
	}
	return (ft_helper_heredoc(mini, tmp.hdd_f));
}
