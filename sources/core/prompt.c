/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:47:45 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:47:45 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*concatenate_prompt(char *pwd, char *end)
{
	char	*prompt;

	prompt = variadic_strjoin(5, ESC_BOLD_GREEN, pwd, ESC_BOLD_RED, \
		end, ESC_RESET_COLOR);
	free(pwd);
	free(end);
	return (prompt);
}

char	*create_prompt(void)
{
	char	*pwd;
	char	*end;
	char	*buffer;

	buffer = NULL;
	pwd = getcwd(buffer, 0);
	end = ft_strdup("> ");
	return (concatenate_prompt(pwd, end));
}
