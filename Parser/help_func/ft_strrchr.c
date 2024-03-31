/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:02:07 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 16:24:37 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_strrchr(char *s, int c)
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
