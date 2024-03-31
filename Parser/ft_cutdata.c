/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:47:24 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 16:39:27 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_first_word(char *str)
{
	int	i;

	i = 0;
	is_quot_(str, &i);
	while ((str[i] != 9 && str[i] != 32) && str[i])
		i++;
	return (i);
}

int	ft_strldd(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_get_word(char *s)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	while (s[i] == 9 || s[i] == 32)
		s++;
	i = 0;
	len = get_first_word(s);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_files(char **s)
{
	char	**arr;
	int		id;
	int		wc;
	int		i;

	id = 0;
	i = 0;
	if (!s)
		return (NULL);
	wc = ft_strldd(s);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	while (i < wc)
	{
		arr[i] = ft_get_word(s[id++]);
		if (!arr[i])
			return (handle_of_malloc(arr));
		i++;
	}
	arr[i] = 0;
	return (arr);
}
