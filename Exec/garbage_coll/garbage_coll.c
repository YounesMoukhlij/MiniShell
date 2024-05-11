/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_coll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:27:59 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/11 19:43:23 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_delete	*last_cmd_garbage(t_delete *lst)
{
	t_delete	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	lstaddfront_garbage(t_delete **head, t_delete *node)
{
	node->next = (*head);
	(*head) = node;
}

void	add_back_garbage(t_delete **head, t_delete *node)
{
	if (!head || !node)
		return ;
	if (*head == NULL)
		lstaddfront_garbage(head, node);
	last_cmd_garbage(*head)->next = node;
	node->next = NULL;
}

void	*ft_malloc(size_t size, int mode) 
{
    static t_delete *collecte = NULL;
    t_delete *lst;
    void	*str;
    
    if (mode == 0x1)
	{
        str = malloc(size);
        if (str == NULL)
			return ();
        else
		{
            lst = (t_delete *)malloc(sizeof(t_delete));
            if (lst != NULL) {
                lst->ptr = str;
                lst->next = collecte;
                collecte = lst;
            }
        }
    }
    else {
        // Add the deallocation logic here
        // For simplicity, let's just free the first allocated block
        // if (collecte != NULL) {
        //     lst = collecte;
        //     collecte = collecte->next;
        //     free(lst->ptr);
        //     free(lst);
        // }
    }
    
    return str;
}