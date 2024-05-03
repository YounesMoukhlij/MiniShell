/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcfun_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:07:08 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/24 13:27:21 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	case_one(int *arr, char c, int *i, int *j)
{
	if (c == '<')
	{
		arr[*j] = 4;
		*j += 1;
	}
	else
	{
		arr[*j] = 3;
		*j += 1;
	}
	*i += 1;
}

static void	case_two(int *arr, char c, int *i, int *j)
{
	if (c == '>')
	{
		arr[*j] = 2;
		*j += 1;
	}
	else
	{
		arr[*j] = 1;
		*j += 1;
	}
	*i += 1;
}

int	*ft_arr_tk(char *str, int len)
{
	int	*arr;
	int	i;
	int	j;

	arr = malloc((len + 1) * sizeof(int));
	i = 0;
	j = 0;
	while (str[i] && j < len)
	{
		ft_skep (str, &i);
		if (str[i] == '|')
			arr[j++] = 0;
		else if (str[i] == '<')
			case_one (arr, str[i + 1], &i, &j);
		else if (str[i] == '>')
			case_two (arr, str[i + 1], &i, &j);
		if (!str[i])
			break ;
		i++;
	}
	return (arr);
}

void	fun(char *str, int *i)
{
	int	op;

	op = 0;
	while (!ft_vtk(str[*i]) && str[*i])
	{
		if (str[*i] == '\"' || str[*i] == '\'')
		{
			if (!op)
			{
				if (str[*i] == '\"' )
					op = ft_parq(str, i, 'q');
				else if (str[*i] == '\'')
					op = ft_parq(str, i, 's');
				if (!str[*i])
					break;
			}
			op = 0;
		}
		if (!str[*i])
			break;
		(*i)++;
	}
}

int	number_of_word(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		if (ft_vtk(str[i]))
			i++;
		else
		{
			wc++;
			fun(str, &i);
			if (!str[i])
				break;
		}
	}
	return (wc);
}
