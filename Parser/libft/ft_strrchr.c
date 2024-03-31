/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:02:07 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/02 11:21:42 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len_s;

	len_s = (ft_strlen(s));
	while (len_s >= 0)
	{
		if (s[len_s] == (char)c)
			return ((char *) &s[len_s]);
		len_s--;
	}
	return (0);
}
