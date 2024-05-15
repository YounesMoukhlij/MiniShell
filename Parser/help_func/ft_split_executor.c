/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_executor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:53:54 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/12 17:53:41 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_strlen_word(char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	count_words(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static	char	*ft_create(char *s, char c)
{
	char	*r;
	int		len;
	int		i;

	len = ft_strlen_word(s, c);
	i = 0;
	r = ft_malloc(sizeof(char) * (len + 1), 0x1);
	if (r == NULL)
		return (NULL);
	while (i < len)
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	**ft_split_executor(char *s, char c)
{
	int		i;
	char	**r;

	i = 0;
	if (s == NULL)
		return (NULL);
	r = ft_malloc(sizeof(char *) * ((count_words(s, c) + 1)), 0x1);
	if (!r)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			r[i] = ft_create(s, c);
			if (!r[i])
				return (NULL);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	r[i] = 0;
	return (r);
}
