/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:28:02 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/13 16:19:19 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_len(char *s, int mode)
{
	int	len;

	len = 0x0;
	if (mode == 0x0)
	{
		while (s[len] && s[len] != '=')
			len++;
	}
	else if (mode == 0x1)
	{
		while (s[len])
			len++;
	}
	return (len);
}

char	**ft_split_export(char *s)
{
	int		ii;
	int		len;
	char	**r;

	len = 0x0;
	r = 0x0;
	if (s == NULL)
		return (NULL);
	r = malloc(sizeof(char *) * 0x3);
	if (!r)
		return (0);
	len = get_len(s, 0x0);
	ii = len + 0x1;
	r[0x0] = malloc(len + 0x1);
	if (!r[0x0])
		return (0x0);
	r[0x0] = copy_1(r[0x0], s);
	len = get_len(&s[len], 0x1);
	r[0x1] = malloc(len + 0x1);
	if (!r[0x1])
		return (0x0);
	r[0x1] = copy_2(r[0x1], &s[ii]);
	r[0x2] = 0x0;
	return (r);
}

void	check_export(t_minishell *m, char *s)
{
	int	i;
	int	len;

	i = 0x0;
	len = 0x0;
	while ((s[i] >= '0' && s[i] <= '9') && s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			len++;
		if (!s[len])
			export_error(m, 0x0, s, 0x0);
		if (!ft_isalnum(s[i]))
			export_error(m, 0x1, s, 0x0);
		i++;
	}
}

int	if_equal(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (s[i] == '=')
			return (0x1);
		i++;
	}
	return (0x0);
}

int	no_value(char *s)
{
	int		i;
	int		j;
	int		flag;
	char	*str;

	i = 0x0;
	j = 0x0;
	flag = 0x0;
	while (s[i])
	{
		if (s[i++] == '=')
		{
			str = ft_substr_executor(s, i + 1, ft_strlen(s));
			while (str[j])
			{
				if (ft_isdigit(str[j++]) && flag == 0x0)
					flag = 0x1;
			}
		}
	}
	if (flag == 0x1)
		return (0x0);
	return (0x1);
}

