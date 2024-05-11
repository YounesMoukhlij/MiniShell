/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_coll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:27:59 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/11 20:48:56 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../minishell.h"


# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_delete
{
    void            *ptr;
    struct s_delete    *next;
}    t_delete;


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

void free_2d_array(void **arr, int rows)
{
    if (arr == NULL)
        return;
    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

void free_list(t_delete **head, int size)
{
    t_delete *current = *head;
    t_delete *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}


void    *ft_malloc(size_t size, int mode) 
{
    static t_delete *collecte;
    t_delete *lst;
    void    *str;
    
    
    if (mode == 0x1)
    {
        str = malloc(size);
        if (str == NULL)
            return NULL;
        else
        {
            add_back_garbage(&collecte, lstnew_garbage(str));
            printf("add -> %p\n", &str);
        }
    }
    else 
    {
        // Add the deallocation logic here
        // For simplicity, let's just free the first allocated block
        // if (collecte != NULL) {
        //     lst = collecte;
        //     collecte = collecte->next;
        //     free(lst->ptr);
        //     free(lst);
		// while ((*collecte))
		// {
        // 	free_2d_array((*collecte)->ptr, size);
		// 	(*collecte) = (*collecte)->next;
			
		// }
        free_list(&collecte);
        // }
    }
    
    return str;
}

void    show(void)
{
    system("leaks a.out");
}
int main() 
{
    // Example usage
    atexit(show);
//     char **ptr1 = (char**)ft_malloc(sizeof(char *) * 5, 0x1);
    
//     ptr1[4] = 0;

//    for (int k = 0; k < 5; k++)
//     {
//         ptr1[k] = strdup("11");
//     }
	char *p = ft_malloc(5, 1);

        p = strdup("11");

    // Free memory when no longer needed
    ft_malloc(0, 0x0); // Free memory
}