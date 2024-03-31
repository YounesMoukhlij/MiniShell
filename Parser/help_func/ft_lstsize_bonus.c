/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:56:19 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 16:24:11 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*head;
	int		cl;

	if (!lst)
		return (0);
	head = lst;
	cl = 0;
	while (head)
	{
		cl++;
		head = head->next;
	}
	return (cl);
}
