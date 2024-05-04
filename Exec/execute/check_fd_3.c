/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:36:24 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/04 17:36:25 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_file_expanded(char *s)
{
	int	i;
	int	f;

	i = 0x0;
	f = 0x0;
	if (!s)
		return (0x0);
	if (s[0x0] == SGL && s[ft_strlen(s) - 1] == SGL)
		return (0x0);
	while (s[i])
	{
		if (s[i] == '$')
			f = 0x1;
		i++;
	}
	if (f == 0x1)
		return (0x1);
	return (0x0);
}

void	rmv_SGL_quotes_file(t_minishell *mini, char *str, int index)
{
	int		i;
	int		j;
	char	*s;

	i = 0x0;
	j = 0x0;
	if (!str || is_file_expanded(str))
		return ;
	s = ft_calloc(ft_strlen(str) + 0x1, 0x1);
	if (!s)
		return ;
	while (str[i])
	{
		if (str[i] == SGL && str[i])
			i++;
		if (!str[i])
			break ;
		s[j] = str[i];
		j++;
		i++;
	}
	mini->files[index] = s;
}

char	*ultra_expand_file(t_env *envir, char *s, int i, int j)
{
	char	*p;
	char	*res;

	i = 0x0;
	p = ft_calloc(100, 0x1);
	if (!p)
		return (NULL);
	while (s[i])
	{
		while (s[i] == '$')
		{
			while (s[i] == '$')
				i++;
			if (!ft_isalnum(s[i]))
			{
				i--;
				break ;
			}
			if (!ft_isalpha(s[i]))
			{
				i++;
				break ;
			}
			res = grep_from_env(envir, grep_value(&s[i]));
			p = add_t(p, res);
			if (ft_strlen(p) || !strcmp_f(res, "", 0x0, 0x0))
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

char	*files_without_quotes(char *s, int flag, int i, int j)
{
	char	*res;

	if (!s)
		return ("");
	res = calloc(strlen(s) + 0x1, 0x1);
	if (!res)
		return (NULL);
	if (s[i] == DBL && s[ft_strlen(s) - 1] == DBL)
		flag = 0x1;
	while (s[i])
	{
		if (s[i] == DBL && s[i] && flag == 0x1)
			i++;
		if (s[i] == SGL && flag == 0x0)
			i++;
		if (!s[i])
			break ;
		res[j] = s[i];
		i++;
		j++;
	}
	return (res);
}

int	expand_files(t_minishell **mini, t_env *envir, int i)
{
	char	**s;
	t_env	*tmp;

	s = (*mini)->files;
	if (!s)
		return (0x1);
	if (check_files(*mini, envir))
		return (0x0);
	while (s[i])
	{
		if (is_file_expanded(s[i]))
		{
			s[i] = without_quotes(s[i], 0x0);
			if (already_here(envir, s[i]))
				return (0x1);
			tmp = env_node(&envir, get_str(s[i]));
			if (tmp)
				(*mini)->files[i] = ultra_expand_file(envir, s[i], 0x0, 0x0);
			else
				(*mini)->files[i] = get_str(s[i]);
		}
		else
		{
			(*mini)->files[i] = files_without_quotes(s[i], 0x0, 0x0, 0x0);
			rmv_SGL_quotes_file((*mini), (*mini)->files[i + 0x1], i + 0x1);
		}
		i++;
	}
	return (0x0);
}
