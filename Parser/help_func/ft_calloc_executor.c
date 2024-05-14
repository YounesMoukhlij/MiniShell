/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_executor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:49:08 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/13 18:04:35 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_calloc(int num, int size)
{
	int		i;
	int		n;
	char	*r;

	i = 0;
	n = num * size;
	r = ft_malloc(n, 0x1);
	if (!r)
		return (NULL);
	while (i < n)
	{
		r[i] = '\0';
		i++;
	}
	return (r);
}

char	*ft_calloc_1(int num, int size)
{
	int		i;
	int		n;
	char	*r;

	i = 0;
	n = num * size;
	r = malloc(n);
	if (!r)
		return (NULL);
	while (i < n)
	{
		r[i] = '\0';
		i++;
	}
	return (r);
}
