/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_q.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:21:24 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/20 19:30:51 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_qap(char *str, int *i)
{
	int	c;

	c = 0;
	if (str[*i + 1] && ((str[*i + 1] == '\'' || str[*i + 1] == '\"')
			&& !str[*i + 2]))
	{
		(*i)--;
		while (*i < ft_strlen(str) && *i > 0)
		{
			(*i)--;
			if ((str[*i] == '\'' || str[*i] == '\"'))
				c++;
		}
	}
	return (c);
}

int	ft_check_q(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '|')
			break ;
		i++;
	}
	if (str[i] != '|')
		return (1);
	if (str[i - 1] == '\'' || str[i - 1] == '\"')
		c = check_qap(str, &i);
	if ((((c)) && !(c % 2)))
		return (0);
	return (1);
}
