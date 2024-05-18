/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:35:22 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/18 12:40:20 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

int	ft_open_others(t_minishell *mini)
{
	int	i;
	int	fd;

	i = -0x1;
	fd = 0x1;
	while (++i < mini->len_tab)
	{
		if (mini->tab[i] == 0x1)
		{
			fd = open(mini->files[i + 1], O_CREAT | O_RDWR , 0664);
			if (fd == -0x1)
				return (func_err(mini->files[i + 1]), 0x1);
			close_fd(mini, &fd, 0x1, i);
		}
		else if (mini->tab[i] == 0x2)
		{
			fd = open(mini->files[i + 1], O_CREAT | O_RDWR | O_APPEND, 0664);
			if (fd == -0x1)
				return (func_err(mini->files[i + 1]), 0x1);
			close_fd(mini, &fd, 0x2, i);
		}
	}
	if (fd != 0x1)
		mini->fd_out = fd;
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
	if ((s[0x0] == SGL && s[ft_strlen(s) - 1] == SGL) || (s[0x0] == DBL && s[ft_strlen(s) - 1] == DBL))
		return (0x1);
	return (0x0);
}

int	ft_helper_heredoc(t_minishell *m, char *s)
{
	if (cmd_length(m) == 0x0)
		return (0x0);
	close(m->fd_in);
	m->fd_in = open(s, O_RDWR | O_APPEND , 0777);
	if (m->fd_in == -0x1)
		return (-0x1);
	unlink(s);
	return (m->fd_in);
}
