/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:39:31 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/13 14:53:26 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_put_err(char *input, char *message)
{
	ft_putstr_fd("minishell: ", 0x2);
	if (input)
		ft_putstr_fd(input, 0x2);
	ft_putendl_fd(message, 0x2);
}

void	ft_close(t_minishell *mini, t_env *head, int i)
{
	(void) head;
	(void) mini;
	if (i == 1)
		ft_putstr_fd("exit\n", 2);
	exit(0);
}

void	error_exit(char *input, char *msg)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd("exit: ", 2);
	if (input != NULL)
		ft_putstr_fd(input, 2);
	ft_putendl_fd(msg, 2);
}

int	is_digit(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0x1);
	while (s[i])
	{
		if (s[i] == '+')
			i++;
		if (!ft_isdigit(s[i]))
			return (0x0);
		i++;
	}
	return (0x1);
}

int	is_negative(char *s)
{
	if (s[0x0] == '-' && is_digit(&s[0x1]))
		return (0x1);
	return (0x0);
}
