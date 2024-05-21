/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getstr_fpromt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:23:08 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/21 15:00:43 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	cas_1(char *str, char *ns, int *j, int *i)
{
	int	op;

	op = 0;
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
	if (str[i] != '\"' && str[i] != '\'')
		ns[(*j)++] = ' ';
	return (0);
}

char	*str_caller(char *str)
{
	char	*ns;

	ns = ft_calloc(ft_strlen(str) * 10, 1);
	return (getstr_fpromt(str, ns));
}

char	*getstr_fpromt(char *str, char *ns)
{
	int	i;
	int	j;
	int	op;

	i = 0;
	j = 0;
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
		else
			ns[j++] = str[i++];
	}
	return (ns);
}
