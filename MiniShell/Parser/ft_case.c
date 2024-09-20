/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:20:34 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/21 15:27:04 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	case__11(char c, int *i, int *len)
{
	if (c == '<')
	{
		*len += 1;
		*i += 1;
	}
	else
		*len += 1;
}

static void	case__22(char c, int *i, int *len)
{
	if (c == '>')
	{
		*len += 1;
		*i += 1;
	}
	else
		*len += 1;
}

static void	case__1(char c, int *len)
{
	if (c == '<')
		*len += 1;
	else
		*len += 1;
}

static void	case__2(char c, int *len)
{
	if (c == '>')
		*len += 1;
	else
		*len += 1;
}

void	tkdis(char *str, int *i, int *len)
{
	if (str[*i] == '<' && str[*i + 1] == '<')
		case__11(str[*i], i, len);
	else if (str[*i] == '<')
		case__2(str[*i], len);
	else if (str[*i] == '>' && str[*i + 1] == '>')
		case__22(str[*i], i, len);
	else if (str[*i] == '<')
		case__1(str[*i], len);
	else if (str[*i] == '>')
		case__2(str[*i], len);
}
