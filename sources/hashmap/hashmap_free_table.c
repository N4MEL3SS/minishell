/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_free_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:48:24 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:48:24 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hashmap_free_table(t_hashmap *table)
{
	unsigned int	i;
	t_pair			*current;
	t_pair			*temp;

	i = 0;
	while (i < table->size)
	{
		current = table->pairs[i];
		while (current != NULL)
		{
			temp = current->next;
			hashmap_free_pair(current);
			current = temp;
		}
		i++;
	}
	free(table->pairs);
	free(table);
}
