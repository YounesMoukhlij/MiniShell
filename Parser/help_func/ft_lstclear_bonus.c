/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:54:46 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 16:24:11 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		i;
	t_list	*poiter;
	t_list	*temp;

	if (!del || !lst)
		return ;
	i = ft_lstsize(*lst);
	poiter = *lst;
	while (i > 0)
	{
		temp = poiter->next;
		(*del)(poiter->content);
		free(poiter);
		poiter = temp;
		i--;
	}
	*lst = NULL;
}
