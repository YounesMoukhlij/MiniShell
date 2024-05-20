/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_coll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:27:59 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/20 13:23:34 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_delete    *lstnew_garbage(void *str)
{
    t_delete    *lst;

    lst = malloc(sizeof(t_delete));
    if (!lst)
        return (NULL);
    lst->ptr = str;
    lst->next = NULL;
    return (lst);
}

t_delete    *last_cmd_garbage(t_delete *lst)
{
    t_delete    *tmp;

    if (!lst)
        return (NULL);
    tmp = lst;
    while (tmp->next)
        tmp = tmp->next;
    return (tmp);
}

void    lstaddfront_garbage(t_delete **head, t_delete *node)
{
    node->next = (*head);
    (*head) = node;
}

void    add_back_garbage(t_delete **head, t_delete *node)
{
    if (!head || !node)
        return ;
    if (*head == NULL)
        lstaddfront_garbage(head, node);
    last_cmd_garbage(*head)->next = node;
    node->next = NULL;
}

void free_list(t_delete **head)
{
    t_delete *current = *head;
    t_delete *next;
    while (current != NULL)
    {
        free(current->ptr);
        next = current->next;
        free (current);
        current = next;
    }
    *head = NULL;
}

void    *ft_malloc(size_t size, int mode)
{
    static t_delete *collecte;
    void    *str;
    
    str = NULL;
    if (mode == 0x1)
    {
        str = malloc(size);
        if (str == NULL)
            return NULL;
        else
            add_back_garbage(&collecte, lstnew_garbage(str));
    }
    else 
        free_list(&collecte);
    return str;
}
