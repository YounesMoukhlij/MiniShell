/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/12 15:30:24 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	str = ft_strjoin_executor(cwd, " \033[42m$>\033[0m ");
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
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
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

void	clear_all(t_minishell *m, t_env *env)
{
	ft_cleanshell(&m);
	clear_envir(env);
}

int	main(int ac, char **av, char **env)
{
	char		*str;
	char		*tmp;
	t_minishell	*mini;
	t_env		*envir;
	t_fd		fd;

	int p;
	
	if (ac > 0x1 || !strcmp_f(av[0x1], "./minishell", 0x0, 0x0))
		return (0x1);
	glb_sig = 0;
	envir = full_fill_env(env, 0x0, 0x0);
	fd.tmp_fdout = dup(1);
	fd.tmp_fdin = dup(0);
	sig_func();
	while (1999)
	{
		tmp = display_prompt_msg();
		str = readline(tmp);
		if (!str || first_check(str))
		{
			ft_malloc(0, 0);
			free (str);
			break ;
		}
		if (is_empty(str))
		{
			free(str);
			continue ;
		}
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
		{
			glb_sig = 1;
			ft_execute(&mini, envir, 0x0);
			glb_sig = 0;
		}
		get_fd_back(fd);
		ft_malloc(0, 0);
	}
	clear_envir(envir);
	return (0x0);
}
