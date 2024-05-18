/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:20:08 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/16 16:41:06 by youmoukh         ###   ########.fr       */
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

	printf("s1 == [%s] && s2 == [%s]\n", s1, s2);
	r = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!r)
		return (NULL);
	printf("r == %p\n", &r);
	return (ft_add(r, s1, s2));
}
