/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:53:30 by youmoukh          #+#    #+#             */
/*   Updated: 2024/03/12 12:39:41 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	function_error(char *s)
{
	ft_putstr_fd_executor("no such file or directory : ", 2, 1);
	ft_putstr_fd_executor(s, 2, 1);
}

int	ft_fd_files(t_minishell *mini)
{
	int	i;
	int	fd;

	i = 0;
	while (i < mini->len_tab_flaged)
	{
		printf("i == %d str ==%s flag == %d", i, mini->after_out_or_input[i], mini->flag_input_output[i]);
		printf("\n");
		i++;
	}
	i = 0;
	while (i < mini->len_tab_flaged)
	{
		if (mini->flag_input_output[i] == 1)
		{
			fd = open(mini->after_out_or_input[i], O_RDONLY);
			if (fd == -1)
			{
				// printf("%s\n", mini->after_out_or_input[i]);
				// function_error(mini->after_out_or_input[i]);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	pipex_minishell(t_minishell *mini)
{
	if (ft_fd_files(mini) == 1)
		function_error(NULL);
}
