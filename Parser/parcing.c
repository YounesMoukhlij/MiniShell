/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:20:45 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/24 15:30:25 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_minishell	*parcing(char *str)
{
	t_minishell	*cmp;
	t_minishell	*head;
	char		 **strs;

	cmp = NULL;
	head = NULL;
	strs = ft_spliter(str);
	if (!strs)
		return (NULL);
	cmp = get_link_cmd(strs, head , cmp);
	// ft_cleantach(strs);
	return (cmp);
}
