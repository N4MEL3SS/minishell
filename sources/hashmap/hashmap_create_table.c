/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_create_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:48:12 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:48:12 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_hashmap	*hashmap_create_table(u_int32_t size)
{
	t_hashmap	*new_table;
	u_int32_t	i;

	i = 0;
	new_table = (t_hashmap *)ft_calloc(sizeof(t_hashmap), 1);
	new_table->size = size;
	new_table->count = 0;
	new_table->pairs = (t_pair **)ft_calloc(sizeof(t_hashmap), size);
	while (i < size)
		new_table->pairs[i++] = NULL;
	return (new_table);
}
