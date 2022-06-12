/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:46:30 by null              #+#    #+#             */
/*   Updated: 2022/06/12 03:46:30 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(char **cmd)
{
	int	i;

	i = 1;
	g_minishell.error_status = 0;
	while (cmd[i])
	{
		if (hashmap_search(g_minishell.env, cmd[i]))
			hashmap_delete(g_minishell.env, cmd[i]);
		else if (hashmap_search(g_minishell.local_vars, cmd[i]))
			hashmap_delete(g_minishell.local_vars, cmd[i]);
		i++;
	}
}
