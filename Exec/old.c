
char	*check_if_dollar(t_minishell *mini, char *str)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			s = grep_from_env(mini, &str[i + 1]);
			if (s == NULL)
				return ("WITHOUT");
			else
				return (s);
		}
		i++;
	}
	return (NULL);
}
void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
}

t_env	*exist_but_no_value(char *s, t_minishell *m, int i)
{
	char	**cpy_env;

	if (!ft_strcmp_flag(s, "WITHOUT", 0))
	{
		cpy_env = ft_split_executor(m->cmd[i], '=');
		if (!cpy_env)
			return (NULL);
		return (lstnew_executor(cpy_env[0], ""));
	}
	return (NULL);
}

t_env	*exist_with_value(char *s, t_minishell *m, int i)
{
	char	**cpy_env;

	if (!ft_strcmp_flag(s, "WITHOUT", 0))
	{
		cpy_env = ft_split_executor(m->cmd[i], '=');
		if (!cpy_env)
			return (NULL);
		return (lstnew_executor(cpy_env[0], ""));
	}
	if (s)
	{
		cpy_env = ft_split_executor(m->cmd[i], '=');
		if (!cpy_env)
			return (NULL);
		return (lstnew_executor(cpy_env[0], s));
	}
	return (NULL);
}

t_env	*does_not_even_exist(char *s, t_minishell *m, int i, char *str)
{
	char	**cpy_env;
	t_env	*head;
	char	**t;
	int		flag;

	flag = 0;
	head = m->envir;
	t = ft_split_executor(str, '=');
	if (!str)
		return (NULL);
	while (head)
	{
		if (!ft_strcmp_flag(head->key, t[0], ft_strlen(head->key)))
		{
			flag = 1;
			head->value = t[1];
		}
		head = head->next;
	}
 	if (s == NULL && flag == 0)
	{
		cpy_env = ft_split_executor(m->cmd[i], '=');
		if (!cpy_env)
			return (NULL);
		return (lstnew_executor(cpy_env[0], cpy_env[1]));
	}
	return (NULL);
}

void	ft_export(t_minishell *mini)
{
	t_env 	**head;
	t_env	*lst;
	char	**p;
	int		i;

	i = 0x1;
	head = &mini->envir;
	if (!mini->cmd[i])
		ft_env(mini);
	else
	{
		while (mini->cmd[i])
		{
			// if (more_than_dollar(mini) > 1)
			// {
			// 	lst = ft_handle_dollars(mini, mini->cmd[i]);
			// 	add_back_executor(head, lst);
			// 	break ;
			// }
			// cpy = check_if_dollar(mini, mini->cmd[i]);
			// lst = does_not_even_exist(cpy, mini, i, mini->cmd[i]);
			// lst = ft_help(cpy, mini, i ,lst);
			p = ft_split_export(mini->cmd[i]);
			check_export(p[0x0]);
			lst = lstnew_executor(p[0x0], p[0x1]);
			add_back_executor(head, lst);
			i++;
		}
	}
}

int	more_than_dollar(t_minishell *mini)
{
	int		i;
	int		j;
	int		c;
	char	**s;

	i = 1;
	c = 0;
	s = mini->cmd;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == '$')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

t_env	*ft_handle_dollars(t_minishell *mini, char *s)
{
	char	**str;
	int		i;
	char 	*r;
	char	*res;

	(void) mini;
	(void) s;
	i = 0;
	str = ft_split_executor(s, '$');
	while (str[i + 1])
	{
		r = grep_from_env(mini, str[i + 1]);
		res = ft_strjoin_executor(res, r);
		i++;
	}
	return (lstnew_executor(str[0], res));
}

t_env	*ft_help(char *cpy, t_minishell *mini, int i, t_env *lst)
{
	if (!lst)
		return (exist_but_no_value(cpy, mini, i));
	if (!lst)
		return (exist_with_value(cpy, mini, i));
	return (lst);
}
