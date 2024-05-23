/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:50:39 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/23 16:25:55 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	pwd_1(t_minishell *mini, char *pwd)
{
	free (pwd);
	if (mini->size > 1)
		exit (0x0);
}

int	ft_pwd(t_minishell *mini, t_env **head)
{
	char	*pwd;
	char	*buff;
	char	*input;

	buff = NULL;
	pwd = NULL;
	pwd = getcwd(buff, sizeof(pwd));
	if (pwd && strcmp_f(pwd, "/Users/youmoukh/.Trash/", 24, 0x0))
		ft_putstr_fd_executor(pwd, 0x1, 0x1);
	else
	{
		input = grep_from_env(*head, "OLDPWD");
		if (input)
		{
			ft_putstr_fd_executor(input, 0x1, 0x1);
			if (chdir(input) == -1)
				return (pwd_1(mini, pwd), 0);
		}
	}
	free(pwd);
	if (mini->size > 1)
		exit (0x0);
	return (0x1);
}
