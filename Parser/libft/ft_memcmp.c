/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:34:00 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/01 11:16:24 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src_1;
	unsigned char	*src_2;

	src_1 = (unsigned char *)s1;
	src_2 = (unsigned char *)s2;
	while (n && (*src_1 == *src_2))
	{
		src_1++;
		src_2++;
		n--;
	}
	if (!n)
		return (0);
	return (*src_1 - *src_2);
}
