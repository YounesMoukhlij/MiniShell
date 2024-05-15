/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:20:08 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/13 18:21:22 by youmoukh         ###   ########.fr       */
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

char	*ft_strjoin_executor_1(char *s1, char *s2)
{
	char	*r;

	r = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!r)
		return (NULL);
	return (ft_add(r, s1, s2));
}
