/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:31:48 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/02 21:37:12 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!haystack && !len)
		return (0);
	if (!*needle)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
			j++;
		if (!needle[j])
			return ((char *) &haystack[i]);
		j = 0;
		i++;
	}
	return (0);
}
