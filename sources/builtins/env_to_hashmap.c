/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:45:39 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:45:39 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*env_find_value(char *env_line)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (env_line[i] != '=')
		i++;
	j = i;
	while (env_line[j])
		j++;
	value = ft_substr(env_line, i + 1, j);
	return (value);
}

static char	*env_find_key(char *env_line)
{
	int		i;
	char	*key;

	i = 0;
	while (env_line[i] != '=')
		i++;
	key = ft_substr(env_line, 0, i);
	return (key);
}

t_hashmap	*env_to_hashmap(char **env)
{
	t_hashmap	*table;
	int			len;
	int			i;
	char		*key;
	char		*value;

	len = 0;
	i = -1;
	while (env[len])
		len++;
	table = hashmap_create_table(len * 2);
	while (++i < len)
	{
		key = env_find_key(env[i]);
		value = env_find_value(env[i]);
		hashmap_insert(key, value, table);
		free(key);
		free(value);
	}
	return (table);
}
