/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:53:32 by youmoukh          #+#    #+#             */
/*   Updated: 2024/03/25 14:44:58 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_error(char *s, int i)
{
	(void) i;
	ft_putstr_fd_executor("cd: no such file or directory: ", 2, 0);
	if (i == 1)
		ft_putstr_fd_executor(s, 2, 1);
	exit(1);
}

void	error_case(char *s)
{
	int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == dbl && s[i + 2] == dbl && s[i + 1] == '~')
            print_error("~", 1);
        i++;
    }
}

void	ft_cd(t_minishell *mini)
{
	int		i;
	char	*path;

	i = 0;
	error_case(mini->cmd[1]);
	if (!mini->cmd[1] || mini->cmd[1][0] == '~')
	{
		path = grep_from_env(mini, "HOME");
		i = chdir(path);
		if (i == -1)
			print_error("dfgdfgdfgdfgdfg", 1);
	}
	else if (mini->cmd[1][0] == '-')
	{
		path = grep_from_env(mini, "OLDPWD");
		i = chdir(path);
		if (i == -1)
			print_error(mini->cmd[1], 1);
	}
	else if (mini->cmd[1])
	{
		i = chdir(mini->cmd[1]);
		if (i == -1)
			print_error(mini->cmd[1], 1);
	}
	else
		print_error("zsh: bad pattern: ", 1);
	if (i != -1)
		ft_pwd(mini);
}
