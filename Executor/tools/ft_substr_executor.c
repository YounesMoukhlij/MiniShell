/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_executor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:49:47 by youmoukh          #+#    #+#             */
/*   Updated: 2024/03/19 23:33:43 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:29:28 by youmoukh          #+#    #+#             */
/*   Updated: 2023/11/08 18:33:24 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_substr_executor(char *s, int start, int len)
{
	char	*r;
	int		i;
	int		l;

	i = 0;
	if (!s)
		return (NULL);
	if (!len || start >= ft_strlen(s))
		return (strdup(""));
	l = ft_strlen(s) - start;
	if (l > len)
		l = len;
	r = (char *)malloc(sizeof(char) * (l + 1));
	if (!r)
		return (NULL);
	while (s[start] && l)
	{
		r[i] = s[start];
		start++;
		i++;
		l--;
	}
	r[i] = '\0';
	return (r);
}
