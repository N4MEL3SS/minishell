/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:49:42 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:49:42 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_command_or_argument(int type)
{
	if (((type == T_LITERAL) || (type == T_BUILTIN)))
		return (TRUE);
	return (FALSE);
}

static int	get_commands_length(t_token *current, t_token *pipe)
{
	int	i;

	i = 0;
	while (current != pipe)
	{
		if (is_command_or_argument(current->type))
			i++;
		current = current->next;
	}
	return (i);
}

static char	**fill_command_array(t_token *current, t_token *end, char **cmd)
{
	int	i;

	i = 0;
	while (current != end)
	{
		if (is_command_or_argument(current->type))
		{
			cmd[i] = ft_strdup(current->value);
			i++;
		}
		current = current->next;
	}
	return (cmd);
}

char	**create_command_array(t_token *head, t_token *pipe)
{
	char	**cmd;
	int		cmd_length;

	cmd_length = get_commands_length(head, pipe);
	cmd = (char **)malloc((cmd_length + 1) * sizeof(char *));
	cmd[cmd_length] = NULL;
	cmd = fill_command_array(head, pipe, cmd);
	return (cmd);
}
