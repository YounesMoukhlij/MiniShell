/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:31:29 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/23 16:05:37 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*allocate_max(t_env *envir)
{
	char	*r;

	(void) envir;
	r = ft_calloc(300 * 10, 1);
	return (r);
}

int	ft_isalnum_1(int c)
{
	return ((ft_isdigit(c) || ft_isalpha(c)) || c == '+' || c == '_');
}

int	lst_size(t_minishell **head)
{
	int			i;
	t_minishell	*tmp;

	i = 0;
	tmp = *head;
	while ((tmp))
	{
		(tmp) = (tmp)->next;
		i++;
	}
	return (i);
}

int	get_env_max(t_env *envir)
{
	t_env	*head;
	int		max;

	head = envir;
	max = ft_strlen(head->value);
	while (head)
	{
		if (max < ft_strlen(head->value))
			max = ft_strlen(head->value);
		head = head->next;
	}
	return (max * 30);
}
