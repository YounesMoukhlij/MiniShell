/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:27:40 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/19 15:32:49 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	sig_n(int sig_v)
{
	if (sig_v == SIGINT)
	{
		ex_st_f(0x1, 0x1);
		close(0);
	}
}

char	*handle_question_mark(t_vars *vars)
{
	vars->r = add_t(vars->r, ft_itoa_1(ex_st_f(0x0, 0x0)), vars->envir);
	if (!vars->r)
		return (NULL);
	if (ft_strlen(vars->r))
		vars->i++;
	vars->j = ft_strlen(vars->r);
	return (vars->r);
}

int	process_dollar_signs(t_vars *vars)
{
	int	c;

	c = 0;
	while (vars->s[vars->i] == '$' && vars->s[vars->i])
	{
		vars->i++;
		c++;
	}
	return (c);
}

char	*process_string(t_vars *vars)
{
	int	c;

	while (vars->s[vars->i])
	{
		if (vars->s[vars->i] == '$')
		{
			c = process_dollar_signs(vars);
			if (c % 2 == 0)
				continue ;
			if (vars->s[vars->i] == '?')
			{
				vars->r = handle_question_mark(vars);
				if (!vars->r)
					return (NULL);
			}
			else
			{
				vars->i--;
			}
		}
		if (!vars->s[vars->i] || vars->i > ft_strlen(vars->s))
			break ;
		vars->r[vars->j++] = vars->s[vars->i++];
	}
	return (vars->r);
}

char	*herdoc_helper(char *s, t_env *envir, int i, int j)
{
	t_vars	vars;

	vars.s = s;
	vars.envir = envir;
	vars.i = i;
	vars.j = j;
	vars.r = ft_calloc(200, 1);
	if (!vars.r)
		return (NULL);
	vars.r = process_string(&vars);
	return (vars.r);
}
