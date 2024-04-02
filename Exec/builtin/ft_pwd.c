/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:50:39 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/02 14:31:04 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_pwd(t_minishell *mini)
{
	char	cwd[1024];
	char	*dir;

	(void) mini;
	dir = getcwd(cwd, sizeof(cwd));
	if (!dir)
	{
		perror("minishell: pwd: ");
		return (0x0);
	}
	printf("%s\n", dir);
	return (0x1);
}




