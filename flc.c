#include <stdio.h>

int	ft_vtk(char c)
{
	if (c == '|')
		return (1);
	return (0);
}
int	ft_parq_err(char *str, int *i, char f)
{
	int	op;

	op = 0;
	*i += 1;
	if (f == 'q')
	{
		while ((str[*i]) && op == 0)
		{
			if (str[*i] == '\"')
				op = 1;
			*i += 1;
		}
	}
	else if (f == 's')
	{
		while ((str[*i]) && op == 0)
		{
			if (str[*i] == '\'')
				op = 1;
			*i += 1;
		}
	}
	return (op);
}
void	fun(char *str, int *i)
{
	int	op;

	op = 0;
	while (!ft_vtk(str[*i]) && str[*i])
	{
		while (str[*i] == '\"' || str[*i] == '\'')
		{
			
				if (str[*i] == '\"' )
					op = ft_parq_err(str, i, 'q');
				else if (str[*i] == '\'')
					op = ft_parq_err(str, i, 's');
				if (!str[*i])
					break;
		
		}
		if (!str[*i])
			break;
		(*i)++;
	}
}

 int	number_of_word(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		if (ft_vtk(str[i]))
			i++;
		else if (str[i] == '\"')
			fun(str, &i);
		else 
		{
			wc++;
			fun(str, &i);
			if (!str[i])
				break;
		}
	}
	return (wc);
}

int main ()
{
	printf("%d",number_of_word("ls \"\" \"|\"  |  ab"));
}