# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 12:51:20 by youmoukh          #+#    #+#              #
#    Updated: 2024/03/31 16:37:29 by youmoukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  Exec/execute/check_fd.c \
	  Exec/parsing.c \
	  Exec/expand/expander.c \
	  Exec/expand/expander_utils.c \
	  Exec/env/env_functions.c \
	  Exec/builtin/ft_unset.c \
	  Exec/builtin/ft_echo.c \
	  Exec/builtin/ft_cd.c \
	  Exec/builtin/ft_pwd.c \
	  Exec/builtin/ft_env.c \
	  Exec/builtin/ft_exit.c \
	  Exec/builtin/ft_export.c \
	  Exec/execute/ft_execute.c \
	  Parser/parcfun_1.c \
	  Parser/parcfun_2.c \
	  Parser/ft_build_linker.c \
	  Parser/tools.c \
	  Parser/tools_1.c\
	  Parser/tools_2.c\
	  Parser/epur_str.c\
	  Parser/ft_cutdata.c\
	  Parser/ft_ft_vtk.c \
	  Parser/parcing.c \
	  Parser/ft_after_cmd.c\
	  Parser/ft_join.c \
	  Parser/ft_concat.c \
	  Parser/help_func/lst_functions.c \
	  Parser/help_func/allocate_max.c \
	  Parser/help_func/minishell_functions.c \
	  Parser/help_func/ft_split_executor.c \
	  Parser/help_func/ft_strjoin_executor.c \
	#   Parser/help_func/
	#   Parser/help_func/
	#   Parser/help_func/
	#   Parser/help_func/
	#   Parser/help_func/
	#   Parser/help_func/
	  
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
