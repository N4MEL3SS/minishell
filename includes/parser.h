/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:38:31 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:38:31 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "tokenizer.h"

void	parse_and_execute(t_token *token_lst);
void	command_parser(t_token *token_lst, t_token *pipe, int *old_pipe_in);
void	check_redirects(t_token *token_lst, t_token *pipe, int *save_fd);
void	here_doc_input(char *eof, int *save_fd);
char	**create_command_array(t_token *head, t_token *pipe);
void	interrupt_here_document(int signal);

#endif
