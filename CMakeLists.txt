cmake_minimum_required(VERSION 3.23)
project(minishell_paulahemsi_cmake C)

set(CMAKE_C_STANDARD 99)
add_compile_options(-Wall -Wextra -Werror)

include_directories(includes/)
include_directories(libft/)

set(BUILTINS sources/builtins/2d_array_utils.c
		sources/builtins/cd.c
		sources/builtins/echo.c
		sources/builtins/env_to_hashmap.c
		sources/builtins/exit.c
		sources/builtins/exit_minishell.c
		sources/builtins/export.c
		sources/builtins/hashmap_to_env.c
		sources/builtins/hashmap_to_env_with_quotes.c
		sources/builtins/print_environment.c
		sources/builtins/pwd.c
		sources/builtins/quick_sort_2d_array.c
		sources/builtins/set_local_variable.c
		sources/builtins/unset.c)

set(EXEC sources/exec/execute_command.c
		sources/exec/path.c)

set(HASPMAP sources/hashmap/hash.c
		sources/hashmap/hashmap_create_pair.c
		sources/hashmap/hashmap_create_table.c
		sources/hashmap/hashmap_delete.c
		sources/hashmap/hashmap_free_pair.c
		sources/hashmap/hashmap_free_table.c
		sources/hashmap/hashmap_handle_collision.c
		sources/hashmap/hashmap_insert.c
		sources/hashmap/hashmap_print_table.c
		sources/hashmap/hashmap_search.c)

set(PARSER sources/parser/command_parser.c
		sources/parser/create_command.c
		sources/parser/here_document.c
		sources/parser/process_parser.c
		sources/parser/redirect_parser.c)

set(CORE includes/minishell.h
		sources/core/message.c
		sources/core/here_doc_signal.c
		sources/core/minishell.c
		sources/core/prompt.c
		sources/core/signals.c sources/core/env_dup.c)

set(LEXER sources/lexer/add_token.c
		sources/lexer/check_and_insert_spaces.c
		sources/lexer/check_blanks_around.c
		sources/lexer/define_end_quote.c
		sources/lexer/define_type.c
		sources/lexer/handle_quotes.c
		sources/lexer/insert_spaces.c
		sources/lexer/quotes.c
		sources/lexer/special_case.c
		sources/lexer/split_token.c
		sources/lexer/token_lst.c
		sources/lexer/tokenizer.c)

set(VAR_EXP sources/variable_expansion/expand.c
		sources/variable_expansion/handle_var_single_quote.c
		sources/variable_expansion/variables_expansion.c
		sources/variable_expansion/variables_utils.c)


set(LIBFT libft/ft_atoi.c
		libft/ft_calloc.c
		libft/ft_free_and_null.c
		libft/ft_isblank.c
		libft/ft_isdigit.c
		libft/ft_itoa.c
		libft/ft_memset.c
		libft/ft_putendl_fd.c
		libft/ft_putstr.c
		libft/ft_split.c
		libft/ft_strchr.c
		libft/ft_strcmp.c
		libft/ft_strdup.c
		libft/ft_strjoin.c
		libft/ft_strlen.c
		libft/ft_strncmp.c
		libft/ft_strtrim.c
		libft/ft_substr.c
		libft/variadic_strjoin.c)

add_executable(minishell ${CORE} ${BUILTINS} ${EXEC} ${HASPMAP} ${LEXER} ${PARSER} ${VAR_EXP} ${LIBFT})
target_link_libraries(minishell readline)
target_link_libraries(minishell ncurses)
target_link_libraries(minishell termcap)
