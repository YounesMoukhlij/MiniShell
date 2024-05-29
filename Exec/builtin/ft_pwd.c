/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:50:39 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/29 13:31:59 by youmoukh         ###   ########.fr       */
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

void	check_final(char *s, t_env *env, t_env *tmp)
{
	static int	i = 0;

	tmp = env;
	while (tmp)
	{
		if (!strcmp_f(s, tmp->key, 0, 0))
			i++;
		tmp = tmp->next;
	}
	tmp = env;
	if (i > 1)
	{
		while (tmp)
		{
			if (!strcmp_f(s, tmp->key, 0, 0))
			{
				if (!tmp->value)
				{
					unset_node(s, env);
					break ;
				}
			}
			tmp = tmp->next;
		}
	}
}
