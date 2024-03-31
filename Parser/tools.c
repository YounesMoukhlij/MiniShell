/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:17:36 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 16:20:14 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	case_1(char c, int *i, int *len)
{
	if (c == '<')
	{
		*len += 1;
		*i += 1;
	}
	else
		*len += 1;
}

static void	case_2(char c, int *i, int *len)
{
	if (c == '>')
	{
		*len += 1;
		*i += 1;
	}
	else
		*len += 1;
}

int	ft_set_tk(char *str)
{
	int	len;
	int	i;
	int	op;

	len = 0;
	i = 0;
	op = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (str[i] == '\'')
				op = ft_parq(str, &i, 's');
			else if (str[i] == '\"')
				op = ft_parq(str, &i, 'q');
			op = 0;
			if (!str[i])
				break ;
		}
		if (str[i] == '<')
			case_1(str[i], &i, &len);
		else if (str[i] == '>')
			case_2(str[i], &i, &len);
		i++;
	}
	return (len);
}

int	ft_parq(char *str, int *i, char f)
{
	int	op;

	op = 0;
	*i += 1;
	if (f == 'q')
	{
		while ((str[*i]) && op == 0)
		{
			if (str[*i] == '\"')
				op = 1;
			*i += 1;
		}
	}
	else if (f == 's')
	{
		while ((str[*i]) && op == 0)
		{
			if (str[*i] == '\'')
				op = 1;
			*i += 1;
		}
	}
	return (op);
}
