/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:08:07 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/12 15:26:31 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	sig_n(int sig_v)
{
	if (sig_v == SIGINT)
	{
		glb_sig = 0;
		close(0);
	}
}

char	*herdoc_helper(char *s, t_env *envir)
{
	int		i;
	int		j;
	char	*r;
	int		c;

	r = ft_calloc(200, 1);
	i = 0x0;
	j = 0x0;
	while (s[i])
	{
		while (s[i] == '$' && s[i])
		{
			c = 0x0;
			while (s[i] == '$' && s[i])
			{
				i++;
				c++;
			}
			if (c % 2 == 0x0)
				break ;
			if (s[i] == '?')
			{
				r = add_t(r, ft_itoa(ex_st_f(0x0, 0x0)), envir);
				if (ft_strlen(r))
					i += 1;
				j = ft_strlen(r);
			}
			else
			{
				i--;
				break ;
			}
		}
		if (!s[i] || i > ft_strlen(s))
			break ;
		r[j] = s[i];
		i++;
		j++;
	}
	return (r);
}

char	*expand_heredoc(t_env *envir, char *r, int i, int j)
{
	int		c;
	char	*p;
	char	*s;
	char	*res;

	p = allocate_max(envir);
	if (!p)
		return (NULL);
	s = herdoc_helper(r, envir);
	while (s[i])
	{
		while (s[i] == '$')
		{
			c = 0x0;
			while (s[i] == '$')
			{
				i++;
				c++;
			}
			if (c % 2 == 0x0)
				break ;
			if (c == 0x1 && s[i - 0x1] == '$' && !ft_isalnum(s[i]))
			{
				i--;
				break ;
			}
			if (!ft_isalpha(s[i]))
			{
				i++;
				break ;
			}
			res = grep_from_env(envir,  grep_value(&s[i]));
			if (res)
				p = add_t(p, res, envir);
			if (ft_strlen(p) || !ft_strlen(res))
				i += grep(&s[i]);
			j = ft_strlen(p);
		}
		if (!s[i] || i > ft_strlen(s))
			break ;
		p[j] = s[i];
		i++;
		j++;
	}
	return (p);
}

int	heredoc_check(t_minishell *mini, t_env *env, char *delim, int flag)
{
	char	*s;
	char	*hdd_f;

	hdd_f = hidden_name();
	mini->fd_in = open(hdd_f, O_CREAT | O_RDWR, 0777);
	if (mini->fd_in == -0x1)
		return (-0x1);
	if (expanded_content(delim))
		flag = 0x1;
	delim = without_quotes(delim, 0x0);
	while (1999)
	{
		signal(SIGINT, sig_n);
		s = readline("heredoc> ");
		if (glb_sig == 0)
			return (open(ttyname(2), O_RDWR), 0x1);
		if (!s || !strcmp_f(s, delim, 0x0, 0x0))
		{
			break ;
		}
		if (flag == 0x0 && no_dollar(s))
			s = expand_heredoc(env, s, 0x0, 0x0);
		ft_putstr_fd_executor(s, mini->fd_in, 0x1);
	}
	return (ft_helper_heredoc(mini, hdd_f));
}

int	ft_fd_files(t_minishell *mini, t_env *env)
{
	int	i;
	int	fd;

	i = -0x1;
	fd = 0x0;
	while (++i < mini->len_tab)
	{
		if (mini->tab[i] == 0x4)
			fd = heredoc_check(mini, env, mini->files[i + 0x1], 0x0);
		if (mini->tab[i] == 0x3 || mini->tab[i] < 0)
		{
			fd = open(mini->files[i + 0x1], O_RDONLY);
			if (fd == -0x1)
			{
				ex_st_f(0x1, 0x1);
				func_err(mini->files[i + 0x1]);
				return (0x1);
			}
		}
	}
	if (fd != 0x0)
		mini->fd_in = fd;
	return (0x0);
}

char	*get_str(char *s)
{
	int	i;
	int	count;

	i = 0x0;
	count = 0x0;
	while (s[i])
	{
		if (s[i] == '$')
			count++;
		i++;
	}
	return (&s[count]);
}

int	check_f(char *s)
{
	char	**r;
	int		i;

	i = 0x0;
	if (!s)
		return (0x0);
	r = ft_split_executor(s, ' ');
	while (r[i])
		i++;
	if (i > 0x1)
		return (0x1);
	return (0x0);
}

void	helper_files(char *s)
{
	ft_putstr_fd("Minishell: ", 0x2);
	ft_putstr_fd(s, 0x2);
	ft_putendl_fd(": ambiguous redirect", 0x2);
	ex_st_f(0x1, 0x1);
}

int	check_files(t_minishell *m, t_env *env, int i)
{
	t_env	*tmp;
	
	if (!m->files)
		return (0x0);
	while (++i < m->len_tab)
	{
		tmp = env_node(&env,  get_str(m->files[i + 1]));
		if (tmp)
		{
			if (check_f(tmp->value))
			{
				if (m->files[i + 1][0x0] == '$')
					return (helper_files(m->files[i + 1]), -0x1);
			}
		}
		else if (!tmp)
		{
			if (m->files[i + 1][0x0] == '$')
					return (helper_files(m->files[i + 1]), -0x1);
		}
	}
	return (0x0);
}

int	already_here(t_env *env, char *s)
{
	t_env	*tmp;

	if (!s)
		return (0x1);
	tmp = env_node(&env, get_str(s));
	if (tmp)
		return (0x0);
	return (0x1);
}
