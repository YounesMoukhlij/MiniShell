/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_executor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:49:47 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/18 14:41:38 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_substr_executor(char *s, int start, int len)
{
	char	*r;
	int		i;
	int		l;

	i = 0;
	if (!s)
		return (NULL);
	if (!len || start >= ft_strlen(s))
		return (ft_strdup(""));
	l = ft_strlen(s) - start;
	if (l > len)
		l = len;
	r = (char *)ft_malloc(sizeof(char) * (l + 1), 0x1);
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
