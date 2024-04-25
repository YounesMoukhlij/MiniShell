/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:53:32 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/25 16:06:47 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_error(char *s, int i)
{
	ft_putstr_fd_executor("cd: no such file or directory: ", 2, 0);
	if (i == 1)
		ft_putstr_fd_executor(s, 2, 1);
}

int	cmd_length(t_minishell *m)
{
	int	i;

	i = 0;
	if (!(m->cmd[i]))
		return (0);
	while (m->cmd[i])
		i++;
	return (i);
}

int	error_case(t_minishell *mini, char *s)
{
	int		i;
	char	*d;

    i = 0;
	d = mini->cmd[0x1];
	if (is_digit(d))
		return (ft_put_err("cd:", " string not in pwd"), 0x1);
	if (cmd_length(mini) > 2)
		return (ft_put_err("cd:", " too many arguments"), 0x1);
    while (s[i])
    {
        if (s[i] == dbl && s[i + 2] == dbl && s[i + 1] == '~' && s[i])
            return (print_error("~", 0x1), 0x1);
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

void	change_dir(t_env *envi, int flag)
{
	t_env	*tmp;
	t_env	*tmp_1;
 	char	*new_pwd;
	char	*buff;

	buff = NULL;
	if (flag == 0x1)
	{
		tmp = env_node(&envi, "PWD");
		tmp_1 = env_node(&envi, "OLDPWD");
		if (tmp_1)
		{
			free(tmp_1->value);
			tmp_1->value = ft_strdup(tmp->value);
		}
	}
	else
	{
		new_pwd = getcwd(buff, 100);
		if (new_pwd)
		{
			tmp = env_node(&envi, "PWD");
			if (tmp)
			{
				free(tmp->value);
				tmp->value = ft_strdup(new_pwd);
			}
		}
	}
}

void	change_dir_1(t_env *e, char *path, int f)
{
	t_env	*tmp;
 	char	*new_pwd;
	char	*buff;

	buff = NULL;
	if (f == 0x1)
	{
		tmp = env_node(&e, "PWD");
		if (tmp)
		{
			free(tmp->value);
			tmp->value = ft_strdup(path);
		}
	}
	else
	{
		new_pwd = getcwd(buff, 100);
		if (new_pwd)
		{
			tmp = env_node(&e, "OLDPWD");
			if (tmp)
			{
				free(tmp->value);
				tmp->value = ft_strdup(new_pwd);
			}
		}
	}
}

int	ft_cd(t_minishell *mini, t_env *envir, int size)
{
	int		i;
	t_env	*tmp;
	char *p;

	i = 0;
	if (!mini->cmd[0x0])
		return (0x1);
	if (error_case(mini, mini->cmd[1]))
		return (0x0);
	if (cmd_length(mini) == 1 || !ft_strcmp_flag(mini->cmd[1], "~", 0x0, 0x0))
	{
		tmp = env_node(&envir, "HOME");
		i = chdir(tmp->value);
		if (i == -1)
			return (print_error(tmp->value, 1), 0x1);
	}
	else if (!ft_strcmp_flag(mini->cmd[0x1], "-", 0x0, 0x0))
	{
		p = grep_from_env(envir, "OLDPWD");
		change_dir_1(envir, p, 0x0);
		i = chdir(p);
		if (i == -1)
			return (print_error(p, 1), 0x1);
		change_dir_1(envir, p, 0x1);
	}
	else if (mini->cmd[1])
	{
		change_dir(envir, 0x1);
		i = chdir(mini->cmd[1]);
		if (i == -1)
			return (print_error(mini->cmd[1], 1), 0x1);
		change_dir(envir, 0x0);
	}
	else
		print_error("zsh: bad pattern: ", 1);
	if (size > 1)
		exit (0x1);
	return (0x1);
}
