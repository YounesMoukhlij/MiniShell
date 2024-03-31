/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:10:21 by youmoukh          #+#    #+#             */
/*   Updated: 2024/03/31 15:41:33 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <readline/readline.h>

# define sgl '\''
# define dbl '\"'



typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef	struct	s_pipex
{
	int		pid;
	char	*path;
	char	**path_d;
	int		pipe_fd[2];
}	t_pipex;

typedef struct s_minishell
{
	char				**cmd;
    char				**files;
	int					*tab;
    int					len_tab;
	int					fd_in;
	int					fd_out;
	t_pipex				pipex;
	t_env				*envir;
	struct s_minishell	*next;
}	t_minishell;

t_minishell mini;

// YOUNES
void	unset_node(t_minishell *m, char *str);

int			ft_isdigit(int c);
int			ft_isalpha(int c);
void		ft_free_env(t_env **env);
void		ft_free_strings(char **s);
char		*copy_1(char *r, char *s);
char		*copy_2(char *r, char *s);
char		*without_quotes(char *s, int flag);
void 		ft_expand(t_minishell **head, t_env **env);
int			case_1(char *s, int pos);
int			case_2(char *s, int pos);
int			dollar_position(char *s, int pos);
int			ft_isalnum(int c);
void		expander(t_minishell *mini);
char		*allocate_max(t_minishell *mini);
char		*ft_calloc(int num, int size);
char		*ft_substr_executor(char *s, int start, int len);
char		*ft_strjoin_space_executor(char *s1, char *s2, char sep);
void		ft_export(t_minishell *mini);
void		ft_exit(void);
void		ft_unset(t_minishell *mini);
void		ft_cd(t_minishell *mini);
void		ft_echo(t_minishell *mini);
int			is_builtins(t_minishell *mini);
void		ft_env(t_minishell *mini);
void		ft_pwd(t_minishell *mini);

char		*grep_from_env(t_minishell *mini, char *string);
char		*ft_strjoin_executor(char *s1, char *s2);


void    	full_fill_path(t_minishell *mini);


void		ft_execute(t_minishell **head);
void		add_back_executor(t_env **head, t_env *node);
void		add_front_executor(t_env **head, t_env *node);
t_env		*last_node_executor(t_env *lst);
int			lst_size_executor(t_env **head);
t_env		*lstnew_executor(char *key, char *value);
void		check_fd(t_minishell *mini);
char		**ft_split_executor(char *s, char c);
t_env		*full_fill_env(char **env);
int			ft_strlen(char *s);
char		*ft_get_path(t_minishell *mini);
void		ft_putstr_fd_executor(char *s, int fd, int flag_newline);
int			ft_strcmp_flag(char *s1, char *s2, int flag);


t_minishell	*return_data(void);
t_minishell	*return_data_1(void);
t_minishell	*return_data_2(void);

#endif
