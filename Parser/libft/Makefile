SRCS = ft_atoi.c ft_bzero.c ft_calloc.c  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlcpy.c \
		ft_strlen.c ft_tolower.c ft_toupper.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memcmp.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c  ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putnbr_fd.c  ft_putstr_fd.c ft_putendl_fd.c

SRCS_B = ft_lstnew_bonus.c  ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c \
			ft_lstsize_bonus.c ft_lstlast_bonus.c  ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

NAME = libft.a
LIBC = ar -rcs
OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}
CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf
INCS = .

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

.c.o:${NAME}
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	@echo "$(GREEN)------------------------------------------------------$(RESET)"
	@echo "$(GREEN)		ANA KAN9SOD ma3adix 3a ma3a parla "
	@echo "$(GREEN)------------------------------------------------------$(RESET)"
	@${LIBC} ${NAME} ${OBJS}

all: ${NAME}

bonus: all $(OBJS_B)
	@echo "$(BLUE)------------------------------------------------------$(RESET)"
	@echo "$(BLUE)		>> • BONUS√ • $(RESET)"
	@echo "$(BLUE)------------------------------------------------------$(RESET)"
	@$(LIBC) $(NAME) $(OBJS_B)

clean:
	@echo "$(YELLOW)it was cleaned up!$(RESET)"
	@rm -rf $(OBJS) $(OBJS_B)

fclean: clean
	@rm -f $(NAME)
re: fclean all
