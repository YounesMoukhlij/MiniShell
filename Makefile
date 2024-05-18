# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 12:51:20 by youmoukh          #+#    #+#              #
#    Updated: 2024/05/18 15:00:45 by youmoukh         ###   ########.fr        #
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
	  Parser/ft_after_cmd.c\
	  Exec/builtin/ft_cd.c \
	  Exec/expand/expander.c \
	  Exec/execute/check_fd.c \
	  Exec/execute/check_fd_1.c \
	  Exec/execute/check_fd_2.c \
	  Exec/execute/check_fd_3.c \
	  Exec/execute/check_fd_4.c \
	  Exec/builtin/ft_unset.c \
	  Exec/builtin/ft_echo.c \
	  Exec/builtin/ft_cd_1.c \
	  Exec/builtin/ft_pwd.c \
	  Exec/builtin/ft_env.c \
	  Exec/builtin/ft_exit.c \
	  Exec/builtin/ft_export.c \
	  Exec/builtin/ft_export_1.c \
	  Exec/builtin/ft_export_2.c \
	  Exec/builtin/ft_export_3.c \
	  Exec/builtin/ft_export_4.c \
	  Exec/builtin/ft_export_5.c \
	  Exec/env/env_functions.c \
	  Exec/builtin/ft_exit_1.c \
	  Exec/execute/ft_execute.c \
	  Exec/execute/ft_execute_1.c \
	  Exec/execute/ft_execute_2.c \
	  Exec/execute/ft_execute_3.c \
	  Exec/builtin/print_export.c \
	  Exec/expand/expander_utils.c \
	  Exec/expand/expander_utils_1.c \
	  Exec/expand/expander_utils_2.c \
	  Exec/expand/expander_utils_3.c \
	  Parser/ft_build_linker.c \
	  Parser/ft_cleantach.c \
	  Parser/ft_cleanshell.c \
	  Parser/help_func/lst_functions.c \
	  Exec/signals/signal_handler.c \
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
	  Parser/help_func/ft_strlen.c \
	  Parser/help_func/ft_atoi.c \
	  Parser/help_func/ft_bzero.c \
	  Parser/help_func/ft_isascii.c \
	  Parser/help_func/ft_isprint.c \
	  Exec/garbage_coll/garbage_coll.c \

OBJ = ${SRC:.c=.o}
CFLAG = -Wall -Wextra -Werror -g -fsanitize=address
NAME = minishell
READLINE_L = $(shell brew --prefix readline)/lib
READLINE_I = $(shell brew --prefix readline)/include
CC = cc

all : ${NAME}

$(NAME): $(OBJ) minishell.h Makefile
	@${CC} ${CFLAG} ${OBJ} -L ${READLINE_L} -o ${NAME} -lreadline
	@echo "\033[31mLinking ...\033[0m"
	@echo "\033[33m<.>DONE<.>\033[0m"

%.o: %.c minishell.h
	@${CC} ${CFLAG} -I ${READLINE_I} -c $< -o $@
	@echo "\033[32mCompiling ...\033[0m"

norm :
	@norminette

clean :
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : clean norm
