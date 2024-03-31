/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:44:45 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/08 10:09:10 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (s1 && !s2)
		return ((char *)s1);
	else if (!s1 && s2)
		return ((char *)s2);
	else if (!s1 && !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = 0;
	while (s2[i])
		str[len_s1++] = s2[i++];
	str[len_s1] = '\0';
	return (str);
}
