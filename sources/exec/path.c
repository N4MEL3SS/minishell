/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:47:58 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:47:58 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_possible_path(char *envpath, char *cmd)
{
	char	*path;

	if (ft_strncmp(envpath, cmd, ft_strlen(envpath)) == 0)
		path = ft_strdup(cmd);
	else
		path = (variadic_strjoin(3, envpath, "/", cmd));
	return (path);
}

static bool	is_executable(char *cmd_path)
{
	struct stat	buffer;

	if (stat(cmd_path, &buffer) != 0)
		return (FALSE);
	if ((buffer.st_mode & S_IFMT) == S_IFDIR)
		return (FALSE);
	if ((buffer.st_mode & S_IXUSR))
		return (TRUE);
	return (FALSE);
}

char	*get_absolute_path(char *cmd, char *path_variable)
{
	char		**all_paths;
	char		*cmd_path;
	int			i;

	i = 0;
	all_paths = ft_split(path_variable, ':');
	while (all_paths && all_paths[i])
	{
		cmd_path = get_possible_path(all_paths[i], cmd);
		if (is_executable(cmd_path))
			break ;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	free_2d_array(all_paths);
	return (cmd_path);
}
