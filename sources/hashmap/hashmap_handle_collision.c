/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_handle_collision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:48:28 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:48:28 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hashmap_handle_collision(t_hashmap *table,
		unsigned long int index, t_pair *new_pair)
{
	t_pair	*current;

	current = table->pairs[index];
	while (current->next != NULL)
		current = current->next;
	current->next = new_pair;
	current->next->next = NULL;
	table->count += 1;
}
