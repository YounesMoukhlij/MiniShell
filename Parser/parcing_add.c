/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:08:28 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/21 15:06:00 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_des(char c, int fg)
{
	if (fg == 1)
	{
		if (c == '>' || c == '<')
			return (1);
	}
	else
		if (c == '\t' || c == ' ')
			return (1);
	return (0);
}

char	*hudler_ts(char *s1, char *word, int *id, int fg)
{
	int	i;
	int	op;

	i = 0;
	op = 0;
	while (s1[*id] && (!get_des(s1[*id], fg)))
	{
		if (s1[*id] == '\'' || s1[*id] == '\"')
		{
			if (!op)
			{
				hund(s1, id, &i, word);
				op = 0;
			}
		}
		if (!s1[*id])
			break ;
		word[i++] = s1[(*id)++];
	}
	word[i] = '\0';
	return (word);
}

int	red_check(char *str, int i, int t)
{
	while (str[++i])
	{
		ft_skep(str, &i);
		if (!str[i])
			break ;
		if (str[i] == '>')
		{
			while (str[i] == '>' && str[i])
			{
				if (str[i + 1] == '<')
					return (5);
				i++;
				t++;
			}
			if (!str[i])
				break ;
			if (t >= 3)
				return (1);
			t = 0;
		}
		if (!str[i])
			break ;
	}
	return (0);
}
