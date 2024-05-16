/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:55 by ynassibi          #+#    #+#             */
/*   Updated: 2024/05/16 18:03:04 by youmoukh         ###   ########.fr       */
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

// char	*display_prompt_msg()
// {
// 	char	*cwd;
// 	char	*str;
// 	char	buff[4096 + 1];

	
// 	cwd = getcwd(buff, 4096);
// 	if (cwd)
// 		str = ft_strjoin_executor(cwd, " \033[42m$>\033[0m ");
// 	// else
// 	// 	str = ft_strdup("minishell -> ");
// 	return (str);
// }

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

int ex_st_f(int status, int mode)
{
	static int saved;

	if (mode == 1)
		saved = status;
	return (saved);
}

void	get_fd_back(t_fd fd)
{
	dup2(fd.tmp_fdout, 0x1);
	dup2(fd.tmp_fdin, 0x0);
}

int	heredock(t_minishell *mini, t_env *env, int i)
{
	t_minishell	*tmp;
	int			fd;

	tmp = mini;
	while (tmp)
	{
		i = -0x1;
		while (++i < tmp->len_tab)
		{
			if (tmp->tab[i] == 0x4)
			{
				fd = heredoc_check(tmp, env, tmp->files[i + 0x1], 0x0);
				if (fd == -0x1)
					return (0x1);
			}
		}
		tmp = tmp->next;
	}
	return (0x0);
}

int	main(int ac, char **av, char **env)
{
	int 		p;
	t_fd		fd;
	t_minishell	*mini;
	char		*promt;
	t_env		*envir;

	if (ac > 0x1 || !strcmp_f(av[0x1], "./minishell", 0x0, 0x0))
		return (0x1);
	glb_sig = 0x0;
	envir = full_fill_env(env, 0x0, 0x0);
	fd.tmp_fdout = dup(0x1);
	fd.tmp_fdin = dup(0x0);
	while (1999)
	{
		sig_func();
		promt = readline("minishell -> ");
		if (!promt )
		{
			ft_malloc(0x0, 0x0);
			free (promt);
			break ;
		}
		if (is_empty(promt))
		{
			free(promt);
			continue ;
		}
		p = ft_checker(promt);
		add_history(promt);
		ft_puterror(p);
		if (p != -1)
		{
			free(promt);
			continue ;
		}
		mini = parcing(promt);
		if (heredock(mini, envir, -0x1))
			continue;
		if (mini)
		{
			glb_sig = 1;
			ft_execute(&mini, envir, 0x0);
			glb_sig = 0x0;
		}
		else
		{
			free (promt);
			ft_cleanshell(&mini);
			continue ;
		}
		get_fd_back(fd);
		ft_malloc(0x0, 0x0);
		free (promt);
	}
	clear_envir(envir);
	return (0x0);
}
