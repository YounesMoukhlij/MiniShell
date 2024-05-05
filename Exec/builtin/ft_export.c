/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:50:34 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/05 18:32:24 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	my_check(t_minishell *mini)
{
	if (!mini->cmd[1] || (mini->cmd[1][0] == '$' && !mini->cmd[1 + 1]))
		return (0x1);
	if (!ft_strlen(mini->cmd[0x1]))
		return (0x1);
	return (0x0);
}

int	ft_export(t_minishell *mini, t_env *envir, int i)
{
	t_env	**head;
	t_env	*lst;
	char	**p;

	if (!mini->cmd[0x0])
		return (0x0);
	head = &envir;
	if (my_check(mini))
		print_export(&mini->export);
	else
	{
		while (mini->cmd[i])
		{
			if (is_exportable(mini, mini->cmd[i], envir)
				 && err_export(mini->cmd[i]) && 
				!already_exist(mini->cmd[i], envir) && ft_strlen(mini->cmd[i]))
			{
				if (check_special_case(mini->cmd[i]))
				{
					puts(">1");
					lst = lstnew_executor(ft_key(mini->cmd[i]),
							special_case(mini->cmd[i], envir));
				}
				else if (no_equal(mini->cmd[i]))
				{
					puts(">3");
					lst = lstnew_executor(mini->cmd[i], NULL);
					add_back_executor(&mini->export, lst);
				}
				else if (if_equal(mini->cmd[i]))
				{
					puts(">2");
					p = ft_split_export(mini->cmd[i]);
					check_export(mini, p[0x0]);
					lst = lstnew_executor(p[0x0], p[0x1]);
				}
				else if (no_value(mini->cmd[i]))
				{
					puts(">4");
					lst = lstnew_executor(mini->cmd[i], "");
				}
				add_back_executor(head, lst);
			}
			i++;
		}
	}
	if (mini->size > 1)
		exit(0x0);
	i = 0x0;
	while (mini->cmd[i])
	{
		if (!(is_exportable_1(mini, mini->cmd[i], envir)
				&& err_export_1(mini->cmd[i])))
			return (0x0);
		i++;
	}
	return (0x1);
}
