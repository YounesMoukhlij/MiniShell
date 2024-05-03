
#include "../../minishell.h"

int is_existed(char *s)
{
    int i;

    i = 0x0;
    while (s[i])
    {
        if (s[i] == '$' && s[i + 1] == '?')
            return (0x1);
        i++;
    }
    return (0x0);
}

char	*ft_exit_status(char *s)
{
	int		i;
	int		j;
	char	*r;
	int		c;

	r = ft_calloc(200, 1);
	i = 0x0;
	j = 0x0;
	while (s[i])
	{
		while (s[i] == '$' && dollar_position(s, i) && s[i])
		{
			c = 0x0;
			while (s[i] == '$' && s[i])
			{
				i++;
				c++;
			}
			if (c % 2 == 0x0)
				break ;
			if (s[i] == '?')
			{
				r = add_t(r, ft_itoa(exit_status));
				if (ft_strlen(r))
					i += 1;
				j = ft_strlen(r);
			}
			else
			{
				i--;
				break;
			}
		}
		if (!s[i] || i > ft_strlen(s))
			break;
		r[j] = s[i];
		i++;
		j++;
	}
	return (r);
}

int extra_check(char *s)
{
	if (s[0] == '$' &&
		(s[1] == dbl ||
		s[1] == sgl))
		return (0x1);
	return (0x0);
}

char	*big_work(t_env *envir, char *r, int i, int j)
{
	int		c;
	char	*p;
	char	*s;
	char	*res;

	i = 0x0;
	j = 0x0;
	p = allocate_max(envir);
	if (!p)
		return (NULL);
	s = ft_exit_status(r);
	while (s[i])
	{
		while (s[i] == '$' && dollar_position(s, i))
		{
			c = 0x0;
			while (s[i] == '$')
			{
				i++;
				c++;
			}
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
			res = grep_from_env(envir, grep_value(&s[i]));
			p = add_t(p, res);
			if (ft_strlen(p) || !strcmp_f(res, "", 0x0, 0x0))
			i += grep(&s[i]);
			j = ft_strlen(p);
		}
		if (!s[i] || i > ft_strlen(s))
			break ;
		p[j] = s[i];
		i++;
		j++;
	}
	return (p);
}

int	no_dollar(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			return (0x1);
		i++;
	}
	return (0x0);
}
