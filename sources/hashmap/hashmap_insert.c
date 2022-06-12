/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:48:32 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:48:32 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hashmap_insert(char *key, char *value, t_hashmap *table)
{
	unsigned long int	index;
	t_pair				*new_pair;
	t_pair				*current;

	index = hash(key, table->size);
	new_pair = hashmap_create_pair(key, value);
	current = table->pairs[index];
	if (current == NULL)
	{
		table->pairs[index] = new_pair;
		table->count += 1;
	}
	else
	{
		if (ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			hashmap_free_pair(new_pair);
		}
		else
			hashmap_handle_collision(table, index, new_pair);
	}
}
