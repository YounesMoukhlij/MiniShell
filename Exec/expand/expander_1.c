/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:56:23 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/20 13:54:28 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_quotes(char *s)
{
	int	i;

	i = 0x0;
	if (!s)
		return (0x0);
	while (s[i])
	{
		if (!strcmp_f(s, "''", 0x0, 0x0) || !strcmp_f(s, "\"\"", 0x0, 0x0))
			return (0x1);
		i++;
	}
	return (0x0);
}

int	get_double_arr_len(char **s)
{
	int	i;

	i = 0x0;
	if (!s)
		return (-1);
	while (s[i])
		i++;
	return (i);
}

int	check_execute(char *s)
{
	int		i;
	char	**r;

	i = 0x0;
	if (!s)
		return (0x0);
	if ((s[0] == SGL && s[ft_strlen(s) - 1] == SGL)
		|| (s[0] == DBL && s[ft_strlen(s) - 1] == DBL))
	{
		r = ft_split_executor(s, ' ');
		if (get_double_arr_len(r) > 1)
			return (0x1);
	}
	return (0x0);
}

int	check_dollar(t_env *env, char *s)
{
	int		i;
	char	**r;
	char	*str;
	char	*o;

	i = 0x0;
	if (!s)
		return (0x0);
	if ((s[0] == SGL && s[ft_strlen(s) - 1] == SGL)
		|| (s[0] == DBL && s[ft_strlen(s) - 1] == DBL))
	{
		while (s[i])
		{
			if (s[i] == '$')
			{
				o = no_qts(s, 0x0, 0x0, 0x0);
				str = grep_from_env_1(env, &o[1]);
				r = ft_split_executor(str, ' ');
				if (get_double_arr_len(r) > 1)
					return (0x1);
			}
			i++;
		}
	}
	return (0x0);
}
