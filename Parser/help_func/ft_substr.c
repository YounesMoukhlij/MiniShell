/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:32:34 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/18 14:26:19 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	char		*tracker;

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
	str = (char *) ft_malloc(sizeof(char) * (len + 1), 0x1);
	if (!str)
		return (0);
	i = -1;
	while (tracker[++i] && i < len)
		str[i] = tracker[i];
	str[i] = '\0';
	return (str);
}

char	*ft_substr_env(char *s, int start, int len)
{
	char	*r;
	int		i;
	int		l;

	i = 0;
	if (!s)
		return (NULL);
	if (!len || start >= ft_strlen(s))
		return (ft_strdup_1(""));
	l = ft_strlen(s) - start;
	if (l > len)
		l = len;
	r = malloc(sizeof(char) * (l + 1));
	if (!r)
		return (NULL);
	while (s[start] && l)
	{
		r[i] = s[start];
		start++;
		i++;
		l--;
	}
	r[i] = '\0';
	return (r);
}
