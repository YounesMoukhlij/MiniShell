/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:18:32 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/04 17:09:31 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**execv_env(t_env *envir)
{
	char	**str;
	char	*string;
	t_env 	*tmp;
	int		i;

	i = 0;
	tmp = envir;
	str = malloc(sizeof(char *) * lst_size_executor(&tmp) + 1);
	if (!str)
		return (NULL);
	while (tmp)
	{
		string = ft_strjoin_space_executor(tmp->key, tmp->value, '=');
		if (tmp->next)
		 	str[i++] = ft_strdup(string);
		free (string);
		tmp = tmp->next;
	}
	str[i] = 0;
	return (str);
}

int	check_cmd(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0x0);
	while (s[i])
	{
		if (s[i] == ' ')
			return (0x1);
		i++;
	}
	return (0x0);
}

int	check_path(t_env **env, char *s)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!strcmp_f("PATH", tmp->key, 0x0, 0x0))
			return (0x0);
		tmp = tmp->next;
	}
	ft_putstr_fd(s, 0x2);
	ft_putendl_fd(": no such file or directory", 0x2);
	return (0x1);
}

t_env	*env_node_v(t_env **envi, char *value)
{
	while ((*envi))
	{
		if (!strcmp_f((*envi)->value, value, 0x0, 0x0))
			return (*envi);
		(*envi) = (*envi)->next;
	}
	return (NULL);
}

int	ex_err(char *s)
{
	struct stat		buf;

	if (stat(s, &buf) == 0)
	{
		if (buf.st_mode & S_IFDIR)
			return (126);
		else if ((buf.st_mode & S_IXUSR) == 0)
			return (127);
	}
	else
		return (0x0);
	return (0x1);
}
