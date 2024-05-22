/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:35:22 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/22 16:00:34 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_open_others(t_minishell *mini, int i, int f_in, int f_out)
{
	while (++i < mini->len_tab)
	{
		if (mini->tab[i] == 0x1)
		{
			f_out = open(mini->files[i + 1], O_CREAT | O_RDWR, 0777);
			if (f_out == -0x1)
				return (func_err(mini->files[i + 1]), 0x1);
			close_fd(mini, &f_out, 0x1, i);
		}
		else if (mini->tab[i] == 0x2)
		{
			f_out = open(mini->files[i + 1], O_CREAT | O_RDWR | O_APPEND, 0664);
			if (f_out == -0x1)
				return (func_err(mini->files[i + 1]), 0x1);
			close_fd(mini, &f_out, 0x2, i);
		}
		else if (mini->tab[i] == 0x3)
		{
			f_in = open(mini->files[i + 1], O_RDONLY, 0664);
			if (f_in == -0x1)
				return (func_err(mini->files[i + 1]), 0x1);
			close_fd(mini, &f_in, 0x3, i);
		}
	}
	if (f_out != 0x1)
		mini->fd_out = f_out;
	if (f_in != 0x0)
		mini->fd_in = f_in;
	return (0);
}

char	*hidden_name(void)
{
	static int	i;
	char		*s1;

	s1 = ft_strjoin_executor("/tmp/tmp_file_", ft_itoa(i));
	i++;
	return (s1);
}

int	expanded_content(char *s)
{
	if ((s[0x0] == SGL && s[ft_strlen(s) - 1] == SGL)
		|| (s[0x0] == DBL && s[ft_strlen(s) - 1] == DBL))
		return (0x1);
	return (0x0);
}

int	ft_helper_heredoc(t_minishell *m, char *s)
{
	if (cmd_length(m) == 0x0)
		return (0x0);
	close(m->fd_in);
	m->fd_in = open(s, O_RDWR | O_APPEND, 0777);
	if (m->fd_in == -0x1)
		return (-0x1);
	unlink(s);
	return (m->fd_in);
}

int	func(char *p, char *res, int *i, char *s)
{
	int	j;

	j = 0x0;
	if (ft_strlen(p) || !ft_strlen(res))
		*i += grep(&s[*i]);
	j = ft_strlen(p);
	return (j);
}
