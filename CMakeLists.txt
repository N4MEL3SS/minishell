cmake_minimum_required(VERSION 3.21)
project(minishell C)

#add_compile_options(-Wall -Wextra -Werror)

set(CMAKE_C_STANDARD 99)
include_directories(includes/)

set(HEAD includes/minishell.h)

set(SRC source/core/main.c
		source/core/utils.c)

add_executable(minishell ${HEAD} ${SRC})
target_link_libraries(minishell readline)
