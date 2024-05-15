/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:08:46 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/12 14:17:23 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*zero(char *str)
{
	str = ft_malloc(sizeof(char) * 2, 0x1);
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int		i;

	str = NULL;
	n = nb;
	i = len(n);
	if (nb == 0)
		return (zero(str));
	str = (char *)ft_malloc(i + 1, 1);
	if (!str)
		return (0);
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n /= 10;
		i--;
	}
	return (str);
}
