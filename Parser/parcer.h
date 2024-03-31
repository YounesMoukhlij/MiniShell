/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:32:52 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 15:25:18 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "libft/libft.h"


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
