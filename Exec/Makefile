# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 12:51:20 by youmoukh          #+#    #+#              #
#    Updated: 2024/03/31 01:09:04 by youmoukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  execute/check_fd.c \
	  parsing.c \
	  expand/expander.c \
	  expand/expander_utils.c \
	  tools/ft_substr_executor.c \
	  tools/ft_calloc_executor.c \
	  env/env_functions.c \
	  tools/lst_functions.c \
	  tools/allocate_max.c \
	  tools/minishell_functions.c \
	  tools/ft_split_executor.c \
	  tools/ft_strjoin_executor.c \
	  builtin/ft_unset.c \
	  builtin/ft_echo.c \
	  builtin/ft_cd.c \
	  builtin/ft_pwd.c \
	  builtin/ft_env.c \
	  builtin/ft_exit.c \
	  builtin/ft_export.c \
	  execute/ft_execute.c \

OBJ = ${SRC:.c=.o}
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
NAME = minishell

all : ${NAME} clean play

play :
	@./minishell

%.o : %.c ../minishell.h
	@cc ${CFLAGS} -c $< -o $@

${NAME} : ${OBJ}
	@cc ${CFLAGS} ${OBJ} -lreadline -o $@

norm :
	@norminette

clean :
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : all fclean

.PHONY : clean norm
