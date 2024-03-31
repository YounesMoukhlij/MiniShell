/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:31:26 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 15:14:44 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"

static int	strs_lens(char **str)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	j = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		len += j;
		i++;
	}
	return (len + i);
}

char *ft_collection (char **str,char *st)
{
	int	i;
	int	ii;
	int	j;

	i = 0;
	ii = 0;
	while (str[i])
	{
		j = 0;
		while(str[i][j])
			st[ii++] = str[i][j++];
		if (str[i])
			st[ii++] = ' ';
		i++;
	}
	st[ii] = 0;
	return (st);
}
char	*ft_join(char **str)
{
	char	*st;
	int	len;


	if (!(*str))
		return (NULL);
	len = strs_lens(str);
	st = malloc(len + 1);
	return (ft_collection(str, st));
}
