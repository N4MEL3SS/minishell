cmake_minimum_required(VERSION 3.21)
project(minishell_celadia C)

#add_compile_options(-Wall -Wextra -Werror)

set(CMAKE_C_STANDARD 99)
include_directories(includes/)
include_directories(libft/)

set(HEAD includes/minishell.h)

set(SRC_CORE source/core/main.c
		source/core/utils.c
		source/core/utils_lst.c source/core/init.c source/core/debug.c source/core/free.c source/core/env_lst.c source/core/signal.c source/core/minishell.c source/core/parser.c)

set(SRC_BUILTINS)

set(SRC_EXECUTER)

set(SRC_LEXER)

set(LIBFT libft/libft.h
		libft/ft_atoi.c
		libft/ft_bzero.c
		libft/ft_calloc.c
		libft/ft_isalnum.c
		libft/ft_isalpha.c
		libft/ft_isascii.c
		libft/ft_isdigit.c
		libft/ft_isprint.c
		libft/ft_itoa.c
		libft/ft_lstadd_back.c
		libft/ft_lstadd_front.c
		libft/ft_lstclear.c
		libft/ft_lstdelone.c
		libft/ft_lstiter.c
		libft/ft_lstlast.c
		libft/ft_lstmap.c
		libft/ft_lstnew.c
		libft/ft_lstsize.c
		libft/ft_memchr.c
		libft/ft_memcmp.c
		libft/ft_memcpy.c
		libft/ft_memmove.c
		libft/ft_memset.c
		libft/ft_putchar_fd.c
		libft/ft_putendl_fd.c
		libft/ft_putnbr_fd.c
		libft/ft_putstr_fd.c
		libft/ft_split.c
		libft/ft_strchr.c
		libft/ft_strdup.c
		libft/ft_striteri.c
		libft/ft_strjoin.c
		libft/ft_strlcat.c
		libft/ft_strlcpy.c
		libft/ft_strlen.c
		libft/ft_strmapi.c
		libft/ft_strncmp.c
		libft/ft_strnstr.c
		libft/ft_strrchr.c
		libft/ft_strtrim.c
		libft/ft_substr.c
		libft/ft_tolower.c
		libft/ft_toupper.c)

add_executable(minishell ${HEAD} ${SRC_CORE} ${SRC_BUILTINS} ${SRC_EXECUTER} ${SRC_LEXER} ${LIBFT_HEAD} ${LIBFT})
target_link_libraries(minishell readline)
