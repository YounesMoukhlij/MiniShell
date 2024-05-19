/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:32:30 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/19 15:32:55 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*grep_from_env_1(t_env *envir, char *string)
{
	t_env	*tmp;

	tmp = envir;
	while (tmp)
	{
		if (!strcmp_f(tmp->key, string, 0x0, 0x0))
		{
			if (!tmp->value)
			{
				return (ft_strdup_1(""));
			}
			return (tmp->value);
		}
		tmp = tmp->next;
	}
	return (ft_strdup_1(""));
}

char	*allocate_max_1(t_env *envir)
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
	r = ft_calloc_1(max * 30, 1);
	return (r);
}

char	*grep_value_1(char *s)
{
	int		len;
	int		i;
	char	*r;

	len = 0x0;
	if (!s)
		return (NULL);
	while (s[len])
	{
		if (!ft_isalnum(s[len]))
			break ;
		len++;
	}
	r = malloc(len + 0x1);
	if (!r)
		return (NULL);
	i = 0x0;
	while (i < len)
	{
		r[i] = s[i];
		i++;
	}
	r[len] = '\0';
	return (r);
}
