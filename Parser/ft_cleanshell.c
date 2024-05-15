/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:19:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/11 18:24:17 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cleanshell(t_minishell **node)
{
	t_minishell	*temp;
	t_minishell	*current;

	current = *node;
	while (current)
	{
		temp = current->next;
		ft_cleantach(current->cmdt);
		ft_cleantach(current->afcmd_t);
		ft_cleantach(current->files);
		ft_cleantach(current->cmd);
		// free (current->tmp.r);
		// free (current->tmp.rst);
		// free (current->tmp.expand_str);
		// ft_cleantach (current->tmp.gv_redline);
		// ft_cleantach (current->tmp.s);
		// ft_cleantach (current->path_d);
		// ft_cleantach (current->tmp.bin_cmd_r);
		// ft_cleantach (current->tmp.bin_cmd_res);
		ft_cleantach(current->path_d);
		free (current->path);
		free(current->tab);
		current->len_tab = 0;
		free(current);
		current = temp;
	}
	*node = NULL;
}
