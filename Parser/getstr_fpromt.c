/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getstr_fpromt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:23:08 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/30 14:31:05 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	cas_1(char *str, char *ns, int *j, int *i)
{
	int	op;

	op = 0;
	if (*i)
	{
		if (str[*i - 1] == '<' || str[*i - 1] == '>')
			ns[(*j)++] = ' ';
	}
	while (str[*i] && op == 0)
	{
		ns[(*j)++] = str[(*i)++];
		if (str[*i] == '\"')
			op = 1;
	}
	ns[(*j)++] = str[(*i)++];
	return (op);
}

static int	cas_2(char *str, char *ns, int *j, int *i)
{
	int	op;

	op = 0;
	if (*i)
	{
		if (str[*i - 1] == '<' || str[*i - 1] == '>')
			ns[(*j)++] = ' ';
	}
	while (str[*i] && op == 0)
	{
		ns[(*j)++] = str[(*i)++];
		if (str[*i] == '\'')
			op = 1;
	}
	ns[(*j)++] = str[(*i)++];
	return (op);
}

static int	texter(char *str, char *ns, int i, int *j)
{
	if (str[i] == '|')
		ns[(*j)++] = ' ';
	return (0);
}

char	*str_caller(char *str)
{
	char	*ns;

	ns = ft_calloc(ft_strlen(str) * 10, 1);
	return (getstr_fpromt(str, ns, 0x0, 0x0));
}

char	*getstr_fpromt(char *str, char *ns, int i, int j)
{
	int	op;

	op = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '\"')
		{
			op = cas_1(str, ns, &j, &i);
			if (op == 1)
				op = texter(str, ns, i, &j);
		}
		else if (str[i] == '\'')
		{
			op = cas_2(str, ns, &j, &i);
			if (op == 1)
				op = texter(str, ns, i, &j);
		}
		else if (str[i])
			ns[j++] = str[i++];
		else
			(1) && (j++, i++);
	}
	return (ns);
}
