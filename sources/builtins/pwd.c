/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:46:19 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:46:19 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_current_working_directory(void)
{
	char	*buffer;

	buffer = NULL;
	return (getcwd(buffer, 0));
}

void	pwd(void)
{
	char	*cwd;

	g_minishell.error_status = 0;
	cwd = get_current_working_directory();
	if (cwd)
		printf("%s\n", cwd);
	else
		error_message("pwd", strerror(errno), 1);
	free(cwd);
}
