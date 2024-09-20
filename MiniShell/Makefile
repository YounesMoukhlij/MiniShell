# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 12:51:20 by youmoukh          #+#    #+#              #
#    Updated: 2024/09/20 15:51:00 by youmoukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  Parser/tools.c \
	  Parser/tools_1.c\
	  Parser/parcing.c \
	  Parser/parcing_add.c \
	  Parser/parcing_add_2.c \
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
	  Parser/ft_case.c\
	  Execution/builtin/ft_cd.c \
	  Execution/expand/expander.c \
	  Execution/expand/expander_1.c \
	  Execution/execute/check_fd.c \
	  Execution/execute/check_fd_1.c \
	  Execution/execute/check_fd_2.c \
	  Execution/execute/check_fd_3.c \
	  Execution/execute/check_fd_4.c \
	  Execution/execute/check_fd_5.c \
	  Execution/execute/check_fd_6.c \
	  Execution/execute/check_fd_7.c \
	  Execution/execute/check_fd_8.c \
	  Execution/execute/check_fd_9.c \
	  Execution/execute/check_fd_10.c \
	  Execution/builtin/ft_unset.c \
	  Execution/builtin/ft_echo.c \
	  Execution/builtin/ft_echo_1.c \
	  Execution/builtin/ft_cd_1.c \
	  Execution/builtin/ft_pwd.c \
	  Execution/builtin/ft_env.c \
	  Execution/builtin/ft_exit.c \
	  Execution/builtin/ft_export.c \
	  Execution/builtin/ft_export_1.c \
	  Execution/builtin/ft_export_2.c \
	  Execution/builtin/ft_export_3.c \
	  Execution/builtin/ft_export_4.c \
	  Execution/builtin/ft_export_5.c \
	  Execution/env/env_functions.c \
	  Execution/env/env_functions_1.c \
	  Execution/builtin/ft_exit_1.c \
	  Execution/builtin/extra_func.c \
	  Execution/extended_main.c \
	  Execution/extended_main_1.c \
	  Execution/extended_main_2.c \
	  Execution/execute/ft_execute.c \
	  Execution/execute/ft_execute_1.c \
	  Execution/execute/ft_execute_2.c \
	  Execution/execute/ft_execute_3.c \
	  Execution/execute/ft_execute_4.c \
	  Execution/execute/ft_execute_5.c \
	  Execution/execute/ft_execute_6.c \
	  Execution/builtin/print_export.c \
	  Execution/expand/expander_utils.c \
	  Execution/expand/expander_utils_1.c \
	  Execution/expand/expander_utils_2.c \
	  Execution/expand/expander_utils_3.c \
	  Execution/expand/expander_utils_4.c \
	  Execution/expand/expander_utils_5.c \
	  Parser/ft_build_linker.c \
	  Parser/ft_cleantach.c \
	  Parser/ft_cleanshell.c \
	  Parser/getstr_fpromt.c \
	  Parser/ft_check_q.c \
	  Parser/help_func/lst_functions.c \
	  Execution/signals/signal_handler.c \
	  Parser/help_func/allocate_max.c \
	  Parser/help_func/minishell_functions.c \
	  Parser/help_func/ft_split_executor.c \
	  Parser/help_func/ft_strjoin_executor.c \
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
	  Execution/garbage_coll/garbage_coll.c \
	  Execution/garbage_coll/garbage_coll_1.c \

OBJ = ${SRC:.c=.o}
CFLAG = -Wall -Wextra -Werror
NAME = minishell
READLINE_L = $(shell brew --prefix readline)/lib
READLINE_I = $(shell brew --prefix readline)/include
CC = cc

all : ${NAME}

$(NAME): $(OBJ) minishell.h
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
