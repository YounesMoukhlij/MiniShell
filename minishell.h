/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:10:21 by youmoukh          #+#    #+#             */
/*   Updated: 2024/05/29 17:29:38 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <termios.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>

# define SGL '\''
# define DBL '\"'
# define ERR_0 "\033[31m$>\033[0m: syntax error near unexpected token `|'"
# define ERR_1 "\033[31m$>\033[0m: syntax error near unexpected token `>'"
# define ERR_2 "\033[31m$>\033[0m: syntax error near unexpected token `<'"
# define ERR_3 "\033[31m$>\033[0m: syntax error near unexpected token `newline'"
# define ERR_4 "\033[31m$>\033[0m: syntax error near unexpected token `? '"

int							g_sig;

typedef struct s_delete
{
	void				*ptr;
	struct s_delete		*next;
}						t_delete;

typedef struct s_fd
{
	int					fdin;
	int					fdout;
}						t_fd;

typedef struct s_herdoc
{
	char				*s;
	char				*str;
	char				*hdd_f;
}						t_herdoc;

typedef struct s_env
{
	char				*key;
	char				*value;
	int					flag;
	struct s_env		*next;
}						t_env;

typedef struct s_heredoc_context
{
	t_env				*envir;
	char				*s;
	char				*p;
	int					i;
	int					j;
}						t_heredoc_context;

typedef struct s_doc
{
	char				*s;
	char				*str;
	char				*hdd_f;
}						t_doc;

typedef struct s_vars
{
	char				*s;
	char				*r;
	t_env				*envir;
	int					i;
	int					j;
}						t_vars;

typedef struct s_expand
{
	char				*s;
	char				*res;
	char				*p;
	int					c;
}						t_expand;

typedef struct s_big_work
{
	char				*s;
	int					c;
	char				*res;
}						t_big_work;

typedef struct s_tmp
{
	int					lens;
	int					*arr;
	char				**pt;
}						t_tmp;

typedef struct s_minishell
{
	int					check_err;
	int					*t_tab;
	int					parsing_err;
	int					pid_fork;
	char				**cmd;
	int					size;
	char				**cmdt;
	char				**afcmd_t;
	char				**files;
	int					*tab;
	int					len_tab;
	int					fd_in;
	int					fd_out;
	int					t_fd_in;
	int					t_fd_out;
	char				*path;
	char				**path_d;
	t_fd				fd;
	struct s_minishell	*next;
}						t_minishell;


int						check_newline(char *s);
void					check_final(char *s, t_env *env, t_env *tmp);
char					**get_echo_splited(char **s, int len, int p, int j);
int						help_echo(t_minishell *mini);
int						check_fs(char **s, t_minishell *m);
int						check_sf(char **s, t_minishell *m);
char					*ft_key_1(char *s);
int						cm_len(t_minishell *m);
char					**cmd(t_minishell *m);
int						return_cmd(int f);
int						safe_fork(void);
int						ft_open_1(t_minishell *m, char *s, int *f_out, int *i);
int						heredock(t_minishell *mini, t_env *env, int i);
int						syntax(char *promt);
void					ft_puterror(int p);
char					*display_prompt_msg(void);
void					get_fd_back(t_fd fd);
int						check_promt(char *promt);
void					ft_close_fd(t_minishell **head);
void					clean_1(char *s);
void					ft_end(t_minishell *m, char *s, t_fd fd);
void					clean_2(char *s, t_minishell *mini);
int						ft_open_3(t_minishell *m, char *s, int *f_in, int *i);
t_minishell				*last_cmd(t_minishell *lst);
int						ft_open_2(t_minishell *m, char *s, int *f_out, int *i);
void					add_size(t_minishell *m, int full_size);
void					add_back(t_minishell **head, t_minishell *node);
char					*str_caller(char *str);
int						get_des(char c, int fg);
char					*hudler_ts(char *s1, char *word, int *id, int fg);
int						red_check(char *str, int i, int t);
char					*getstr_fpromt(char *str, char *ns, int i, int j);
int						ft_check_q(char *str);
int						check_files_1(t_minishell *m, t_env *env, int i);
int						func(char *p, char *res, int *i, char *s);
t_delete				*lstnew_garbage(void *str);
int						is_file_expanded(char *s);
void					rmv_sgl_quotes_file(t_minishell *mini, char *str,
							int index);
char					*ultra_expand_file(t_env *envir, char *s, int i, int j);
t_delete				*last_cmd_garbage(t_delete *lst);

char					*handle_question_mark(t_vars *vars);

int						process_dollar_signs(t_vars *vars);
void					lstaddfront_garbage(t_delete **head, t_delete *node);

char					*process_string(t_vars *vars);
void					help_1(char **delim, int *flag);
int						heredoc_check(t_minishell *mini, t_env *env,
							char *delim, int flag);
int						already_here(t_env *env, char *s);

char					*herdoc_helper(char *s, t_env *envir, int i, int j);
char					*grep_value_1(char *s);
char					*expand_heredoc(t_env *envir, char *r, int i, int j);
char					*files_no_qts(char *s, int flag, int i, int j);

int						check_f(char *s);
void					func_err(char *s);
int						check(char *s, int f, int flag_0);
int						check_quotes(char *s);
int						check_execute(char *s);
int						big_check(t_minishell *mini);
int						get_double_arr_len(char **s);
int						check_dollar(t_env *env, char *s);
char					*grep_from_env_1(t_env *envir, char *string);
int						check_first(char *s);
char					*ft_substr_executor_1(char *s, int start, int len);
char					*ft_strjoin_executor_1(char *s1, char *s2);
int						ft_strlen(char *str);
char					*ft_calloc_1(int num, int size);
void					signal_handler_child(int sig);
char					*ft_strdup_1(char *s1);
int						is_correct(char *s);
void					*ft_malloc(size_t size, int mode);
char					*ft_itoa_1(int nb);
int						ft_parq_err(char *str, int *i, char f);
void					fun(char *str, int *i);
t_env					*env_node_value(t_env **envi, char *value);
int						ft_isalnum_1(int c);

void					ft_put_err(char *input, char *message);
void					print_func(t_env *env, char *s, int i, int j);
int						get_double_arr_len(char **s);
int						close_fd(t_minishell *mini, int *fd, int flag, int pos);
void					sig_n(int sig_v);
char					*allocate_max_1(t_env *envir);
void					tkdis(char *str, int *i, int *len);
char					*ft_exit_status(char *s, t_env *envir, int i, int j);
int						check_single(char *s);
char					*do_single(char *s, int i, int j);
int						is_empty(char *s);
int						ex_st_f(int status, int mode);
void					handle_fd(t_minishell *mini);
int						get_env_max(t_env *envir);
int						is_builtin_cmd(t_minishell *m, t_env *envir);
int						is_builtin(t_minishell *m);
int						is_file_expanded(char *s);
void					rmv_sgl_quotes_file(t_minishell *mini, char *str,
							int index);
char					*files_no_qts(char *s, int flag, int i, int j);
char					*ultra_expand_file(t_env *envir, char *s, int i, int j);
int						expand_files(t_minishell **mini, t_env *envir, int i);
int						ft_open_others(t_minishell *mini, int i, int f_in,
							int f_out);
int						heredoc_check(t_minishell *mini, t_env *env,
							char *delim, int flag);
char					*hidden_name(void);
int						check_files(t_minishell *m, t_env *env, int i);
int						expanded_content(char *s);
char					*get_str(char *s);
int						ft_helper_heredoc(t_minishell *m, char *s);
int						ft_fd_files(t_minishell *mini, t_env *env);
void					func_err(char *s);
int						already_here(t_env *env, char *s);
int						no_dollar(char *s);
int						get_len(char *s, int mode);
char					**ft_split_export(char *s);
int						no_equal(char *s);
int						if_equal(char *s);
void					check_export(t_minishell *m, char *s);
int						no_value(char *s);
int						extra_check(char *s);
int						is_correct_1(char *s);
int						err_export(char *s);
int						err_export_1(char *s);
char					*no_space(char *s, int i, int j, int flag);
int						ft_is_equal_1(char *s);
int						ft_is_equal(char *s);
int						is_eq_exist(char *s);
int						check_arg_ex(t_minishell *m, int i, int j);
int						err_check(t_minishell *m);
void					rmv_sgl_quotes_cmd(t_minishell *mini, char *str);
void					check_arg(t_minishell *mini, t_env *env);
int						is_expanded(t_minishell *mini, char *s);
t_env					*env_node_v(t_env **envi, char *value);
void					print_cmd(t_minishell *mini);
void					sig_func(void);
int						lst_size(t_minishell **head);
void					export_error(t_minishell *m, int option, char *s,
							char *o);
int						check_cmd(char *s);
void					change_dir(t_env *envi, int flag, char *buff);
int						error_case(t_minishell *mini, char *s);
void					print_error(char *s, int i);
int						is_negative(char *s);
void					error_exit(char *input, char *msg);
void					ft_close(t_minishell *mini, t_env *head, int i);
void					ft_swap_nodes(t_env *tmp);
t_env					*sortlist(t_env **head);
int						check_path(t_env **env, char *s);
t_env					*copy_list(t_env *head);
char					**execv_env(t_env *envir);
int						ex_err(char *s);
int						is_cmd(t_minishell *mini, t_env *envir);
int						exve_err(char *s);
int						is_bin_cmd(t_minishell *mini, t_env *envir, int flag,
							int i);
int						lst_size(t_minishell **head);
int						mini_checks(char *s, int i);
void					export_error(t_minishell *m, int option, char *s,
							char *o);
int						no_equal(char *s);
int						my_check(t_minishell *mini);

int						i_b_n(char *s, t_env *envir, t_minishell *m);

void					i_b_n_1(int f, char *s);

void					i_b_n_2(t_minishell *m, char ***res);

int						ft_fd_files(t_minishell *mini, t_env *env);

void					help_1(char **delim, int *flag);

void					help_her(char *s, t_env *env, int *fd);

int						heredoc_1(char *s, char *delim);

int						heredoc_check(t_minishell *mini, t_env *env,
							char *delim, int flag);
void					h_pp(t_minishell *mini, int t_pipe[2], int f,
							int old_stdin);

void					check_env(t_minishell *mini, t_env *envir);
int						setup_pipes(int t_pipe[2]);

void					h_cp(t_minishell *mini, t_env *envir, int t_pipe[2],
							int f);
void					handle_child_output(t_minishell *mini, int t_pipe[2]);

char					**get_cmd_splited(char **s, int len, int j, int p);

int						uef_1(char *s, int *i);

int						uef_2(char *s, int *i);
int						uef_3(char *p, char *res, int *i, char *s);

char					*u_e_f(t_env *envir, char *s, int i, int j);

void					e_x_2(char **r, int *i, int *j, t_env *env);

int						e_x_1(char *s, int *i, int *c);

int						b_g_1(char *s, int *i, int *c);
void					b_g_3(char **res, t_env *envir, char *s, char **p);

void					b_g(char *s, int *i, int *c);

void					back_up(t_env **ennv, int i, char *pwd, char *buff);
char					*ft_key(char *s);
int						is_num(char *s);
int						check_special_case(char *s);
char					*special_case(char *s, t_env *envir);
int						is_exist(char *s, t_env *envir, char *r);
int						is_exportable(t_minishell *m, char *s, t_env *envir);
int						is_exportable_1(t_minishell *m, char *s, t_env *envir);
void					ft_put_err(char *input, char *message);
t_env					*full_fill_print(t_env **env);
t_env					*copy_list(t_env *head);
void					print_export(t_env **head);
char					*big_work(t_env *envir, char *s, int i, int j);
void					rmv_sgl_quotes_cmd(t_minishell *mini, char *str);
int						cmd_length(t_minishell *m);
void					clear_envir(t_env *head);
void					signal_handler(int sig_v);
void					ft_put_err(char *input, char *message);
int						check_s(char *s);
int						env_check(t_env **eenv, char *s);
void					ft_putendl_fd(char *s, int fd);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					unset_node(char *str, t_env *envir);
int						ft_isdigit(int c);
int						ft_isalpha(int c);
void					ft_free_env(t_env **env);
void					ft_free_strings(char **s);
char					*copy_1(char *r, char *s);
char					*copy_2(char *r, char *s);
char					*no_qts(char *s, int flag, int i, int j);
void					ft_expand(t_minishell **head, t_env **env);
int						case_1(char *s, int pos);
int						case_2(char *s, int pos);
int						dollar_position(char *s, int pos);
int						ft_isalnum(int c);
void					expander(t_minishell **mini, t_env *envir);
char					*allocate_max(t_env *envir);
char					*ft_calloc(int num, int size);
int						big_built_in(t_minishell *mini, t_env *envir, int flag);
char					*ft_substr_executor(char *s, int start, int len);
char					*ft_strjoin_space_executor(char *s1, char *s2,
							char sep);
int						ft_export(t_minishell *mini, t_env *envir, int i,
							int flag);
int						ft_exit(t_minishell *mini);
int						ft_unset(t_minishell *mini, t_env *envir);
int						ft_cd(t_minishell *mini, t_env *envir);
int						ft_echo(t_minishell *mini, t_env *env, int i, int f);
int						is_cmd(t_minishell *mini, t_env *envir);
int						ft_env(t_minishell *mini, t_env *envir);
int						ft_pwd(t_minishell *mini, t_env **head);
t_env					*env_node(t_env **envi, char *keyy);
char					*grep_from_env(t_env *envir, char *string);
char					*ft_strjoin_executor(char *s1, char *s2);
void					full_fill_path(t_minishell *mini, t_env *envir);
char					*add_t(char *p, char *o, t_env *e);
void					ft_execute(t_minishell **head, t_env *envir,
							int flag, int f);
void					add_back_executor(t_env **head, t_env *node);
void					add_front_executor(t_env **head, t_env *node);
t_env					*last_node_executor(t_env *lst);
int						lst_size_executor(t_env **head);
t_env					*lstnew_executor(char *key, char *value, int f);
int						check_fd(t_minishell *mini, t_env *envir);
char					**ft_split_executor(char *s, char c);
t_env					*full_fill_env(char **env, int i, int j);
int						ft_strlen(char *s);
char					*ft_get_path(t_env *envir);
void					ft_putstr_fd_executor(char *s, int fd,
							int flag_newline);
int						strcmp_f(char *s1, char *s2, int flag, int i);
char					*grep_value(char *s);
int						is_digit(char *s);
int						grep(char *s);
t_minishell				*return_data(void);
t_minishell				*return_data_1(void);
t_minishell				*return_data_2(void);
t_minishell				*parcing(char *str);
void					ft_get_len(char *s1, int i, size_t *len_word, int fg);
char					**ft_splitt(char *str);
void					hun_par(char *s1, int *id, int *i, char *word);
int						number_of_word(char *str);
void					is_quot_(char *str, int *i);
void					hund(char *s1, int *id, int *i, char *word);
int						ft_vtk(char c);
int						*ft_arr_tk(char *str, int len);
int						ft_set_tk(char *str);
char					**ft_spliter(char *s);
int						ft_parq(char *str, int *i, char f);
int						hudler_o(char *s1, int i, int *op, size_t *len_word);
char					*hudler_t(char *s1, char *word, int *id);
void					ft_skep(char *str, int *i);
char					**handle_of_ft_malloc(char **tab);
int						get_des(char c, int fg);
t_minishell				*get_link_cmd(char **str, t_minishell *head,
							t_minishell *cmd, int d);
void					shell_at_back(t_minishell **head, t_minishell *node);
void					shell_at_font(t_minishell **head, t_minishell *node);
t_minishell				*last_shell(t_minishell *lst);
t_minishell				*new_shell(char **cmd, char **atcmd, int *arr, int len);
t_minishell				*get_data(t_minishell *cmp, int *arr, int len);
char					**ft_splits(char *s, char fg);
char					**ft_files(char **s);
char					**ft_after_cmd(char **s);
int						ft_strldd(char **str);
int						ft_vtk(char c);
char					**ft_concat(char **arr_1, char **arr_2);
int						*ft_split_arr(int *b_arr, int alen, int *i,
							int *arr_len);
char					*ft_join(char **str);
void					ft_cleantach(char **s);
void					ft_cleanshell(t_minishell **node);
int						ft_checker(char *str);
int						pip_check(char *str);
void					show_me(t_minishell *cmp);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_atoi(char *str);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
char					*ft_strchr(char *s, int c);
int						ft_strlen(char *str);
int						ft_isprint(int c);
char					*ft_strrchr(char *s, int c);
char					*ft_strchr(char *s, int c);
char					*ft_strnstr(char *haystack, char *needle, int len);
int						ft_strncmp(char *s1, char *s2, int n);
char					*ft_strdup(char *s1);
int						ft_strlcpy(char *dst, char *src, int dstsize);
int						ft_strlcat(char *dst, char *src, int dstsize);
void					ft_bzero(void *s, int n);
int						ft_memcmp(void *s1, void *s2, int n);
void					*ft_memcpy(void *dst, void *src, int n);
void					*ft_memset(void *b, int c, int len);
void					*ft_memchr(void *s, int c, int n);
void					*ft_memmove(void *dest, void *src, int n);
char					*ft_strtrim(char *s1, char *set);
char					*ft_substr(char *s, unsigned int start, int len);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_itoa(int nb);
char					**ft_split(char *s, char c);
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmapi(char *s, char (*f)(unsigned int, char));
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);

#endif
