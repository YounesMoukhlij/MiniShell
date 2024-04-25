/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:47:49 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/25 18:04:16 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_node(t_env *node)
{
	free(node->key);
	free(node->value);
	// free(node);
}

void	unset_node(char *s, t_env *envir)
{
	t_env	*tmp;
	t_env	*pre;
	t_env	**head;

	head = &envir;
	tmp = (*head);
	while (tmp)
	{
		if (!ft_strcmp_flag(tmp->key, s, 0x0, 0x0))
		{
			pre->next = tmp->next;
			pre = tmp->next;
			free_node(tmp);
			break ;
		}
		pre = tmp;
		tmp = tmp->next;
	}
}

// void	unset_error(int option, char *s)
// {
// 	printf("unset: ");
// 	if (option == 0x0)
// 		printf("%s: invalid parameter name");
// 	if (option == 0x1)
// 		printf("bad pattern: ");
// 	if (option == 0x2)
// 		printf("not valid in this context: ");
// 	printf("%s\n", s);
// 	exit(1);
// }

int	check_unset(char *s, t_env *envir)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=' && ft_isalnum(s[i + 1]))
		{
			printf("unset: %s : invalid parameter name", s);
			return (1);
		}
		if (s[i] == '=')
		{
			i += 2;
			printf("unset: %s : not a valid identifier", grep_from_env(envir, &s[i]));
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_unset(t_minishell *mini, t_env *envir, int size)
{
	int	i;

	i = 0x1;
	if (!mini->cmd[0x0])
		return (0x0);
	while (mini->cmd[i])
	{
		if (check_unset(mini->cmd[i], envir))
			return (0x0);
		unset_node(mini->cmd[i], envir);
		i++;
	}
	if (size > 1)
		exit (0x0);
	return (0x1);
}
