/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_print_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:48:35 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:48:35 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hashmap_print_table(t_hashmap *table)
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
			ft_putendl_fd("----------------------------", 1);
			ft_putstr("| ");
			ft_putstr(current->key);
			ft_putstr(" | = | ");
			ft_putstr(current->value);
			ft_putendl_fd(" |", 1);
			current = temp;
		}
		i++;
	}
	ft_putendl_fd("----------------------------", 1);
}
