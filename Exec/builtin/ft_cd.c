/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:53:32 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/09 15:32:30 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_error(char *s, int i)
{
	ft_putstr_fd_executor("cd: no such file or directory: ", 2, 0);
	if (i == 1)
		ft_putstr_fd_executor(s, 2, 1);
	// exit(1);
}

int	error_case(t_minishell *mini, char *s)
{
	int i;

    i = 0;
	// printf("%s\n", mini->cmd[2]);
	if (mini->cmd[2] != NULL)
		return (ft_put_err("cd:", " too many arguments"), 0x1);
    while (s[i])
    {
        if (s[i] == dbl && s[i + 2] == dbl && s[i + 1] == '~')
            return (print_error("~", 1), 0x1);
        i++;
    }
	return (0x0);
}

t_env	*env_node(t_env **envi, char *keyy)
{
	while ((*envi))
	{
		if (!ft_strcmp_flag((*envi)->key, keyy, 0x0, 0x0))
			return (*envi);
		(*envi) = (*envi)->next;
	}
	return (NULL);
}

//             khra
void	change_dir(t_env *envi, char *path)
{
	t_env	*tmp;
 	char	*new_pwd;
	char	*buff;

	buff = NULL;
	tmp = env_node(&envi, "PWD");
	if (tmp)
	{
		free(tmp->value);
		tmp->value = ft_strdup(path);
	}
	new_pwd = getcwd(buff, 100);
	if (new_pwd)
	{
		tmp = env_node(&envi, "OLDPWD");
		if (tmp)
		{
			free(tmp->value);
			tmp->value = ft_strdup(new_pwd);
		}
	}

}

int	ft_cd(t_minishell *mini, t_env *envir)
{
	int		i;
	char	*path;

	i = 0;
	if (!mini->cmd[0x0])
		return (0x1);
	if (error_case(mini, mini->cmd[1]))
		return (0x0);
	if (!mini->cmd[1] || mini->cmd[1][0] == '~')
	{
		path = grep_from_env(envir, "HOME");
		change_dir(envir, path);
		i = chdir(path);
		if (i == -1)
			return (print_error("No such file or directory", 1), 0x1);
	}
	else if (mini->cmd[1][0] == '-')
	{
		path = grep_from_env(envir, "OLDPWD");
		// change_dir(envir, path);
		i = chdir(path);
		if (i == -1)
			return (print_error("No such file or directory", 1), 0x1);
	}
	else if (mini->cmd[1])
	{
		i = chdir(mini->cmd[1]);
		if (i == -1)
			return (print_error("No such file or directory", 1), 0x1);
	}
	else
	{
		print_error("zsh: bad pattern: ", 1);
		mini->exit_status = 127;
	}
	return (0x0);
}
