/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:24:31 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/15 14:02:00 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*env_node_value(t_env **envi, char *value)
{
	while ((*envi))
	{
		if (!strcmp_f((*envi)->value, value, 0x0, 0x0))
			return (*envi);
		(*envi) = (*envi)->next;
	}
	return (NULL);
}