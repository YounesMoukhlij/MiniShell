/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:36:15 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/20 19:33:59 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	red_check(char *str, int i, int t)
{
	while (str[i])
	{
		ft_skep(str, &i);
		if (!str[i])
			break;
		if (str[i] == '>')
		{
			while (str[i] == '>' && str[i])
			{
				if (str[i + 1] == '<')
					return (5);
				if (!str[i])
					break;
				i++;
				t++;
			}
			if (!str[i] )
				break;
			if (t >= 3)
				return (1);
			t = 0;
		}
		if (!str[i])
			break;
		i++;
	}
	return (0);
}

int	infile_check(char *str, int i, int t)
{
	while (str[i])
	{
		ft_skep(str, &i);
		if (!str[i])
			break;
		if (str[i] == '<')
		{
			while (str[i] == '<' && str[i])
			{
				if (!str[i])
					break;
				i++;
				t++;
			}
			if (t >= 3)
				return (1);
			t = 0;
		}
		if (!str[i])
			break;
		i++;
	}
	return (0);
}

int	check_expected_token(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_skep(str, &i);
		if (!str[i])
			break;
		if (str[i] == '<' || str[i] == '>')
		{
			i++;
			if (str[i] == '<' || str[i] == '>')
				i++;
			while ((str[i] == 9 || str[i] == 32) && str[i])
				i++;
			if (str[i] == '|')
				return (-1);
			if (str[i] == '<' || str[i] == '>' || !str[i])
				return (7);
		}
		i++;
	}
	return (0);
}

int	check_2(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		ft_skep(s, &i);
		if (!s[i])
			break;
		if (s[i] == '<' && s[i + 1] == '>' && s[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	check_yns(char *i)
{
	if (i[0x0] == SGL && i[ft_strlen(i) - 1] == SGL)
		return (0x1);
	if (i[0x0] == DBL && i[ft_strlen(i) - 1] == DBL)
		return (0x1);
	return (0x0);
}

int	check_1(char *s)
{
	if (s[ft_strlen(s) - 1] == '>'
		|| s[ft_strlen(s) - 1] == '<')
		return (0x1);
	return (0x0);
}

int	ft_checker(char *str)
{
	if (str[0] == '>' || str[0] == '<')
	{
		if (ft_strlen(str) <= 2)
			return (6);
	}
	if (check_1(str))
		return (7);
	if (pip_check(str))
		return (0);
	if (red_check(str, 0x0, 0x0) || check_2(str))
		return (5);
	if (infile_check(str, 0x0, 0x0))
		return (3);
	if (check_expected_token(str))
	{
		if (check_expected_token(str) == -1)
			return (0);
		return (7);
	}
	return (-1);
}
