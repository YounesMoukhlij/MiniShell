/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:50:34 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/07 17:30:47 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_len(char *s, int mode)
{
	int	len;

	len = 0x0;
	if (mode == 0x0)
	{
		while (s[len] && s[len] != '=')
			len++;
	}
	else if (mode == 0x1)
	{
		while (s[len])
			len++;
	}
	return (len);
}

char	**ft_split_export(char *s)
{
	int		ii;
	int		len;
	char	**r;

	len = 0x0;
	if (s == NULL)
		return (NULL);
	r = malloc(sizeof(char *) * 0x3);
	if (!r)
		return (0);
	len = get_len(s, 0x0);
	ii = len + 0x1;
	r[0x0] = ft_calloc(len + 0x1, 0x1);
	if (!r[0x0])
		return (0x0);
	r[0x0] = copy_1(r[0x0], s);
	len = get_len(&s[len], 0x1);
	r[0x1] = ft_calloc(len + 0x1, 0x1);
	if (!r[0x1])
		return (0x0);
	r[0x1] = copy_2(r[0x1], &s[ii]);
	r[0x2] = 0x0;
	return (r);
}

void	export_error(int option, char *s)
{
	printf("export: ");
	if (option == 0x0)
		printf("not an identifier: ");
	if (option == 0x1)
		printf("bad pattern: ");
	if (option == 0x2)
		printf("not valid in this context: ");
	printf("%s\n", s);
}

void	check_export(char *s)
{
	int	i;
	int	len;

	i = 0x0;
	len = 0x0;
	while ((s[i] >= '0' && s[i] <= '9') && s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			len++;
		if (!s[len])
			export_error(0x0, s);
		if (!ft_isalnum(s[i]))
			export_error(0x1, s);
		i++;
	}
}

int	if_equal(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (s[i] == '=' && s[i + 1] == ' ')
			return (0x0);
		if (s[i] == '=')
			return (0x1);
		i++;
	}
	return (0x0);
}

int	no_value(char *s)
{
	int		i;
	int		j;
	int		flag;
	char	*str;

	i = 0x0;
	j = 0x0;
	flag = 0x0;
	while (s[i])
	{
		if (s[i++] == '=')
		{
			str = ft_substr_executor(s, i + 1, ft_strlen(s));
			while (str[j])
			{
				if (ft_isdigit(str[j++]) && flag == 0x0)
					flag = 0x1;
			}
		}
	}
	if (flag == 0x1)
		return ( 0x0);
	return (0x1);
}

int	is_num(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (ft_isdigit(s[i + 0x1]))
			return (0x1);
		i++;
	}
	return (0x0);
}

int	is_exportable(char *s, t_env *envir)
{
	int	i;

	i = 0x0;
	if (ft_isdigit(s[0x0]))
		return (export_error(0x0, s), 0x0);
	while (s[i])
	{
		if (s[0x0] && s[0x1] == ' ')
			return (0x1);
		if (s[i] == '+' && s[i + 1] == '=')
			return (0x1);
		if (s[i] == '=' && s[i + 0x1] == ' ' && is_num(&s[i + 0x2]))
			return (0x0);
		if (s[i] == '=')
			return (0x1);
		i++;
	}
	if (!ft_strcmp_flag(grep_from_env(envir, s), "(null)", 0x0, 0x0))
		return (0x0);
	return (0x1);
}

int	already_exist(char *s, t_env *envir)
{
	t_env	*head;
	int		i;

	i = 0x0;
	head = envir;
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] == '=' && s[i - 1] == '+')
		return (0x0);
	while (head)
	{
		if (!ft_strcmp_flag(head->key, ft_substr_executor(s, 0x0, i), 0x0, 0x0))
		{
			head->value = &s[++i];
			return (0x1);
		}
		head = head->next;
	}
	return (0x0);
}

char	*special_case(char *s, t_env *envir)
{
	int		i;
	char	*str;
	char 	*you;

	i = 0x0;
	you = NULL;
	while (s[i])
	{
		if (s[i] == '+' && s[i + 1] == '=')
		{
			str = ft_substr_executor(s, 0x0, i);
			you = ft_strjoin_executor(grep_from_env(envir, str), &s[i + 2]);
			unset_node(str, envir);
			break ;
		}
		i++;
	}
	return (you);
}

int	check_special_case(char *s)
{
	int		i;

	i = 0x0;
	while (s[i])
	{
		if (s[i] == '+' && s[i + 1] == '=')
			return (0x1);
		i++;
	}
	return (0x0);
}

char	*ft_key(char *s)
{
	int		i;
	char	*str;

	i = 0x0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '=')
		{
			str = ft_substr_executor(s, 0x0, i);
			return (str);
		}
		i++;
	}
	return (NULL);
}

int	no_equal(char *s)
{
	int	i;

	i = 0x0;
	while (s[i])
	{
		if (s[i++] == '=')
			return (0x0);
	}
	return (0x1);
}

int	ft_export(t_minishell *mini, t_env *envir, int i)
{
	t_env 	**head;
	t_env	*lst;
	char	**p;
	t_env	**print;

	if (!mini->cmd[0x0])
		return (0x0);
	print = full_fill_print(&envir);
	head = &envir;
	if (!mini->cmd[i] || (mini->cmd[i][0] == '$' && !mini->cmd[i + 1]))
		print_export(print);
	else
	{
		while (mini->cmd[i])
		{
			if (is_exportable(mini->cmd[i], envir))
			{
				if (already_exist(mini->cmd[i], envir))
				{
					puts("0");
					break ;
				}
				else if (check_special_case(mini->cmd[i]))
				{
					puts("1");
					lst = lstnew_executor(ft_key(mini->cmd[i]), special_case(mini->cmd[i], envir));
				}
				else if (if_equal(mini->cmd[i]))
				{
					puts("2");
					p = ft_split_export(mini->cmd[i]);
					check_export(p[0x0]);
					lst = lstnew_executor(p[0x0], p[0x1]);
				}
				else if (no_equal(mini->cmd[i]))
				{
					puts("4");
					// print_export(&print);
					lst = lstnew_executor(mini->cmd[i], "");
					printf("[%s=%s]\n", lst->key, lst->value);
					add_back_executor(print, lst);
					break;
				}
				else if (no_value(mini->cmd[i]))
				{
					puts("3");
					lst = lstnew_executor(mini->cmd[i], "");
				}
				add_back_executor(head, lst);
			}
			i++;
		}
	}
	// exit(1);
	return (0x1);
}
