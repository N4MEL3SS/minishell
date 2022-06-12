/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:47:35 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:47:35 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_message(char *input, char *error_message, int status)
{
	printf("%sminishell> %s%s: %s%s\n", BOLD_YELLOW, YELLOW, input, \
		error_message, RESET_COLOR);
	g_minishell.error_status = status;
}
