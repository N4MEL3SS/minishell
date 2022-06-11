# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 17:05:36 by lcouto            #+#    #+#              #
#    Updated: 2021/08/02 19:16:51 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADERS = -I includes -I libft
CC	= clang
RM	= rm -rf
CFLAGS	= -Wall -Wextra -Werror -g $(HEADERS)
TCAPS = -ltermcap
READLINE = -lreadline -lncurses
LIBFT = libft
FLAGS = -L $(LIBFT) -lft $(READLINE)

DIR_SRCS = sources
DIR_OBJS = objects
DIRS = lexer parser builtins exec core hashmap variable_expansion

SRC = $(wildcard $(DIR_SRCS)/*.c)
SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
SOURCES = $(foreach dir,$(SOURCEDIRS),$(wildcard $(dir)/*.c))

OBJS = $(subst $(DIR_SRCS),$(DIR_OBJS),$(SOURCES:.c=.o))

ifeq ($(SANITIZE_A),true)
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer
endif

ifeq ($(SANITIZE_L),true)
	CFLAGS += -fsanitize=leak -fno-omit-frame-pointer
endif


all: $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT)
		@-$(CC) $(CFLAGS) $(OBJS) $(FLAGS) $(HEADER) -o $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
		@mkdir -p objects
		@mkdir -p objects/tokenizer
		@mkdir -p objects/parser
		@mkdir -p objects/builtins
		@mkdir -p objects/exec
		@mkdir -p objects/system
		@mkdir -p objects/hashmap
		@mkdir -p objects/variable_expansion
		@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@
		@echo "Compiled "$<" successfully!"

clean:
		@make clean -C $(LIBFT)
		@$(RM) $(OBJS)
		@$(RM) $(DIR_OBJS)
		@echo "project cleaned."

fclean:	clean
		make fclean -C $(LIBFT)
		@$(RM) $(NAME)
		@$(RM) $(DIR_OBJS)
		@echo "project deleted."

re:		fclean all

install:
	sudo apt-get install libreadline-dev

PHONY:	all clean fclean re install
