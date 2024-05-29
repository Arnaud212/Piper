#SETUP
NAME		=	pipex
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	pipex.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

SRCS_FUNC	=	pipex.c lib_utils.c ft_split.c childs.c error.c free.c
SRCS_DIR	=	srcs/
SRCS 		=	$(addprefix $(SRCS_DIR), $(SRCS_FUNC))
OBJ_SRCS	=	$(SRCS:.c=.o)

#COMMANDS
%.o: %.c $(HEADER)
				@$(CC) $(FLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJ_SRCS)
				@$(CC) $(FLAGS) $(OBJ_SRCS) -o $(NAME)
				@echo "$(GREEN)$(NAME) created!$(DEFAULT)"


clean:
				@$(RM) $(OBJ_SRCS)
				@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m