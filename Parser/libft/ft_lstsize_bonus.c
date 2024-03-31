/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:56:19 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/08 15:14:33 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
