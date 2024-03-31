/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:26:13 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 16:24:37 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	*y;

	x = (unsigned char *) s1;
	y = (unsigned char *) s2;
	i = 0;
	while ((x[i] && y[i]) && n && (x[i] == y[i]))
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	else
	{
		return (x[i] - y[i]);
	}
}
