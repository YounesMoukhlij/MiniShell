/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_linker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:16:53 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/18 12:53:15 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_helper(t_minishell *lst)
{
	lst->fd_in = 0;
	lst->fd_out = 1;
	lst->size = 0;
	lst->pid_fork = -1;
	lst->check_err = 0;
	lst->return_exve = 0;
}

t_minishell	*lst_cmd(char *cmd, char *file, int *arr, int len)
{
	t_minishell	*lst;
	char		*s;
	char		**str;

	lst = ft_malloc(sizeof(t_minishell), 0x1);
	if (!lst)
		return (NULL);
	str = ft_splits(file, 1);
	lst->cmdt = ft_splits(cmd, 0);
	lst->afcmd_t = ft_after_cmd(str);
	lst->files = ft_files(str);
	lst->tab = arr;
	lst->len_tab = len;
	s = ft_join(ft_concat(lst->cmdt, ++lst->afcmd_t));
	lst->cmd = ft_splits(s, 0);
	init_helper(lst);
	--lst->afcmd_t;
	lst->next = 0;
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

void	add_back(t_minishell **head, t_minishell *node)
{
	if (!head || !node)
		return ;
	if (*head == NULL)
		lstaddfront(head, node);
	last_cmd(*head)->next = node;
	node->next = NULL;
}

void	add_size(t_minishell *m, int full_size)
{
	t_minishell	*tmp;

	tmp = m;
	while (tmp)
	{
		tmp->size = full_size;
		tmp = tmp->next;
	}
}

t_minishell	*get_link_cmd(char **str, t_minishell *head, t_minishell *cmd, int d)
{
	t_tmp	tmp;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (str[i])
	{
		tmp.lens = ft_set_tk(str[i]);
		tmp.arr = ft_arr_tk(str[i], tmp.lens);
		while (++j < tmp.lens)
			if (tmp.arr[j] <= 0 || tmp.arr[j] > 4)
				tmp.arr[j] = 3;
		tmp.pt = ft_splits(str[i], 1);
		if (i < tmp.lens)
			cmd = lst_cmd(tmp.pt[0], str[i], tmp.arr, tmp.lens);
		else
			cmd = lst_cmd(tmp.pt[0], str[i], tmp.arr, tmp.lens);
		add_back(&head, cmd);
		i++;
	}
	add_size(head, d);
	return (head);
}
