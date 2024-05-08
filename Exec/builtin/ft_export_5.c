/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:28:14 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/08 18:17:25 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_correct(char *s)
{
	int		i;
	char	*r;

	i = 0x0;
	if (is_eq_exist(s))
	{
		r = ft_substr_executor(s, 0x0, is_eq_exist(s));
		while (r[i])
		{
			if (!ft_isalnum(s[i]))
				return (export_error(NULL, 0x0, s, 0x0), 0x1);
			i++;
		}
	}
	else
	{
		while (s[i])
		{
			if (!ft_isalnum(s[i]))
				return (export_error(NULL, 0x0, s, 0x0), 0x1);
			i++;
		}
	}
	return (0x0);
}

int	is_correct_1(char *s)
{
	int		i;
	char	*r;

	i = 0x0;
	if (is_eq_exist(s) != 0x0)
	{
		r = ft_substr_executor(s, 0x0, is_eq_exist(s));
		while (r[i])
		{
			if (!ft_isalnum(s[i]))
				return (0x1);
			i++;
		}
	}
	else
	{
		while (s[i])
		{
			if (!ft_isalnum(s[i]))
				return (0x1);
			i++;
		}
	}
	return (0x0);
}

int	err_export(char *s)
{
	if (ft_is_equal(s))
		return (0x0);
	return (0x1);
}

int	err_export_1(char *s)
{
	if (ft_is_equal_1(s))
		return (0x0);
	return (0x1);
}

char	*no_space(char *s)
{
	int		i;
	int		j;
	char	*r;
	int		flag;

	i = 0x0;
	j = 0x0;
	flag = 0x0;
	r = ft_calloc(ft_strlen(s) + 1, 0x1);
	if (!r)
		return (r);
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		{
			flag = 1;
			i++;
		}
		if (j > 1 && s[i - 1] == ' ' && ft_isalpha(s[i]) && flag == 1)
		{
			i--;
			flag = 0;
		}
		r[j] = s[i];
		j++;
		i++;
	}
	return (r);
}
