# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: null <null@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/12 03:37:28 by null              #+#    #+#              #
#    Updated: 2022/06/12 03:37:28 by null             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADERS = -I includes -I libft
CC	= clang
RM	= rm -rf
CFLAGS	= -Wall -Wextra -Werror $(HEADERS)
READLINE = -lreadline
LIBFT = libft
FLAGS = -L $(LIBFT) -lft $(READLINE)

DIR_SRCS = sources
DIR_OBJS = objects
DIRS = builtins				\
		core				\
		exec				\
		hashmap				\
		lexer				\
		parser				\
		variable_expansion

SRC = $(wildcard $(DIR_SRCS)/*.c)
SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
SOURCES = $(foreach dir,$(SOURCEDIRS),$(wildcard $(dir)/*.c))

OBJS = $(subst $(DIR_SRCS), $(DIR_OBJS), $(SOURCES:.c=.o))

GREEN = \033[0;32m
WHITE = \033[0;37m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RED = \033[0;31m
END = \033[0m


$(NAME): $(OBJS)
		@make -s all -C $(LIBFT)
		@-$(CC) $(CFLAGS) $(OBJS) $(FLAGS) $(HEADER) -o $(NAME)
		@echo "$(GREEN)$(NAME) created.$(RESET)"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
		@mkdir -p objects
		@mkdir -p objects/lexer
		@mkdir -p objects/parser
		@mkdir -p objects/builtins
		@mkdir -p objects/exec
		@mkdir -p objects/core
		@mkdir -p objects/hashmap
		@mkdir -p objects/variable_expansion
		@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@
		@echo "$(BLUE)Compiled $(WHITE)"$<"$(BLUE) successfully!$(RESET)"

all: $(NAME)

clean:
		@make -s clean -C $(LIBFT)
		@echo "$(YELLOW)libft cleaned.$(RESET)"
		@$(RM) $(OBJS)
		@$(RM) $(DIR_OBJS)
		@echo "$(YELLOW)$(NAME) cleaned.$(RESET)"

fclean:	clean
		@make -s fclean -C $(LIBFT)
		@echo "$(RED)libft deleted.$(RESET)"
		@$(RM) $(NAME)
		@$(RM) $(DIR_OBJS)
		@echo "$(RED)$(NAME) deleted.$(RESET)"

re:		fclean all

PHONY:	all clean fclean re
