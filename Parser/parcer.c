/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/30 16:00:22 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"

int	main(int ac, char **av, char **env)
{
	char	*str;

	while (1)
	{
		str = readline("minishell $> ");
		add_history(str);
		parcing(str);
		free (str);
	}
	return (0);
}
