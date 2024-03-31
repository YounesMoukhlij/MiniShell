/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:33:15 by ynassibi          #+#    #+#             */
/*   Updated: 2024/03/31 16:22:55 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_atoi(char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_calloc(int nmemb, int size);
char		*strchr(char *s, int c);
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
