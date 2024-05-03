

#include "../../minishell.h"

void	print_error(char *s, int i)
{
	ft_putstr_fd_executor("cd: no such file or directory: ", 2, 0);
	if (i == 1)
		ft_putstr_fd_executor(s, 2, 1);
}

int	cmd_length(t_minishell *m)
{
	int	i;

	i = 0;
	if (!(m->cmd[i]))
		return (0);
	while (m->cmd[i])
		i++;
	return (i);
}

int	error_case(t_minishell *mini, char *s)
{
	int		i;
	char	*d;

	i = 0;
	d = mini->cmd[0x1];
	if (d[0] == '$')
		return (0x0);
	// if (is_digit(d))
	// 	return (ft_put_err("cd:", " string not in pwd"), 0x1);
	if (cmd_length(mini) > 2)
		return (ft_put_err("cd:", " too many arguments"), 0x1);
	while (s[i])
	{
		if (s[i] == DBL && s[i + 2] == DBL && s[i + 1] == '~' && s[i])
			return (print_error("~", 0x1), 0x1);
		i++;
	}
	return (0x0);
}

t_env	*env_node(t_env **envi, char *keyy)
{
	while ((*envi))
	{
		if (!strcmp_f((*envi)->key, keyy, 0x0, 0x0))
			return (*envi);
		(*envi) = (*envi)->next;
	}
	return (NULL);
}

void	change_dir(t_env *envi, int flag)
{
	t_env	*tmp;
	t_env	*tmp_1;
	char	*new_pwd;
	char	*buff;

	buff = NULL;
	if (flag == 0x1)
	{
		tmp = env_node(&envi, "PWD");
		tmp_1 = env_node(&envi, "OLDPWD");
		if (tmp_1)
			tmp_1->value = ft_strdup(tmp->value);
	}
	else
	{
		new_pwd = getcwd(buff, sizeof(new_pwd));
		if (new_pwd)
		{
			tmp = env_node(&envi, "PWD");
			if (tmp)
				tmp->value = ft_strdup(new_pwd);
		}
	}
}
