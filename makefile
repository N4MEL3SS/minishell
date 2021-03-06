#	PROGRAM_NAMES
NAME = minishell

#	FLAG_COMPILATION
CC = clang
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HEADERS_DIR)

#	HEADERS
HEADERS_DIR = ./includes/
HEADERS_LIST = minishell.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

#	SOURCE
SRCS_DIR = ./source/
SRCS_LIST = main.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

#	OBJECT_FILES
OBJS_DIR = ./objs/
OBJS_DIR_NAME = objs
OBJS_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_LIST))

#	COLORS
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
END = \033[0m

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(GREEN) $(NAME) created. $(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR_NAME)
	@echo "$(GREEN) Object files directory was created. $(RESET)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "$(RED) Object files were deleted. $(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED) $(NAME) was deleted. $(RESET)"
	@rm -rf $(OBJS_DIR_NAME)

re: fclean all

.PHONY: all clean fclean re
