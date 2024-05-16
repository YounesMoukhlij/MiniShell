/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:28:14 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/15 20:41:21 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_first(char *s)
{
	int		i;
	int		j;
	char	*t;
	
	j = is_eq_exist(s);
	if (j != 0)
		t = ft_substr_executor_1(s, 0x0, is_eq_exist(s) + 1);
	else
		t = s;
	i = 0x0;
	while (t[i])
	{
		if (!ft_isalpha(t[0]))
			return (0x1);
		if (!ft_isalnum(t[i]) && t[i] != '_' && t[i] != '=')
		{
			if (t[i + 1] && t[i] == '+' && t[i + 1] == '=')
				return (0x0);
			return (0x1);
		}
		i++;
	}
	return (0x0);
}

int	err_export(char *s)
{
	if (!s)
		return (0x0);
	if (check_first(s))
		return (export_error(NULL, 0x0, s, 0x0), 0x0);
	return (0x1);
}

int	err_export_1(char *s)
{
	if (!s)
		return (0x0);
	if (check_first(s))
		return (0x0);
	return (0x1);
}
