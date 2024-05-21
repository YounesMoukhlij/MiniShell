/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:25:09 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/21 15:14:29 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_strdup(char *s1)
{
	char	*copy;
	size_t	s1_len;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	copy = ft_malloc(sizeof(char) * (s1_len + 1), 0x1);
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strdup_1(char *s1)
{
	char	*copy;
	size_t	s1_len;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	copy = malloc(sizeof(char) * (s1_len + 1));
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
