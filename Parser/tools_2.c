/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:55:01 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 16:20:14 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_get_len(char *s1, int i, size_t *len_word, int fg)
{
	while (s1[i])
	{
		if (s1[i] == '\'' || s1[i] == '\"')
		{
			if (s1[i] == '\"' )
				ft_parq(s1, &i, 'q');
			else if (s1[i] == '\'')
				ft_parq(s1, &i, 's');
			(*len_word) += i;
		}
		else if (!get_des(s1[i], fg))
		{
			i++;
			(*len_word)++;
		}
		else
			break ;
	}
}

void	is_quot_(char *str, int *i)
{
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		if (str[*i] == '\'')
		{
			(*i)++;
			while (str[*i] != '\'')
				(*i)++;
		}
		else if (str[*i] == '\"')
		{
			(*i)++;
			while (str[*i] != '\"')
				(*i)++;
		}
	}
	return ;
}

void	hund(char *s1, int *id, int *i, char *word)
{
	int	op;

	op = 0;
	if (s1[*id] == '\"' )
	{
		while (s1[*id] && op == 0)
		{
			word[(*i)++] = s1[(*id)++];
			if (s1[*id] == '\"')
				op = 1;
		}
	}
	else if (s1[*id] == '\'' )
	{
		while (s1[*id] && op == 0)
		{
			word[(*i)++] = s1[(*id)++];
			if (s1[*id] == '\'')
				op = 1;
		}
	}
}
