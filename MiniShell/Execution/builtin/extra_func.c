/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:56:34 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/30 12:59:52 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_old(t_env **env, char **str)
{
	t_env	*t2;
	t_env	*y;

	y = *env;
	t2 = env_node(&y, "OLDPWD");
	if (!t2)
		add_back_executor(env,
			lstnew_executor(ft_strdup_1("OLDPWD"), ft_strdup_1(*str), 0x0));
}

void	create_pwd(t_env **env)
{
	t_env	*t1;
	t_env	*h;
	char	*str;
	char	*buff;

	h = *env;
	buff = 0x0;
	str = getcwd(buff, sizeof(str));
	if (!str)
		return ;
	t1 = env_node(&h, "PWD");
	if (!t1)
		add_back_executor(env,
			lstnew_executor(ft_strdup_1("PWD"), ft_strdup_1(str), 0x0));
	create_old(env, &str);
	free (str);
}

int	check_again(char *s)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (s[0] == '-')
	{
		while (i < ft_strlen(s) - 1)
		{
			if (s[i] == 'n')
				j++;
			i++;
		}
		if (j == ft_strlen(s) - 1)
			return (0x1);
	}
	return (0x0);
}
