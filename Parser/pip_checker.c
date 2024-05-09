/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:53:06 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/09 16:01:20 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pip_check_close(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
		{
			i++;
			if (str[i] == '|')
				i++;
			while ((str[i] == 9 || str[i] == 32) && str[i])
				i++;
			if (str[i] == '|' || !str[i])
				return (1);
		}
		i++;
	}
	return (0);
}

int	pip_loading(char *str, int *i, int *t)
{
	if (str[*i] == '|')
	{
		while (str[*i] == '|')
		{
			if ((str[*i] == 9 || str[*i] == 32) && str[*i])
				i++;
			(*i)++;
			(*t)++;
		}
		if (!str[*i])
			return (1);
		if (*t >= 2)
			return (1);
		(*t) = 0;
	}
	(*i)++;
	return (0);
}

int	pip_check(char *str)
{
	int	i;
	int	t;

	t = 0;
	i = 0;
	if (str[i] == '|')
		return (1);
	if (pip_check_close(str))
		return (1);
	while (str[i])
	{
		ft_skep(str, &i);
		if (!str[i])
			break;
		if (pip_loading(str, &i, &t))
			return (1);
	}
	return (0);
}
