/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_to_env_with_quotes.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:46:12 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:46:12 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*pair_to_env_entry_with_quotes(t_pair *pair)
{
	char	*entry;
	char	*temp;
	char	*aux;
	char	*value_with_quotes;

	if (pair->value[0])
	{
		temp = ft_strjoin(pair->key, "=");
		aux = ft_strjoin("\"", pair->value);
		value_with_quotes = ft_strjoin(aux, "\"");
		entry = ft_strjoin(temp, value_with_quotes);
		free(temp);
		free(aux);
		free(value_with_quotes);
	}
	else
		entry = ft_strdup(pair->key);
	return (entry);
}

char	**hashmap_to_env_with_quotes(t_hashmap *table)
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
			env[j] = pair_to_env_entry_with_quotes(current);
			current = temp;
			j++;
		}
		i++;
	}
	return (env);
}
