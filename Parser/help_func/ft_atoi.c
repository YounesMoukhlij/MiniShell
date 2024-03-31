/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:44:37 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 16:24:37 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_fixed(int s)
{
	if (s > 0)
		return (-1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		s;
	size_t	rst;

	s = 1;
	rst = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			s *= -1;
		i++;
	}
	if ((rst > 922337203685477580)
		|| (rst == 922337203685477580 && str[i] - 48 > 7))
		return (ft_fixed(s));
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		rst *= 10;
		rst += str[i] - '0';
		i++;
	}
	return (rst * s);
}
