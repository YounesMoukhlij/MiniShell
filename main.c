/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 16:27:18 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_empty(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0x1);
	while (s[i])
	{
		if ((s[i] >= '9' && s[i] <= 13) || s[i] == 32)
			return (0x1);
		i++;
	}
	return (0x0);
}

int	main(int ac, char **av, char **env)
{
	char		*str;
	t_minishell	*mini;

	while (1)
	{
		str = readline("minishell $> ");
		if (is_empty(str))
			break;
		mini = parcing(str);
		
	}
	return (0);
}
