/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:39:04 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/21 14:14:17 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	number_of_words(char *str, int fg)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		if (get_des(str[i], fg))
			i++;
		else
		{
			wc++;
			is_quot_(str, &i);
			while (!get_des(str[i], fg) && str[i])
				i++;
		}
	}
	return (wc);
}

static char	*hooks(char *s1, int *id, int fg)
{
	char	*word;
	size_t	len_word;
	int		i;

	len_word = 0;
	while (get_des(s1[*id], fg))
		(*id)++;
	i = *id;
	ft_get_len(s1, i, &len_word, fg);
	word = ft_malloc(sizeof(char) * (len_word + 1), 0x1);
	if (!word)
		return (NULL);
	return (hudler_ts(s1, word, id, fg));
}

void	fix_arr(char **s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (!ft_strlen(s[i]))
			s[i] = 0x0;
		i++;
	}
}

char	**ft_splits(char *s, char fg)
{
	char	**arr;
	int		id;
	int		wc;
	int		i;

	id = 0;
	i = 0;
	if (!s)
		return (NULL);
	wc = number_of_words(s, fg);
	arr = ft_malloc(sizeof(char *) * (wc + 1), 0x1);
	if (!arr)
		return (NULL);
	while (i < wc)
	{
		arr[i] = hooks(s, &id, fg);
		if (!arr[i])
			return (NULL);
		i++;
	}
	arr[i] = 0;
	fix_arr(arr);
	return (arr);
}
