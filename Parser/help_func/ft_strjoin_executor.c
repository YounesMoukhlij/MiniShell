/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_executor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:13:29 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/15 11:27:01 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*ft_add(char *r, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		r[i] = s2[j];
		i++;
		j++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_strjoin_executor(char *s1, char *s2)
{
	char	*r;

	r = ft_malloc((ft_strlen(s1) + ft_strlen(s2) + 1), 0x1);
	if (!r)
		return (NULL);
	return (ft_add(r, s1, s2));
}

static char	*ft_space_add(char *r, char *s1, char *s2, char sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	r[i++] = sep;
	while (s2[j])
	{
		r[i] = s2[j];
		i++;
		j++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_strjoin_space_executor(char *s1, char *s2, char sep)
{
	char	*r;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	r = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!r)
		return (NULL);
	return (ft_space_add(r, s1, s2, sep));
}
