/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:38:24 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:38:24 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/stat.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"
# include "input.h"
# include "tokenizer.h"
# include "parser.h"
# include "message.h"
# include "builtin.h"

# define IN		0
# define OUT	1

# define T_BUILTIN		42
# define T_LITERAL		43
# define T_PIPE			44
# define T_REDIRECT		45
# define T_FILE			47

# define SINGLE_QUOTE	'\''
# define DOUBLE_QUOTE	'\"'

typedef struct s_pair
{
	char			*key;
	char			*value;
	struct s_pair	*next;
}			t_pair;

typedef struct s_hashmap
{
	t_pair			**pairs;
	unsigned int	count;
	unsigned int	size;
}			t_hashmap;

typedef struct s_minishell
{
	t_hashmap	*env;
	t_hashmap	*local_vars;
	int			error_status;
}				t_minishell;

t_minishell	g_minishell;

void				print_2d_array_fd(char **array, int fd);
void				free_2d_array(char **ptr);
char				*get_absolute_path(char *cmd, char *path_variable);
void				execute(char **cmd);
void				env_dup(char **env);

t_hashmap			*env_to_hashmap(char **env);
char				**hashmap_to_env(t_hashmap *table);
char				**hashmap_to_env_with_quotes(t_hashmap *table);
void				print_environment(t_hashmap *env, int fd);

t_pair				*hashmap_create_pair(char *key, char *value);
t_hashmap			*hashmap_create_table(u_int32_t size);
void				hashmap_free_pair(t_pair *pair);
void				hashmap_free_table(t_hashmap *table);
void				hashmap_insert(char *key, char *value, t_hashmap *table);
char				*hashmap_search(t_hashmap *table, char *key);
void				hashmap_handle_collision(t_hashmap *table,
		unsigned long int index, t_pair *new_pair);
void				hashmap_delete(t_hashmap *table, char *key);
unsigned long int	hash(char *key, unsigned int size);

#endif
