# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 12:51:20 by youmoukh          #+#    #+#              #
#    Updated: 2024/04/16 14:17:00 by youmoukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  Exec/execute/check_fd.c \
	  Exec/signals/signal_handler_1.c \
	  Exec/signals/signal_handler_2.c \
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
	  Exec/builtin/print_export.c \
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
	  Parser/checker.c \
	  Parser/pip_checker.c \
	  Parser/ft_cleantach.c \
	  Parser/ft_cleanshell.c \
	  Parser/help_func/lst_functions.c \
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
	  Parser/help_func/ft_atoi.c \
	  Parser/help_func/ft_putnbr_fd.c \

OBJ = ${SRC:.c=.o}
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
NAME = minishell

all : ${NAME} clean

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
