/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:17:33 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/17 13:53:37 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**handle_of_malloc(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static int	number_of_word(const char *str, char c)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			wc++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (wc);
}
//yassine@nassibi@1337

static char	*hook(const char *s1, int *id, char c)
{
	char	*word;
	size_t	len_word;
	int		i;

	len_word = 0;
	while (s1[*id] == c)
		(*id)++;
	i = *id;
	while (s1[i] && s1[i] != c)
	{
		len_word++;
		i++;
	}
	word = malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s1[*id] && s1[*id] != c)
		word[i++] = s1[(*id)++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		id;
	int		wc;
	int		i;

	id = 0;
	i = 0;
	if (!s)
		return (NULL);
	wc = number_of_word(s, c);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	while (i < wc)
	{
		arr[i] = hook(s, &id, c);
		if (!arr[i])
			return (handle_of_malloc(arr));
		i++;
	}
	arr[i] = 0;
	return (arr);
}
