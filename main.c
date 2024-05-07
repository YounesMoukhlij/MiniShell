/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/07 18:40:28 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show(void)
{
	system("leaks minishell");
}

void	ft_puterror(int p)
{	
	if (p != -1)
	{
		if (p == 0)
			ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `|'",
							2);
		if (p == 1)
			ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `>'",
							2);
		if (p == 3 || p == 5)
			ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `<'",
							2);
		if (p == 6)
			ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `newline'",
							2);
		if (p == 7)
			ft_putendl_fd("\033[31m$>\033[0m: syntax error near unexpected token `? '",
							2);
		ex_st_f(258, 0x1);
	}
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

char	*display_prompt_msg(void)
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
	int	k;

	k = 0;
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

int	first_check(char *s)
{
	int	i;

	i = 0x0;
	if (ft_strlen(s) > 1)
	{
		while (s[i])
		{
			if (!ft_isascii(s[i]) || !ft_isprint(s[i]))
				return (0x1);
			i++;
		}
	}
	return (0x0);
}

int ex_st_f(int status, int mode)
{
	static int a;

	if (mode == 1)
		a = status;
	return (a);
}

void	get_fd_back(t_fd fd)
{
	dup2(fd.tmp_fdout, 0x1);
	dup2(fd.tmp_fdin, 0x0);
}

int	main(int ac, char **av, char **env)
{
	int			p;
	char		*str;
	t_minishell	*mini;
	t_env		*envir;
	t_fd		fd;

	if (ac > 0x1 || !strcmp_f(av[0x1], "./minishell", 0x0, 0x0))
		return (0x1);
	envir = full_fill_env(env, 0x0, 0x0);
	sig_func();
	fd.tmp_fdout = dup(1);
	fd.tmp_fdin = dup(0);
	while (1999)
	{
		str = readline("===> ");
		if (!str || first_check(str))
			break ;
		if (is_empty(str))
			continue ;
		p = ft_checker(str);
		add_history(str);
		ft_puterror(p);
		if (p != -1)
		{
			free(str);
			continue ;
		}
		mini = parcing(str);
		if (mini)
			ft_execute(&mini, envir, 0x0);
		get_fd_back(fd);
	}
	return (0x0);
}
