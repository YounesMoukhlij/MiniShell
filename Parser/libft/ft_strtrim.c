/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:46:30 by ynassibi          #+#    #+#             */
/*   Updated: 2023/11/09 11:15:44 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fish_str(char const *set, char *tracker, int *len, int i)
{
	while (set[i])
	{
		if (set[i] == *tracker)
		{
			tracker++;
			i = 0;
			*len -= 1;
		}
		else
			i++;
	}
	i = 0;
	while (set[i] && *len >= 0)
	{
		if (set[i] == tracker[*len])
		{
			i = 0;
			*len -= 1;
		}
		else
			i++;
	}
	return (tracker);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			len;
	int			i;
	int			j;
	char		*str;
	char		*tracker;

	if (!s1)
		return (0);
	tracker = (char *) s1;
	j = 0;
	len = (ft_strlen(s1) - 1);
	tracker = fish_str(set, tracker, &len, j);
	str = malloc(sizeof(char) * (len + 2));
	if (!str)
		return (0);
	str[len + 1] = 0;
	i = 0;
	while (i <= len)
	{
		str[i] = tracker[i];
		i++;
	}
	return (str);
}
