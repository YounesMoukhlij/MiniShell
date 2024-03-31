/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_linker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:16:53 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 15:25:18 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parcer.h"
#include <stdio.h>

t_minishell	*lst_cmd(char *cmd, char *file, int *arr, int len)
{
	t_minishell	*lst;

	lst = malloc(sizeof(t_minishell));
	if (!lst)
		return (NULL);
	lst->cmdt = ft_splits(cmd, 0);
	lst->afcmd_t = ft_after_cmd(ft_splits(file, 1));
	lst->files = ft_files(ft_splits(file, 1));
	lst->tab = arr;
	lst->len_tab = len;
	lst->cmd = ft_splits(ft_join(\
	ft_concat(lst->cmdt,++lst->afcmd_t )),0);
	lst->next = 0x0;
	return (lst);
}

t_minishell	*last_cmd(t_minishell *lst)
{
	t_minishell	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	lstaddfront(t_minishell **head, t_minishell *node)
{
	node->next = (*head);
	(*head) = node;
}

void	add_back_executor(t_minishell **head, t_minishell *node)
{
	if (!head || !node)
		return ;
	if (*head == NULL)
		lstaddfront(head, node);
	last_cmd(*head)->next = node;
	node->next = NULL;
}

t_minishell	*get_link_cmd(char **str, int *b_arr, int len)
{
	t_minishell	*head;
	t_minishell	*cmd;
	int			lens;
	int			i;
	int			*arr;

	head = 0x0;
	i = 0;
	while (str[i])
	{
		lens = ft_set_tk(str[i]);
		arr = ft_arr_tk(str[i], len);
		if (i < len)
			cmd = lst_cmd(ft_splits(str[i], 1)[0], str[i], arr, lens);
		else
			cmd = lst_cmd(ft_splits(str[i], 1)[0], str[i], arr, lens);
		add_back_executor(&head, cmd);
		i++;
	}
	return (head);
}
