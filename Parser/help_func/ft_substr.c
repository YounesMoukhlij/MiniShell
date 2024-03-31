/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:32:34 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 16:24:37 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	char	*tracker;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		str = ft_calloc(1, sizeof(char));
		if (!str)
			return (0);
		return (str);
	}
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	tracker = &s[start];
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = -1;
	while (tracker[++i] && i < len)
		str[i] = tracker[i];
	str[i] = '\0';
	return (str);
}
