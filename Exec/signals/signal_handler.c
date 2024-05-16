/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:50:58 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/15 21:35:03 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	signal_handler(int sig_v)
{
	if (glb_sig == 0)
	{
		if (sig_v == SIGINT)
		{
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			ex_st_f(0x1, 0x1);
		}
	}
}

void	signal_handler_child(int sig)
{
	if (glb_sig == 1)
	{
		if (sig == SIGQUIT)
			ft_putstr_fd("Quit: 3\n", 0x1);
	}
}
