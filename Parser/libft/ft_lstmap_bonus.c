/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:04:57 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/09 21:04:59 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;
	t_list	*cur;

	if (!lst || !f || !del)
		return (0);
	cur = lst;
	new_list = 0;
	new_node = 0;
	while (cur)
	{
		new_node = ft_lstnew(NULL);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		else
		{
			new_node->content = f (cur->content);
			ft_lstadd_back(&new_list, new_node);
		}
		cur = cur->next;
	}
	return (new_list);
}
