/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:26:13 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/02 21:21:20 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
