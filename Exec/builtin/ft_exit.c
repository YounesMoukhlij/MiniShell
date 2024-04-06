/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:52:51 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/02 14:29:48 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_put_err(char *input, char *message, int ret)
{
	ft_putstr_fd("minishell: ", 2);
	if (input != NULL)
		ft_putstr_fd(input, 2);
	ft_putendl_fd(message, 2);
	return (ret);
}

void	ft_check_digit(char	*arg)
{
	char	*error;
	int		estatus;
	int		i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			error = ft_strjoin_executor(arg, ": numeric argument required");
			estatus = ft_put_err("exit: ", error, 255);
			free(error);
			exit(estatus);
		}
		i++;
	}
}

int	ft_check_exit(char *arg)
{
	int			i;
	char		*error;
	long long	estatus;

	i = 0;
	if (arg[i] == '-')
		i++;
	ft_check_digit(arg + i);
	estatus = ft_atoi(arg + i);
	if (estatus < 0)
	{
		error = ft_strjoin_executor(arg, ": numeric argument required");
		estatus = ft_put_err("exit: ", error, 255);
		free(error);
		exit(estatus);
	}
	if (i == 0)
		return (estatus);
	return (estatus * -1);
}

int	ft_exit(t_minishell *mini)
{
	int		i;

	i = 0;
	puts("|sadsad\n");
	if (!(mini->cmd[0x1]))
	{
		if (mini->forked == NO)
			ft_putstr_fd_executor("exit", 1, 1);
		exit(0);
	}
	if (mini->forked == NO)
			ft_putstr_fd_executor("exit", 1, 1);
	// i = ft_check_exit(mini->cmd[1]);
	if (mini->next != NULL)
		return (ft_put_err("exit", ": too many arguments", 1));
	exit(i);
}
