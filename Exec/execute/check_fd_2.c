

#include "../../minishell.h"

void	sig_n(int sig_v)
{
	if (sig_v == SIGINT)
		printf("Herer aaaaa\n");
}
int	heredoc_check(t_minishell *mini, t_env *env, char *delim, int flag)
{
	char	*s;
	char	*p;
	char	*hdd_f;

	hdd_f = hidden_name();
	mini->fd_in = open(hdd_f, O_CREAT | O_RDWR, 0644);
	if (mini->fd_in == -0x1)
		return (-0x1);
	if (expanded_content(delim))
		flag = 0x1;
	p = without_quotes(delim, 0x0);
	while (1999)
	{
		s = readline("heredoc> ");
		if (!s || !strcmp_f(s, p, 0x0, 0x0))
			break ;
		if (flag == 0x0)
			s = big_work(env, s, 0x0, 0x1);
		ft_putstr_fd_executor(s, mini->fd_in, 0x1);
		free(s);
	}
	return (ft_helper_heredoc(mini, hdd_f));
}

int	ft_fd_files(t_minishell *mini, t_env *env)
{
	int	i;
	int	fd;

	i = -0x1;
	fd = 0x0;
	while (++i < mini->len_tab + 0x1)
	{
		if (mini->tab[i] == 0x4)
			fd = heredoc_check(mini, env, mini->files[i + 0x1], 0x0);
		if (mini->tab[i] == 0x3)
		{
			fd = open(mini->files[i + 0x1], O_RDONLY);
			if (fd == -0x1)
			{
				func_err(mini->files[i + 0x1]);
				return (0x1);
			}
		}
	}
	if (fd != 0x0)
		mini->fd_in = fd;
	return (0x0);
}

char	*get_str(char *s)
{
	int	i;
	int	count;

	i = 0x0;
	count = 0x0;
	while (s[i])
	{
		if (s[i] == '$')
			count++;
		i++;
	}
	return (&s[count]);
}

int	check_files(t_minishell *m, t_env *env)
{
	int		i;
	t_env	*tmp;

	i = -0x1;
	if (!m->files)
		return (0x0);
	while (++i < m->len_tab)
	{
		tmp = env_node(&env, get_str(m->files[i + 0x1]));
		if (m->files[i + 0x1][0x0] == '$' && !tmp)
		{
			ft_putstr_fd("Minishell: ", 0x2);
			ft_putstr_fd(m->files[i + 0x1], 0x2);
			ft_putendl_fd(": ambiguous redirect", 0x2);
			return (0x1);
		}
	}
	return (0x0);
}

int	already_here(t_env *env, char *s)
{
	t_env	*tmp;

	if (!s)
		return (0x1);
	tmp = env_node(&env, get_str(s));
	if (tmp)
		return (0x0);
	return (0x1);
}
