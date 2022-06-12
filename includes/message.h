/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:38:19 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:38:19 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define NOT_FOUND "command not found."
# define TOO_MANY_ARGS "too many arguments."
# define NO_OLDPWD "OLDPWD environment variable has not been set."
# define NO_HOME "HOME environment variable has not been set."
# define NO_FILE_OR_DIR "no such file or directory."
# define SYNTAX_ERROR "syntax error."
# define NUM_ARG_REQUIRED "numeric argument required."

void	error_message(char *input, char *error_message, int status);

#endif
