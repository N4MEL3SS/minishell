/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:38:38 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:38:38 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <stdbool.h>

typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_var
{
	char	*before;
	char	*after;
	char	*value;
	char	*pointer;
}	t_var;

void	tokenizer(char **line, t_token **token_lst);
void	add_token(char *line, int start, int end, t_token **token_lst);
int		split_token(char *line, int *i, int *tkn_end, t_token **token_lst);
void	check_and_insert_spaces(char **line);
char	*insert_spaces(char **line, char *operator_pointer, char *line_init);
bool	no_blanks_around_operator(char *line, char *line_init);
void	handle_quotes(char **token_ptr, int i, int *end_quote);
void	define_end_quote(char *token, bool has_variable,
			char first_quote, int *end_quote);

bool	if_is_special_case(char *value);
void	deal_with_special_case(char **value);

bool	is_quote(char c);
bool	is_between_quotes(char *line, int i, int *match_index, char c);
void	remove_quotes(char **value, char quote);

void	define_type(t_token *previous, char *value, int *type);
bool	is_redirect(char *value);
bool	is_builtin(char *value);

void	expand_variables(char **value);
void	free_var_struct(t_var *var);
void	expand(char **variable);
void	handle_var_single_quote(t_var *var, char **value, int i);

char	*search_var(char *value, int *i);
int		get_var_size(char *var, int *index);
void	free_var_struct(t_var *var);
char	**split_in_two(const char *string, char c);

void	token_list_clear(t_token **lst);
t_token	*token_new(char *value, int type);
void	token_add_back(t_token **lst, t_token *new_token);
t_token	*token_last(t_token *lst);

#endif
