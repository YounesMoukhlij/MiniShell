/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:00:46 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 15:35:56 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parcer.h"

int	calculateRows(char** arr) {
	int	rows;

	rows = 0;
	while (arr[rows])
		rows++;
	return rows;
}

int	calculateCols(char** arr) {
	if (!arr || !arr[0])
		return 0;
	return (ft_strlen(arr[0]));
}

char**	ft_concat(char** arr1, char** arr2) {
	int	rows1;
	int	rows2;
	char	**concatenated;
	int	i;
	int	j;
	i = 0;
	rows1 = calculateRows(arr1);
	rows2 = calculateRows(arr2);
	concatenated = malloc((rows1 + rows2 + 1) * sizeof(char**));
	while (i < rows1)
	{
		concatenated[i] = ft_strdup(arr1[i]) ;
		i++;
	}
	j = 0;
	while (j < rows2)
	{
		concatenated[i] = ft_strdup(arr2[j]);
		j++;
		i++;
	}
	concatenated [rows1 + rows2] = NULL;

	return	(concatenated);
}

