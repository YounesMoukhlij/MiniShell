/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:31:29 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/05 23:33:13 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*allocate_max(t_env *envir)
{
	t_env	*head;
	int		max;
	char	*r;

	head = envir;
	max = ft_strlen(head->value);
	while (head)
	{
		if (max < ft_strlen(head->value))
			max = ft_strlen(head->value);
		head = head->next;
	}
	r = ft_calloc(max, 1);
	return (r);
}

void	ft_free_env(t_env **env)
{
	t_env	*current;
	t_env	*temp;

	current = *env;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*env = NULL;
}

void	ft_free_strings(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	s = NULL;
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
