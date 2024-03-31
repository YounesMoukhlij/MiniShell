/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:43:41 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/01 09:54:09 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	len_s;

	len_s = (nmemb * size);
	arr = malloc(len_s);
	if (!arr)
		return (0);
	ft_bzero(arr, len_s);
	return (arr);
}
