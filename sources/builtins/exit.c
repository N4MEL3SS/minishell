/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:45:45 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:45:45 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_string_number(char *string)
{
	while (*string)
		if (!ft_isdigit(*string++))
			return (FALSE);
	return (TRUE);
}

static void	parse_first_arg(char *arg)
{
	if (!arg)
		return ;
	g_minishell.error_status = ft_atoi(arg);
	if (is_string_number(arg))
		return ;
	error_message("exit", NUM_ARG_REQUIRED, 2);
	exit_minishell();
}

static int	get_argc(char **argv)
{
	int	argc;

	argc = 0;
	while (*(++argv))
		argc++;
	return (argc);
}

void	exit_builtin(char **argv)
{
	int	argc;

	argc = get_argc(argv);
	parse_first_arg(*(argv + 1));
	if (argc > 1)
	{
		error_message("exit", TOO_MANY_ARGS, 1);
		return ;
	}
	printf("exit\n");
	exit_minishell();
}
