/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:10:21 by youmoukh          #+#    #+#             */
/*   Updated: 2024/04/07 22:14:53 by youmoukh         ###   ########.fr       */
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
#include <sys/stat.h>
#include <readline/readline.h>

# define sgl '\''
# define dbl '\"'
# define NO 0
# define YES 1


typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_export
{
	char			*key;
	char			*value;
	struct s_export	*next;
}	t_export;

typedef struct s_minishell
{
	char				**cmd;
	char				**cmdt;
	char				**afcmd_t;
    char				**files;
	int					*tab;
	int					exit_status;
    int					len_tab;
	int					fd_in;
	int					fd_out;
	int					heredoc;
	int					forked;
	char				*path;
	char				**path_d;
	struct s_export		*export;
	struct s_minishell	*next;
}	t_minishell;

// YOUNES
t_export		*full_fill_print(t_env **env);
t_export		*copy_list(t_env *head);
void		print_export(t_export **head);


void		clear_envir(t_env *head);
void		signal_handler_one(int sig_v);
void		signal_handler_two(int sig_v);
void		ft_putendl_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		unset_node(char *str, t_env *envir);
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
void		expander(t_minishell **mini, t_env *envir);
char		*allocate_max(t_env *envir);
char		*ft_calloc(int num, int size);
char		*ft_substr_executor(char *s, int start, int len);
char		*ft_strjoin_space_executor(char *s1, char *s2, char sep);
// ******************************************************************************
// *									BUILT IN							 	*
// ******************************************************************************
int			ft_export(t_minishell *mini, t_env *envir, int i);
int			ft_exit(t_minishell *mini, t_env *envir);
int			ft_unset(t_minishell *mini, t_env *envir);
int			ft_cd(t_minishell *mini, t_env *envir);
int			ft_echo(t_minishell *mini);
int			is_cmd(t_minishell *mini, t_env *envir);
int			ft_env(t_env *envir);
int			ft_pwd(t_minishell *mini);

char		*grep_from_env(t_env *envir, char *string);
char		*ft_strjoin_executor(char *s1, char *s2);
void    	full_fill_path(t_minishell *mini, t_env *envir);

void		ft_execute(t_minishell **head, t_env *envir);
void		add_back_executor(t_env **head, t_env *node);
void		add_front_executor(t_env **head, t_env *node);
t_env		*last_node_executor(t_env *lst);
int			lst_size_executor(t_env **head);
t_env		*lstnew_executor(char *key, char *value);
void		check_fd(t_minishell *mini, t_env *envir);
char		**ft_split_executor(char *s, char c);
t_env		*full_fill_env(char **env);
int			ft_strlen(char *s);
char		*ft_get_path(t_env *envir);
void		ft_putstr_fd_executor(char *s, int fd, int flag_newline);
int			ft_strcmp_flag(char *s1, char *s2, int flag, int i);


t_minishell	*return_data(void);
t_minishell	*return_data_1(void);
t_minishell	*return_data_2(void);

// YASSINE

t_minishell	*parcing(char *str);

void	ft_get_len(char *s1,int i, size_t *len_word,int fg);
char	**ft_splitt(char *str);
void	hun_par(char *s1, int *id, int *i, char *word);
int	number_of_word(char *str);
void	is_quot_(char *str,int *i);
void	hund(char *s1, int *id, int *i, char *word);
int	ft_vtk(char c);
int  *ft_arr_tk(char *str, int len);
int ft_set_tk(char *str);
char	**ft_spliter(char *s);
int   ft_parq(char *str, int *i,char f);
void hudler_o(char *s1,int i,int *op,size_t *len_word);
char  *hudler_t(char *s1,char *word, int *id);
void	ft_skep (char *str, int *i);
char	**handle_of_malloc(char **tab);
int	get_des(char c,int fg);
t_minishell	*get_link_cmd(char **str,int *b_arr,int len);
void	shell_at_back(t_minishell **head, t_minishell *node);
void	shell_at_font(t_minishell **head, t_minishell *node);
t_minishell	*last_shell(t_minishell *lst);
t_minishell	*new_shell(char **cmd,char **atcmd ,int *arr,int len );
t_minishell	*get_data(t_minishell *cmp,int *arr,int len);
char	**ft_splits(char *s,char fg);
char	**ft_files(char **s);
char	**ft_after_cmd(char **s);
int	ft_strldd(char **str);
int	ft_vtk(char c);
char	**ft_concat(char **arr_1, char **arr_2);
int	*ft_split_arr(int *b_arr , int alen, int *i, int *arr_len);
char	*ft_join(char **str);


// LIBFT

int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_atoi(char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);

char		*ft_strchr(char *s, int c);
int			ft_strlen(char *str);
int			ft_isprint(int c);
char		*ft_strrchr(char *s, int c);
char		*ft_strchr(char *s, int c);
char		*ft_strnstr(char *haystack, char *needle, int len);
int			ft_strncmp(char *s1, char *s2, int n);
char		*ft_strdup(char *s1);
int			ft_strlcpy(char *dst, char *src, int dstsize);
int			ft_strlcat(char *dst, char *src, int dstsize);
void		ft_bzero(void *s, int n);
int			ft_memcmp(void *s1, void *s2, int n);
void		*ft_memcpy(void *dst, void *src, int n);
void		*ft_memset(void *b, int c, int len);
void		*ft_memchr(void *s, int c, int n);
void		*ft_memmove(void *dest, void *src, int n);
char		*ft_strtrim(char *s1, char *set);
char		*ft_substr(char *s, unsigned int start, int len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_itoa(int nb);
char		**ft_split(char *s, char c);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmapi(char *s, char (*f)(unsigned int, char));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif
