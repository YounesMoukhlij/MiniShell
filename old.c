char	*herdoc_helper(char *s, t_env *envir, int i, int j)
{
	char	*r;
	int		c;

	r = ft_calloc(200, 1);
	if (!r)
		return (NULL);
	while (s[i])
	{
		while (s[i] == '$' && s[i])
		{
			c = 0x0;
			while (s[i] == '$' && s[i])
				(1) && (i++, c++);
			if (c % 2 == 0x0)
				break ;
			if (s[i] == '?')
			{
				r = add_t(r, ft_itoa_1(ex_st_f(0x0, 0x0)), envir);
				if (!r)
					return (NULL);
				if (ft_strlen(r))
					i += 1;
				j = ft_strlen(r);
			}
			else
			{
				i--;
				break ;
			}
		}
		if (!s[i] || i > ft_strlen(s))
			break ;
		r[j++] = s[i++];
	}
	return (r);
}

// int heredoc_check(t_minishell *mini, t_env *env, char *delim, int flag)
// {
// 	char *hdd_f;
	
// 	hdd_f = hidden_name();
// 	mini->fd_in = open(hdd_f, O_CREAT | O_RDWR | O_APPEND, 0777);
// 	if (mini->fd_in == -1)
// 		return -1;
// 	help_1(&delim, &flag);
// 	signal(SIGINT, sig_n);
// 	while (1)
// 	{
// 		char *s = readline("heredoc> ");
// 		if (!ttyname(0))
// 			return open(ttyname(2), O_RDWR);
// 		if (!s || !strcmp_f(s, delim, 0, 0))
// 			break;
// 		if (flag == 0 && no_dollar(s))
// 			ft_putstr_fd_executor(expand_heredoc(env, s, 0, 0), mini->fd_in, 1);
// 		else
// 			ft_putstr_fd_executor(s, mini->fd_in, 1);
// 		free(s);
// 	}
// 	return ft_helper_heredoc(mini, hdd_f);
// }

// void	big_execution(t_minishell *mini, t_env *envir, int f, int old_stdin)
// {
// 	int	t_pipe[2];
// 	int return_exve;

// 	(void) return_exve;
// 	if (!envir || !(mini)->cmd || !(mini)->cmd[0])
// 		return ;
// 	full_fill_path(mini, envir);
// 	// printf("->>[%s]<<-\n", mini->cmd[1]);
// 	// printf("->>[%s]<<-\n", mini->files[1]);
// 	if (check_fd(mini, envir))
// 		mini->check_err = 0x1;
// 	expander(&mini, envir);
// 	if (pipe(t_pipe) == -1)
// 		return ;
// 	// childs_pipes(t_pipe[0], t_pipe[1], mini, f);
// 	// parent_pipes(t_pipe[0], t_pipe[1], mini, f);
// 	signal(SIGQUIT, signal_handler_child);
// 	mini->pid_fork = fork();
// 	if (!mini->pid_fork)
// 	{
// 		if (mini->check_err == 0x1)
// 		{
// 			ex_st_f(0x0, 0x1);
// 			exit (0x1);
// 		}
// 		if (mini->fd_in != 0)
// 		{
// 			if (dup2(mini->fd_in, 0) == -1)
// 				exit(1);
// 			close(mini->fd_in);
// 		}
// 		if (f == 1)
// 		{
// 			if (mini->fd_out != 1)
// 			{
// 				if (dup2(mini->fd_out, 1) == -1)
// 					exit(1);
// 				close (mini->fd_out);
// 			}
// 			else
// 			{
// 				close (t_pipe[0]);
// 				if (dup2(t_pipe[1], 1) == -1)
// 					exit(1);
// 				close (t_pipe[1]);
// 			}
// 		}
// 		else
// 		{
// 			if (dup2(mini->fd_out, 1) == -1)
// 				exit(1);
// 		}
// 		is_cmd(mini, envir);
// 	}
// 	else
// 	{
// 		close(t_pipe[1]);
// 		if (mini->fd_in != 0)
// 			dup2(t_pipe[0], mini->fd_in);
// 		else
// 			dup2(t_pipe[0], 0);
// 		close(t_pipe[0]);
// 		if (f == 0)
// 		{
// 			dup2(old_stdin, 0x0);
// 			close(old_stdin);
// 		}
// 		else
// 		{
// 			if (mini->fd_in != 0)
// 			{
// 				dup2(mini->fd_in, 0);
// 				close(mini->fd_in);
// 			}
// 		}
// 	}
// }

char	*expand_heredoc(t_env *envir, char *r, int i, int j)
{
	int		c;
	char	*p;
	char	*s;
	char	*res;

	p = allocate_max_1(envir);
	if (!p)
		return (NULL);
	s = herdoc_helper(r, envir, 0x0, 0x0);
	if (!s)
		return (NULL);
	while (s[i])
	{
		while (s[i] == '$')
		{
			c = 0x0;
			while (s[i] == '$')
				(1) && (i++, c++);
			if (c % 2 == 0x0)
				break ;
			if (c == 0x1 && s[i - 0x1] == '$' && !ft_isalnum(s[i]))
			{
				i--;
				break ;
			}
			if (!ft_isalpha(s[i]))
			{
				i++;
				break ;
			}
			res = grep_from_env_1(envir,  grep_value(&s[i]));
			p = add_t(p, res, envir);
			if (!p)
				return (0x0);
			if (ft_strlen(p) || !ft_strlen(res))
				i += grep(&s[i]);
			j = ft_strlen(p);
		}
		if (!s[i] || i > ft_strlen(s))
			break ;
		p[j++] = s[i++];
	}
	return (p);
}