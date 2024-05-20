/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:37:34 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/20 17:40:19 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_existed(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (s[i] == '$' && s[i + 1] == '?')
			return (0x1);
		i++;
	}
	return (0x0);
}

int	e_x_1(char *s, int *i, int *c)
{
	*c = 0x0;
	while (s[*i] == '$' && s[*i])
	{
		(*i)++;
		(*c)++;
	}
	if (*c % 2 == 0x0)
		return (0x1);
	return (0x0);
}

void	e_x_2(char **r, int *i, int *j, t_env *env)
{
	*r = add_t(*r, ft_itoa(ex_st_f(0x0, 0x0)), env);
	if (ft_strlen(*r))
		*i += 1;
	*j = ft_strlen(*r);
}

char	*ft_exit_status(char *s, t_env *envir, int i, int j)
{
	char	*r;
	int		c;

	r = ft_calloc(200, 1);
	if (!r)
		return (NULL);
	while (s[i])
	{
		while (s[i] == '$' && dollar_position(s, i) && s[i])
		{
			if (e_x_1(s, &i, &c))
				break ;
			if (s[i] == '?')
				e_x_2(&r, &i, &j, envir);
			else
			{
				i--;
				break ;
			}
		}
		if (!s[i] || i > ft_strlen(s))
			break ;
		r[j++] = s[i++];
	}
	return (r);
}

int	extra_check(char *s)
{
	if (((s[0] == '$') && (s[1] == DBL)) || (s[1] == SGL))
		return (0x1);
	return (0x0);
}
