/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:38:13 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:38:13 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define BLACK "\033[0;30m"
# define BOLD_BLACK "\033[1;30m"
# define RED "\033[0;31m"
# define BOLD_RED "\033[1;31m"
# define GREEN "\033[0;32m"
# define BOLD_GREEN "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BOLD_YELLOW "\033[1;33m"
# define BLUE "\033[0;34m"
# define BOLD_BLUE "\033[1;34m"
# define PURPLE "\033[0;35m"
# define BOLD_PURPLE "\033[1;35m"
# define CYAN "\033[0;36m"
# define BOLD_CYAN "\033[1;36m"
# define WHITE "\033[0;37m"
# define BOLD_WHITE "\033[1;37m"
# define RESET_COLOR "\033[0m"

# define ESC_BLACK "\001\033[0;30m"
# define ESC_BOLD_BLACK "\001\033[1;30m\002"
# define ESC_RED "\001\033[0;31m\002"
# define ESC_BOLD_RED "\001\033[1;31m\002"
# define ESC_GREEN "\001\033[0;32m\002"
# define ESC_BOLD_GREEN "\001\033[1;32m\002"
# define ESC_YELLOW "\001\033[0;33m\002"
# define ESC_BOLD_YELLOW "\001\033[1;33m\002"
# define ESC_BLUE "\001\033[0;34m\002"
# define ESC_BOLD_BLUE "\001\033[1;34m\002"
# define ESC_PURPLE "\001\033[0;35m\002"
# define ESC_BOLD_PURPLE "\001\033[1;35m\002"
# define ESC_CYAN "\001\033[0;36m\002"
# define ESC_BOLD_CYAN "\001\033[1;36m\002"
# define ESC_WHITE "\001\033[0;37m\002"
# define ESC_BOLD_WHITE "\001\033[1;37m\002"
# define ESC_RESET_COLOR "\001\033[0m\002"

char	*create_prompt(void);
void	define_input_signals(void);
void	define_exec_signals(void);

#endif
