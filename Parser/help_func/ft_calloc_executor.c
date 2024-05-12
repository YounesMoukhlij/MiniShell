/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_executor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:49:08 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/12 14:04:07 by youmoukh         ###   ########.fr       */
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
