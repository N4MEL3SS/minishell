# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: null <null@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/12 03:37:14 by null              #+#    #+#              #
#    Updated: 2022/06/12 03:37:14 by null             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror

FILES = ft_atoi.c			\
		ft_calloc.c			\
		ft_free_and_null.c	\
		ft_isblank.c		\
		ft_isdigit.c		\
		ft_itoa.c			\
		ft_memset.c			\
		ft_putendl_fd.c		\
		ft_putstr.c			\
		ft_split.c			\
		ft_strchr.c			\
		ft_strcmp.c			\
		ft_strdup.c			\
		ft_strjoin.c		\
		ft_strlen.c			\
		ft_strncmp.c		\
		ft_strtrim.c		\
		ft_substr.c			\
		variadic_strjoin.c

OBJECTS = $(FILES:.c=.o)

GREEN = \033[0;32m


all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)
	@echo "$(GREEN)$(NAME) created.$(RESET)"

$(OBJECTS): $(FILES)
	@$(CC) $(FLAGS) -c $(FILES)

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re 
