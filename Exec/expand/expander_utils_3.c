

#include "../../minishell.h"

int	is_expanded(t_minishell *mini, char *s)
{
	int	i;

	(void)mini;
	i = 0x0;
	if (no_dollar(s))
		return (0x1);
	while (s[i])
	{
		if (s[i] == '~')
		{
			if (s[i] == DBL && s[i + 0x2] == DBL && s[i + 0x1] == '~'
				&& ft_strlen(s) > 2)
				return (0x0);
		}
		i++;
	}
	return (0x1);
}

void	rmv_SGL_quotes_cmd(t_minishell *mini, char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0x0;
	j = 0x0;
	if (!str)
		return ;
	s = ft_calloc(ft_strlen(str) + 0x1, 0x1);
	if (!s)
		return ;
	while (str[i])
	{
		if (str[i] == SGL)
			i++;
		s[j] = str[i];
		j++;
		i++;
	}
	mini->cmd[0x0] = s;
}

void	check_arg(t_minishell *mini, t_env *env)
{
	char	*s;
	t_env	*tmp;

	s = mini->cmd[0x1];
	if (!s)
		return ;
	if (s[0x0] == '$')
	{
		tmp = env_node(&env, &s[0x1]);
		if (!tmp)
			mini->cmd[0x1] = NULL;
	}
}
