/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_after_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:25:02 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/11 15:39:32 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_word(char **strs, int len)
{
	char	*word;
	int		ii;
	int		j;
	int		i;

	i = 0;
	ii = 0;
	word = malloc(len + 1);
	while (strs[ii])
	{
		j = 0;
		while (strs[ii][j])
			word[i++] = strs[ii][j++];
		if (strs[ii])
			word[i++] = ' ';
		ii++;
	}
	word[i] = 0;
	// ft_cleantach(strs);
	return (word);
}

int	strs_len(char **str)
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

char	*ft_aftercmd(char *s)
{
	int		len;
	int		i;
	int		q;
	char	**strs;

	i = 0;
	q = 0;
	while (s[i] == 9 || s[i] == 32)
		s++;
	is_quot_(s, &q);
	s += q;
	while ((s[i] != 9 && s[i] != 32) && s[i])
		s++;
	strs = ft_splits(s, 0);
	len = strs_len(strs);
	return (get_word(strs, len));
}

char	**ft_after_cmd(char **s)
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
		arr[i] = ft_aftercmd(s[id++]);
		if (!arr[i])
			return (handle_of_malloc(arr));
		i++;
	}
	arr[i] = 0;
	return (arr);
}
