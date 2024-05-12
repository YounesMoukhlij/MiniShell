/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:43:41 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/12 14:00:36 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	len_s;

	len_s = (nmemb * size);
	arr = ft_malloc(len_s);
	if (!arr)
		return (0);
	ft_bzero(arr, len_s);
	return (arr);
}
