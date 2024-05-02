/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/25 16:26:52 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show()
{
	system("leaks minishell");
}

void	ft_puterror(int p)
{
	if (p == 0)
		ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `|'", 2);
	if (p == 1)
		ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `>'", 2);
	if (p == 3 || p == 5)
		ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `<'", 2);
	if (p == 6)
		ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `newline'", 2);
	if (p == 7)
		ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `? '", 2);
}

int	is_empty(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (0x1);
	while (s[i])
	{
		if (!((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
			return (0x0);
		i++;
	}
	return (0x1);
}

char *display_prompt_msg(void)
{
	char	*cwd;
	char	*str;
	char	buff[4096 + 1];

	cwd = getcwd(buff, 4096);
	str = ft_strjoin_executor(cwd, " \033[32m$>\033[0m ");
	return (str);
}

void	print_cmd(t_minishell *mini)
{
	int k = 0;
	while (mini->cmd[k])
	{
		printf("cmd[%d]=[%s]\n", k, mini->cmd[k]);
		k++;
	}
}

void	sig_func()
{
	signal(SIGINT, signal_handler_one);
	signal(SIGQUIT, signal_handler_one);
	rl_catch_signals = 0;
}


t_minishell	*last_node(t_minishell *lst)
{
	t_minishell	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	main(int ac, char **av, char **env)
{
	char		*str;
	t_minishell	*mini;
	t_env		*envir;
	int		p;

	(void) av;
	(void) mini;
	(void) envir;
	if (ac != 0x1)
		return (0x1);
	envir = full_fill_env(env, 0x0, 0x0);
	exit_status = 0x0;
	sig_func();
	while (1999)
	{
		str = readline(display_prompt_msg());
		if (!str)
			break ;
		if (is_empty(str))
			continue ;
		p = ft_checker(str);
		add_history(str);
		ft_puterror(p);
		if (p != -1)
		{
			free(str);
			continue;;
		}
		mini = parcing(str);
		// print_cmd(mini);
		if (mini)
    		ft_execute(&mini, envir, env);
		free (str);
	}
	return (0x0);
}
