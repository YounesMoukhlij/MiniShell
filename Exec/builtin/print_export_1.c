/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:40:33 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/17 12:52:43 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_swap_nodes(t_env *tmp)
{
	char	*str;

	if (strcmp_f(tmp->key, tmp->next->key, 0x0, 0x0) > 0)
	{
		str = ft_strdup(tmp->next->key);
		free(tmp->next->key);
		tmp->next->key = ft_strdup(tmp->key);
		free(tmp->key);
		tmp->key = str;
		str = ft_strdup(tmp->next->value);
		free(tmp->next->value);
		tmp->next->value = ft_strdup(tmp->value);
		free(tmp->value);
		tmp->value = str;
	}
}
