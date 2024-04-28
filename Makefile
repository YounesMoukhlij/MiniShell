# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 12:51:20 by youmoukh          #+#    #+#              #
#    Updated: 2024/04/25 18:38:07 by youmoukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  Parser/tools.c \
	  Parser/tools_1.c\
	  Parser/parcing.c \
	  Parser/tools_2.c\
	  Parser/epur_str.c\
	  Parser/ft_join.c \
	  Parser/parcfun_2.c \
	  Parser/checker.c \
	  Parser/ft_ft_vtk.c \
	  Parser/parcfun_1.c \
	  Parser/ft_concat.c \
	  Parser/ft_cutdata.c\
	  Parser/pip_checker.c \
	  Exec/builtin/ft_cd.c \
	  Parser/ft_after_cmd.c\
	  Exec/expand/expander.c \
	  Exec/execute/check_fd.c \
	  Exec/builtin/ft_unset.c \
	  Exec/builtin/ft_echo.c \
	  Exec/builtin/ft_cd_1.c \
	  Exec/builtin/ft_pwd.c \
	  Exec/builtin/ft_env.c \
	  Exec/builtin/ft_exit.c \
	  Exec/builtin/ft_export.c \
	  Exec/env/env_functions.c \
	  Exec/builtin/ft_exit_1.c \
	  Exec/execute/ft_execute.c \
	  Exec/builtin/print_export.c \
	  Exec/expand/expander_utils.c \
	  Parser/ft_build_linker.c \
	  Parser/ft_cleantach.c \
	  Parser/ft_cleanshell.c \
	  Parser/help_func/lst_functions.c \
	  Exec/signals/signal_handler_1.c \
	  Parser/help_func/allocate_max.c \
	  Parser/help_func/minishell_functions.c \
	  Parser/help_func/ft_split_executor.c \
	  Parser/help_func/ft_strjoin_executor.c \
	  Exec/builtin/print_export_1.c \
	  Parser/help_func/ft_calloc_executor.c \
	  Parser/help_func/ft_isalnum.c \
	  Parser/help_func/ft_strdup.c \
	  Parser/help_func/ft_isalpha.c \
	  Parser/help_func/ft_substr_executor.c \
	  Parser/help_func/ft_isdigit.c \
	  Parser/help_func/ft_putendl_fd.c \
	  Parser/help_func/ft_putchar_fd.c \
	  Parser/help_func/ft_putstr_fd.c \
	  Parser/help_func/ft_itoa.c \
	  Parser/help_func/ft_atoi.c \

OBJ = ${SRC:.c=.o}
CFLAG = -Wall -Wextra -Werror -g -fsanitize=address
NAME = minishell
READLINE_L = $(shell brew --prefix readline)/lib
READLINE_I = $(shell brew --prefix readline)/include
CC = cc

all : ${NAME} clean

$(NAME): $(OBJ)
	${CC} ${CFLAG} ${OBJ} -L ${READLINE_L}  -o ${NAME} -lreadline

%.o: %.c minishell.h
	${CC} ${CFLAG} -I ${READLINE_I} -c $< -o $@

norm :
	@norminette

clean :
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : clean norm
