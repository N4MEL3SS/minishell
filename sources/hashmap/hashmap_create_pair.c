/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_create_pair.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:48:06 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:48:06 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pair	*hashmap_create_pair(char *key, char *value)
{
	t_pair	*new_pair;

	new_pair = (t_pair *)ft_calloc(sizeof(t_pair), 1);
	new_pair->key = ft_strdup(key);
	new_pair->value = ft_strdup(value);
	return (new_pair);
}
