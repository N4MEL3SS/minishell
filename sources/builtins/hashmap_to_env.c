/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_to_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:46:08 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:46:08 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pair_to_env_entry(t_pair *pair)
{
	char	*entry;
	char	*temp;

	temp = ft_strjoin(pair->key, "=");
	entry = ft_strjoin(temp, pair->value);
	free(temp);
	return (entry);
}

char	**hashmap_to_env(t_hashmap *table)
{
	unsigned int	i;
	unsigned int	j;
	t_pair			*current;
	t_pair			*temp;
	char			**env;

	i = 0;
	j = 0;
	env = (char **)ft_calloc(sizeof (char *), table->count + 1);
	while (i < table->size && j < table->count)
	{
		current = table->pairs[i];
		while (current != NULL)
		{
			temp = current->next;
			env[j] = pair_to_env_entry(current);
			current = temp;
			j++;
		}
		i++;
	}
	return (env);
}
