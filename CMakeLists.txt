cmake_minimum_required(VERSION 3.23)
project(minishell_paulahemsi_cmake C)

set(CMAKE_C_STANDARD 99)
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

set(CORE sources/core/error.c
		sources/core/here_doc_signal.c
		sources/core/minishell.c
		sources/core/prompt.c
		sources/core/signals.c)

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


set(FT_PRINTF libft/ft_printf/flags_parser.c
		libft/ft_printf/ft_printf.c
		libft/ft_printf/parsing_identifiers/print_char.c
		libft/ft_printf/parsing_identifiers/print_hex.c
		libft/ft_printf/parsing_identifiers/print_integer.c
		libft/ft_printf/parsing_identifiers/print_string.c)

set(LIBFT libft/ft_add.c
		libft/ft_atoi.c
		libft/ft_bzero.c
		libft/ft_calloc.c
		libft/ft_countdigit.c
		libft/ft_dlstadd_back.c
		libft/ft_dlstadd_front.c
		libft/ft_dlstclear.c
		libft/ft_dlstdelone.c
		libft/ft_dlstiter.c
		libft/ft_dlstlast.c
		libft/ft_dlstmap.c
		libft/ft_dlstnew.c
		libft/ft_dlstsize.c
		libft/ft_free_and_null.c
		libft/ft_isalnum.c
		libft/ft_isalpha.c
		libft/ft_isascii.c
		libft/ft_isblank.c
		libft/ft_isdigit.c
		libft/ft_isnegative.c
		libft/ft_isprint.c
		libft/ft_isspace.c
		libft/ft_isupper.c
		libft/ft_isxdigit.c
		libft/ft_itoa.c
		libft/ft_itoa_hex.c
		libft/ft_lstadd_back.c
		libft/ft_lstadd_front.c
		libft/ft_lstclear.c
		libft/ft_lstdelone.c
		libft/ft_lstiter.c
		libft/ft_lstlast.c
		libft/ft_lstmap.c
		libft/ft_lstnew.c
		libft/ft_lstsize.c
		libft/ft_memccpy.c
		libft/ft_memchr.c
		libft/ft_memcmp.c
		libft/ft_memcpy.c
		libft/ft_memmove.c
		libft/ft_memset.c
		libft/ft_numlen.c
		libft/ft_putchar.c
		libft/ft_putchar_fd.c
		libft/ft_putendl.c
		libft/ft_putendl_fd.c
		libft/ft_putnbr.c
		libft/ft_putnbr_fd.c
		libft/ft_putnbr_unsigned.c
		libft/ft_putstr.c
		libft/ft_putstr_fd.c
		libft/ft_split.c
		libft/ft_strchr.c
		libft/ft_strclr.c
		libft/ft_strcmp.c
		libft/ft_strdup.c
		libft/ft_strequ.c
		libft/ft_strjoin.c
		libft/ft_strlcat.c
		libft/ft_strlcpy.c
		libft/ft_strlen.c
		libft/ft_strmapi.c
		libft/ft_strncmp.c
		libft/ft_strnequ.c
		libft/ft_strnstr.c
		libft/ft_strrchr.c
		libft/ft_strtrim.c
		libft/ft_substr.c
		libft/ft_tolower.c
		libft/ft_toupper.c
		libft/get_next_line.c
		libft/get_next_line_multfd.c
		libft/variadic_strjoin.c)

add_executable(minishell ${CORE} ${BUILTINS} ${EXEC} ${HASPMAP} ${LEXER} ${PARSER} ${VAR_EXP}
		${LIBFT} ${FT_PRINTF})
target_link_libraries(minishell readline)
target_link_libraries(minishell ncurses)
target_link_libraries(minishell termcap)
