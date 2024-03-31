/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:57:33 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/08 11:30:24 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	s2;

	s1 = (unsigned char *)s;
	s2 = (unsigned char)c;
	while (n)
	{
		if (*s1 == s2)
			return (s1);
		s1++;
		n--;
	}
	return (NULL);
}
