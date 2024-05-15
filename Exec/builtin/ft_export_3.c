/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:27:58 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/15 17:56:14 by youmoukh         ###   ########.fr       */
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

char	*test(char *s, int start, int len)
{
	char	*r;
	int		i;
	int		l;

	i = 0;
	if (!s)
		return (NULL);
	if (!len || start >= ft_strlen(s))
		return ("");
	l = ft_strlen(s) - start;
	if (l > len)
		l = len;
	r = (char *)malloc(sizeof(char) * (l + 1));
	if (!r)
		return (NULL);
	while (s[start] && l)
	{
		r[i] = s[start];
		start++;
		i++;
		l--;
	}
	r[i] = '\0';
	return (r);
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
			str = test(s, 0x0, i);
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
	(void) o;
	ft_putstr_fd("export: ", 0x2);
	if (option == 0x0)
		ft_put_err(s, " : not a valid identifier");
	if (option == 0x1)
		ft_put_err(s, ": bad pattern");
	if (option == 0x2)
		ft_put_err(s, " : not valid in this context");
	ex_st_f(0x1, 0x1);
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
