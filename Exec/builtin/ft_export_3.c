/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:27:58 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/04 15:27:59 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_special_case(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (s[i] == '+' && s[i + 1] == '=')
			return (0x1);
		i++;
	}
	return (0x0);
}

char	*ft_key(char *s)
{
	int		i;
	char	*str;

	i = 0x0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '=')
		{
			str = ft_substr_executor(s, 0x0, i);
			return (str);
		}
		i++;
	}
	return (NULL);
}

int	no_equal(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (s[i++] == '=')
			return (0x0);
	}
	return (0x1);
}

void	export_error(t_minishell *m, int option, char *s, char *o)
{
	ft_putstr_fd("export: ", 0x2);
	if (option == 0x0)
		ft_putstr_fd("not an identifier: ", 0x2);
	if (option == 0x1)
		ft_putstr_fd("bad pattern: ", 0x2);
	if (option == 0x2)
		ft_putstr_fd("not valid in this context: ", 0x2);
	ft_putendl_fd(s, 0x2);
	if (o)
		ft_putendl_fd(0, 0x2);
	exit_status = 0x1;
	if (m)
	{
		if (m->size > 1)
			exit(0x1);
	}
}

int	mini_checks(char *s, int i)
{
	while (s[i])
	{
		if (s[i++] == '=')
			return (0x0);
	}
	return (0x1);
}
