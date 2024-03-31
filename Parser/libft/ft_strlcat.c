/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:24:13 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/10 23:17:29 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	com(size_t x, size_t y)
{
	if (x < y)
		return (x);
	return (y);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	length;
	size_t	i;

	i = 0;
	len_src = ft_strlen(src);
	if (!dst && !dstsize)
		return (len_src);
	len_dst = ft_strlen(dst);
	length = len_src + com(len_dst, dstsize);
	while (src[i] && (len_dst + i + 1) < dstsize)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (length);
}
